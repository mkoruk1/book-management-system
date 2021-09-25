#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <fstream>

using namespace std;

class Node //Book
{
public:
    string isbn;
    string name;
    string author;
    unsigned int pubYear;
    string status;
    Node* next;
};

#endif // BOOK_H_INCLUDED
