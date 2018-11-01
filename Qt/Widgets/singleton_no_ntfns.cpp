#include "singleton_no_ntfns.h"

Singleton_no_ntfns::Singleton_no_ntfns(const QString text, QWidget* parent) :
    QLabel(text,parent)
{
    this->setStyleSheet(QString("font-size: 42px;color: grey"));
    this->setAlignment(Qt::AlignCenter);
}

void Singleton_no_ntfns::free_instance()
{
    delete this;
//    _instance = nullptr;
}

bool Singleton_no_ntfns::is_exist()
{
    return _instance;
}
Singleton_no_ntfns* Singleton_no_ntfns::_instance = nullptr;

Singleton_no_ntfns *Singleton_no_ntfns::instance()
{
    if (!_instance)
        _instance = new Singleton_no_ntfns(QString("Для Вас нет новых оповещений"));
    return _instance;
}

Singleton_no_ntfns::~Singleton_no_ntfns()
{
//    delete _instance;
    _instance = nullptr;
}
