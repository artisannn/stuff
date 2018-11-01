#include "ma_user.h"



int maUser::copyTreeNodeRecursive(int pkID,int newParentID,int userid_trg)
// копирование элемента дерева и всех подчиненных элементов
{
    bool pr;
    int newID,newNumber,errcode;
    QXDataQuery *query;

    errcode=0;
    query=DbConnection::instance()->getDataQuery();
    // обработка записи
    // получить ид новой записи
    if (errcode==0)
        newID=DbConnection::instance()->call_ALLOCATEID("CATOBJECTS");
    // получить порядковый номер для добавляемой записи
    if (errcode==0)
    {
        newNumber=0;
        query->prepare("SELECT coalesce(max(number_),0)+1 as newNumber FROM CATOBJECTS WHERE user_id_= :userID and coalesce(parnode_,0)=:parNode");
        query->bindValue(":userID",userid_trg);
        query->bindValue(":parNode",newParentID);
        pr=query->exec();
        if (pr)
        {
            query->first();
            newNumber=query->value("newNumber").toInt();
        }
        else
            errcode=query->lastError().number();
    }
    // создать новую запись
    if (errcode==0)
    {
        if (newParentID==0)
        {
            query->prepare("INSERT INTO CATOBJECTS (NODE_, PARNODE_, NUMBER_, OBJECT_, IDOBJECT_, IMAGE_, OPENIMAGE_, NAME_, TITLE_, ALIAS_, SQL_, USER_ID_) \
                           SELECT :pNewNode, NULL, :pNewNumber, OBJECT_, IDOBJECT_, IMAGE_, OPENIMAGE_, NAME_, TITLE_, ALIAS_, SQL_, :UserID \
                           FROM CATOBJECTS \
                           WHERE NODE_ = :pNode");
            query->bindValue(":pNewNode",newID);
            query->bindValue(":pNewNumber",newNumber);
            query->bindValue(":UserID",userid_trg);
            query->bindValue(":pNode",pkID);
            pr=query->exec();
        }
        else
        {
            query->prepare("INSERT INTO CATOBJECTS (NODE_, PARNODE_, NUMBER_, OBJECT_, IDOBJECT_, IMAGE_, OPENIMAGE_, NAME_, TITLE_, ALIAS_, SQL_, USER_ID_) \
                           SELECT :pNewNode, :pNewParNode, :pNewNumber, OBJECT_, IDOBJECT_, IMAGE_, OPENIMAGE_, NAME_, TITLE_, ALIAS_, SQL_, :UserID \
                           FROM CATOBJECTS \
                           WHERE NODE_ = :pNode");
            query->bindValue(":pNewNode",newID);
            query->bindValue(":pNewParNode",newParentID);
            query->bindValue(":pNewNumber",newNumber);
            query->bindValue(":UserID",userid_trg);
            query->bindValue(":pNode",pkID);
            pr=query->exec();
        }
    }
    if (!pr)
        errcode=query->lastError().number();
    // скопировать подчиненные записи
    if (errcode==0)
    {
        query->prepare("SELECT NODE_ FROM CATOBJECTS WHERE PARNODE_=:ID ORDER BY NUMBER_");
        query->bindValue(":ID",pkID);
        pr=query->exec();
        if (pr)
        {
            pr=query->first();
            while (pr && (errcode==0))
            {
                errcode=copyTreeNodeRecursive(query->value("NODE_").toInt(),newID,userid_trg);
                pr=query->next();
            }
        }
        else
            errcode=query->lastError().number();
    }
    //
    DbConnection::instance()->freeDataQuery(query);
    return errcode;
}


