#ifndef MA_USER_H
#define MA_USER_H
#include "basePluginDocument.h"


class maUser: public BasePluginDocument
{
    Q_OBJECT
    Q_INTERFACES(BasePluginInterface)
    Q_PLUGIN_METADATA (IID "ru.kazan.icl.VisiData.BasePluginInterface")
    
    QAction* MenuItem;
    QMenu* PopUpMenuIns;
    QString q;
    QString GrandScript_ORACLE;
    QString GrandScript_POSTGRE;

public:
    maUser();
    ~maUser();
    int copyTreeNodeRecursive(int, int, int);
    bool copyTree(int, int);
    int eventUserDefined(QString actionParams);
    int eventOnJournRButtonDown();
    int eventAfterSaveBeforeCommit();
private slots:
    void setGrandClick();
};

#endif // MA_USER_H
