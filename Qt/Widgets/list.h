#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include <QDebug>

template <typename T, std::size_t N>
class List
{
public:
    List(const T (&array)[N]);
    ~List();
    void print();
private:
    struct Node {Node* next = nullptr;
                Node* prev = nullptr;
                T data;};
    Node* first = nullptr;
    Node* last = nullptr;
};

template <typename T, std::size_t N>
List<T,N>::List(const T (&array)[N])
{
    try
    {
        first=last= new Node();
        first->data = array[0];
        for ( size_t i = 1; i<N; i++ )
        {
            Node* temp = new Node();
            last->next = temp;
            temp->prev = last;
            temp->data = array[i];
            last = temp;
        }
    }
    catch (const std::bad_alloc&)
    {
        qDebug()<<"Too sad :(, There is not enouth memory for List object!";
    }
}

template <typename T, std::size_t N>
void List<T,N>::print()
{
    for (Node* i = first; i!=nullptr ; i = i->next)
    {
        qDebug ()<<i->data;
    }
}

template <typename T, std::size_t N>
List<T,N>::~List()
{
    for (Node* i = first; i!=nullptr ; i = first )
    {
        first = i->next;
        delete i;
    }
}


#endif // LIST_H