bool maUser::copyTree(int userid_src,int userid_trg)
// копирование всего дерева от одного пользователя к другому
{
    QXDataQuery *query;
    QString str;
    bool pr;
    int err;
    // если userid_src = userid_trg - копирование запрещено
    if (userid_src==userid_trg)
    {
        QMessageBox::warning(0,"Копирование","Выберите разных пользователей",QMessageBox::Ok);
        return false;
    }
    str="";
    query=DbConnection::instance()->getDataQuery();
    // проверки:
    // - если нет элементов в дереве для userid_src - копирование запрещено
    // - если есть элементы в дереве для userid_trg - копирование запрещено
    err=0;
    query->prepare("SELECT COUNT(*) as CNT FROM CATOBJECTS WHERE USER_ID_ = :ID");
    query->bindValue(":ID",userid_src);
    pr=query->exec();
    if (pr)
    {
        query->first();
        if (query->value("CNT").toInt()==0)
        {
            err=-1;
            str=str+"Не заполнено дерево-источник\n";
        }
    }
    else
    {
        err=-1;
        str=str+"Ошибка проверки источника\n";
    }
    query->bindValue(":ID",userid_trg);
    pr=query->exec();
    if (pr)
    {
        query->first();
        if (query->value("CNT").toInt()!=0)
        {
            err=-1;
            str=str+"Дерево-приемник должно быть пустым\n";
        }
    }
    else
    {
        err=-1;
        str=str+"Ошибка проверки приемника\n";
    }
    if (err!=0)
    {
        QMessageBox::warning(0,"Копирование",str,QMessageBox::Ok);
        DbConnection::instance()->freeDataQuery(query);
        return false;
    }
    // копирование
    err=0;
    DbConnection::instance()->transaction();
    query->prepare("select NODE_ from CATOBJECTS where user_id_=:ID and parnode_ is null");
    query->bindValue(":ID",userid_src);
    pr=query->exec();
    if (pr)
    {
        pr=query->first();
        while (pr && (err==0))
        {
            err=copyTreeNodeRecursive(query->value("NODE_").toInt(),0,userid_trg);
            pr=query->next();
        }
    }
    if (err==0)
    {
        DbConnection::instance()->commit();
        QMessageBox::information(0,"Копирование","Дерево скопировано",QMessageBox::Ok);
    }
    else
    {
        DbConnection::instance()->rollback();
        QMessageBox::warning(0,"Копирование","Ошибка копирования дерева\n"+QString::number(err),QMessageBox::Ok);
    }
    DbConnection::instance()->freeDataQuery(query);
    return !err;
}


// Раздача прав по нажатию правой кнопкой мыши по полю журнала
int maUser::eventOnJournRButtonDown()
{
    PopUpMenuIns = new QMenu(document->getListForm()->getTableView());
    MenuItem = new QAction("Задать права",PopUpMenuIns);
    PopUpMenuIns->addAction(MenuItem);
    PopUpMenuIns->popup(QCursor::pos());
    connect(PopUpMenuIns, SIGNAL(triggered(QAction*)), this , SLOT(setGrandClick()));
    return 0;
}


void maUser::setGrandClick() // Вызываемый метод по правой кнопке мыши
{
    bool done;
    QXDataQuery* script = connection->getDataQuery();
    QString user_name;
    bool iSsuccess = false;
    bool iSfail = false;
    QString fail_message = QString("Не заданы права для следующих пользователей:\n\t");
    QString success_message = QString("Права для следующих пользователей заданы успешно:\n\t");
    auto selectedRowsList = document->getListForm()->getSelectedRows();

    for (auto currentRowIndex: selectedRowsList)
    {
        // Текущая выделенная запись
        QSqlRecord recordOfJournal = document->getListDataModel()->record(currentRowIndex);

        // Вытаскиваем значение имени пользователя из recordJournal в формате QString
        user_name = recordOfJournal.value("mausr_name").toString().toUpper();

        if (recordOfJournal.value("mausr_name").isNull())
        {
            QMessageBox::information(0,document->getMdDoc()->getDocName(),"Задан пользователь с пустым именем");
            break;
        }

        if (tuning->getDbType() == DbType::dbtOracle)
        {
            script->prepare(GrandScript_ORACLE);
            script->bindValue(0,QVariant(user_name));
        }
        else if (tuning->getDbType() == DbType::dbtPostgre)
        {
            script->prepare(GrandScript_POSTGRE);
            script->bindValue(":u_name",user_name);
        }
        done = script->exec();

        // Формируем сообщения, уведомляющие о том, кому права задались, а кому нет
        if (done)
        {
            iSsuccess = true;
            success_message += QString("• %1\n\t").arg(user_name);
        }
        else
        {
            iSfail = true;
            fail_message += QString("• %1\n\t").arg(user_name);
        }
    }
    if (iSsuccess && !iSfail)   // Если права были розданы всем, то выводим только success_message
    {
        QMessageBox::information(0,document->getMdDoc()->getDocName(),
                                         success_message);
    }
    if (iSsuccess && iSfail)    // Если если кому-то НЕ раздались права, от выводим оба сообщения
    {
        QMessageBox::warning(0,document->getMdDoc()->getDocName(),
                                         fail_message);
        QMessageBox::information(0,document->getMdDoc()->getDocName(),
                                         success_message);
    }
    if (!iSsuccess && iSfail)   // Если никому не розданы права, то выводим только fail_message
    {
        QMessageBox::warning(0,document->getMdDoc()->getDocName(),
                                         fail_message);
    }
    connection->freeDataQuery(script);
}

    // По нажатию кнопки "Задать права" раздать права
