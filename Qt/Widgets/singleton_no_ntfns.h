#ifndef SINGLETON_NO_NTFNS_H
#define SINGLETON_NO_NTFNS_H
#include <QLabel>

class Singleton_no_ntfns : public QLabel
{
    Singleton_no_ntfns(const QString text, QWidget *parent = nullptr);
    static Singleton_no_ntfns * _instance;
public:
    void free_instance();
    static bool is_exist();
    static Singleton_no_ntfns* instance();
    void add_no_ntfns_label();
    void delete_no_ntfns_label();
    ~Singleton_no_ntfns();
};

#endif // SINGLETON_NO_NTFNS_H
