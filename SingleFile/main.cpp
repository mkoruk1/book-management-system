#include <iostream>
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

void LinkedList::printList()
{
    cout<<"---BOOK LIST---"<<endl<<endl;
    cout<<endl<<"TOTAL BOOK:"<<bookCounter<<endl<<endl;
    if(head==NULL)
    {
        cout<<endl<<"LIST IS EMPTY.";
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<"\nISBN:"<<temp->isbn<<endl;
            cout<<"\nNAME:"<<temp->name<<endl;
            cout<<"\nAUTHOR:"<<temp->author<<endl;
            cout<<"\nPUB YEAR:"<<temp->pubYear<<endl;
            cout<<"\nSTATUS:"<<temp->status<<endl<<endl;;
            cout<<"------------------"<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
}

void LinkedList::loadFromDatabase()
{
    Node obj;
    ifstream file("Database.txt",ios::in);
    while(true)
    {
    file>>obj.isbn>>obj.name>>obj.author>>obj.pubYear>>obj.status;
    if (!file){break;}
    insertBook(&obj);
    }
    cout<<endl<<"SUCCESFULLY LOADED FROM DATABASE.";
    file.close();
}

void LinkedList::saveToFile(Node* book)
{
        ofstream file("Database.txt",ios::app);
        if(file.is_open())
        {
            file<<book->isbn<<endl;
            file<<book->name<<endl;
            file<<book->author<<endl;
            file<<book->pubYear<<endl;
            file<<book->status<<endl;
        }
        file.close();
}

void LinkedList:: saveToFileAll()
{
        ofstream file("Database.txt");
        Node *temp=head;
        if(file.is_open())
        {
            while(temp!=NULL)
            {
            file<<temp->isbn<<endl;
            file<<temp->name<<endl;
            file<<temp->author<<endl;
            file<<temp->pubYear<<endl;
            file<<temp->status<<endl;
            temp=temp->next;
            }

        }
            file.close();

}

void LinkedList::insertBook(Node *book)
{
    Node* newNode=new Node();
    Node* temp;
    newNode->isbn=book->isbn;
    newNode->name=book->name;
    newNode->author=book->author;
    newNode->pubYear=book->pubYear;
    newNode->status=book->status;
    newNode->next=NULL;
    bookCounter++;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void LinkedList::deleteBookFromList(Node* book)
{
    int counter=0;
    Node* hold=head;
    while(hold!=NULL)
    {
        if(hold->name==book->name)
        {
             break;
        }
        hold=hold->next;
        if(hold==NULL)
        {
            cout<<endl<<"BOOK IS NOT IN THE LIST."<<endl;
        }
    }
    Node* temp;
    Node* temp1;
    temp=head;
    if(head==NULL)
    {
        cout<<"\nLIST IS EMPTY."<<endl;
        Sleep(2000);
    }
    else if(head->name==book->name)
    {
        cout<<endl<<"FOUND IN FIRST NODE."<<endl;
        Sleep(2000);
        head=head->next;
        delete temp;
    }
    else
    {
        while((temp->next->name)!=(book->name))
        {
            temp=temp->next;
            counter=counter+1;
        }
        if(temp->next->name==book->name)
        {
            cout<<endl<<"FOUND IN NODE ["<<counter+2<<"]";
            Sleep(2000);
            temp1=temp->next;
            temp->next=temp1->next;
            delete temp1;
        }
        else
        {
            cout<<"BOOK IS NOT FOUND."<<endl;
            Sleep(2000);
        }
    }

}

void LinkedList::bookMenu()
{
    Node book;
    short int value;
    char returnC;
    while(1)
    {
        system("cls");
        cout<<endl<<"MAIN MENU";
        cout<<endl<<"============================="<<endl;
        cout<<endl<<"01.INSERT BOOK\n"<<endl<<"02.DISPLAY THE BOOKLIST\n"<<endl<<"03.DELETE BOOK\n"<<endl<<"04.LOAD FROM DATABASE\n"<<endl<<"05.EXIT\n"<<endl;
        cout<<endl<<"============================="<<endl;
        cout<<"\nSelect Your Option: ";
        cin>>value;
        switch(value)
        {
        case 1:
            system("cls");
            cout<<"----- ADD BOOK TO THE SYSTEM -----\n "<<endl;
            cout<<endl<<"ISBN:";
            cin>>book.isbn;
            cin.get();
            cout<<endl<<"NAME OF THE BOOK:";
            getline(cin,book.name);
            cout<<endl<<"AUTHOR:";
            getline(cin,book.author);
            cout<<endl<<"PUBLISH YEAR:";
            cin>>book.pubYear;
            if(book.pubYear<1985)
            {
                book.status="REFERENCE";
                cout<<endl;
            }
            else
            {
                book.status="AVAIBLE";
                cout<<endl;
            }
            insertBook(&book);
            saveToFile(&book);
            cout<<"SUCCESFULLY SAVED TO DATABASE."<<endl;
            Sleep(2000);
            break;
        case 2:
            system("cls");
            printList();
            cout<<"\n\n\n\nPress Enter to return..."<<endl;
            returnC=getch();
            break;
        case 3:
            system("cls");
            cout<<"----- DELETE BOOK FROM THE SYSTEM -----\n"<<endl;
            cout<<endl<<"NAME OF THE BOOK TO REMOVE: ";
            cin>>book.name;
            deleteBookFromList(&book);
            bookCounter--;
            saveToFileAll();
            break;
        case 4:
            system("cls");
            loadFromDatabase();
            Sleep(2000);
            break;
        case 5:
            exit(0);

        default:
            cout<<endl<<"Invalid value!";
            Sleep(1000);
        }
    }
}
void LinkedList::loginScren()
{
    char test;
    cout<<"==========================================";
    cout<<"\n\n\n\t\t  BOOK";
	cout<<"\n\n\t\tMANAGEMENT";
	cout<<"\n\n\t\t SYSTEM";
	cout<<"\n\n\n=========================================="<<endl;
	cout<<"\n\n\nMADE BY : MUSTAFA KORUK"<<endl;
	cout<<"\nPress Enter to continue..."<<endl;
	test=getch();
	system("cls");
}

LinkedList::~LinkedList()
{

}

int main()
{
   LinkedList book;
   book.loginScren();
   book.bookMenu();

   return 0;
}

