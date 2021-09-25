#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "book.h"

class LinkedList
{
private:
    Node* head;
public:
    unsigned int bookCounter=0;
    LinkedList(){head=NULL;}
    ~LinkedList();
    void printList();
    void loadFromDatabase();
    void saveToFile(Node*);
    void saveToFileAll();
    void deleteFromFile(Node* );
    void insertBook(Node*);
    void deleteBookFromList(Node*);
    void bookMenu();
    void loginScren();
};

#endif // LINKEDLIST_H_INCLUDED