int maUser::eventUserDefined(QString actionParams)
{
    QXDataQuery* script = connection->getDataQuery();
    if (actionParams == "SETGRAND")
    {
        QString Message;
        bool done = false;
        QSqlRecord record = getRecord0();
        QString user_name = record.value("mausr_name").toString().toUpper();

        if (record.value("mausr_name").isNull())
        {
            QMessageBox::warning(0,document->getMdDoc()->getDocName(),"Задайте прежде имя пользователя!");
            return -1;
        }
        if (tuning->getDbType() == DbType::dbtOracle)
        {
            script->prepare(GrandScript_ORACLE);
            script->bindValue("u_name",user_name);
        }
        else if (tuning->getDbType() == DbType::dbtPostgre)
        {
            script->prepare(GrandScript_POSTGRE);
            script->bindValue("u_name",user_name);
        }
        done = script->exec();
        Message = QString("Для пользователя %1 права%2заданы").arg(user_name).arg((done ? " " :" не "));

        QMessageBox::information(0,document->getMdDoc()->getDocName(),Message);
        connection->freeDataQuery(script);
    }
    return 0;
}


int maUser::eventAfterSaveBeforeCommit()
{
    qDebug() << "eventAfterSaveBeforeCommit()" << endl;
    QXSqlEditableModel* Mymodel0 = getModel0();
    int result=BasePluginDocument::eventAfterSaveBeforeCommit();
    QString role_id;
    QSqlRecord q0 = getRecord0();
    QXDataQuery* q;

    if (result!=0)
    {
        qDebug() << result << endl; return result;
    }
    if (!q0.value("mausr_role_id").isNull())//if not q0.FieldByName('mausr_role_id').IsNull then
    {
        qDebug() << "!q0.value(mausr_role_id).isNull()--> true" << endl;
        if ((Mymodel0->getStatusRow(0) == QXSqlEditableModel::Insert) ||
            ((Mymodel0->getStatusRow(0) == QXSqlEditableModel::Update && 1)) // Валью всегда не равно нью валью
                    /*q0.fieldName("mausr_role_id").OldValue!=q0.fieldName("mausr_role_id").Value*/ )
        {
            qDebug() <<  (Mymodel0->getStatusRow(0) == QXSqlEditableModel::Insert ? "Insert--> true" : "Insert-->false")<< endl;
            qDebug() <<  (Mymodel0->getStatusRow(0) == QXSqlEditableModel::Update? "Update--> true" : "Update-->false")<< endl;
            role_id = q0.value("mausr_role_id").toString();
            q = connection->getDataQuery();
            q->prepare("SELECT COUNT (*) FROM CATOBJECTS WHERE USER_ID_ = " + role_id);
            qDebug() << "q->exec()-->SELECT COUNT (*) FROM CATOBJECTS WHERE USER_ID_ = "+ role_id << endl;
            bool exec = q->exec();
            qDebug() << (exec ? "exec() --> true" : "exec() --> false") ;
            q->first();
            if (q->value(0).toInt() > 0)
            {
                if  (QMessageBox::question(0,document->getMdDoc()->getDocName(),
                                           "Скопировать дерево роли пользователю ?",
                                           QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                           QMessageBox::Yes)==QMessageBox::Yes)
                {
                        q->prepare("DELETE FROM CATOBJECTS WHERE USER_ID_ = " + q0.value("mausr_user_id").toString());
                    qDebug() << (q->exec() ?  "DELETE FROM CATOBJECTS WHERE USER_ID_ = " + q0.value("mausr_user_id").toString() +"-->true" :
                                              "DELETE FROM CATOBJECTS WHERE USER_ID_ = " + q0.value("mausr_user_id").toString() +"-->false")<< endl;
                    if (copyTree(role_id.toInt(),q0.value("mausr_user_id").toInt()))
                        QMessageBox::information(0,document->getMdDoc()->getDocName(),"Копирование дерева завершено");
                }
                connection->freeDataQuery(q);
            }
        }
    }
    return result;
}


maUser::~maUser()
{
}

maUser::maUser()
{
    GrandScript_ORACLE = "BEGIN U_GRANT_ROLE_PRIVS(:u_name); COMMIT; END;";
    GrandScript_POSTGRE = "";
}

