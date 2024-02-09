// Doubly circular linked list
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev; 
};

template <class T>
class DoublyCL
{
    private:            
        struct node<T> * First;
        struct node<T> * Last;
        int Count;

    public:

        DoublyCL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);
        void DeleteAtPos(int iPos);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int CountNode();
};

    template <class T>
    DoublyCL<T> :: DoublyCL()
    {
        First = NULL;
        Last = NULL;
        Count = 0;
    }

    template <class T>
    void DoublyCL<T> :: InsertFirst(T No)
    {
       struct node<T> * newn = NULL;
       newn = new struct node<T>;

       newn->data = No;
       newn->next = NULL;
       newn->prev = NULL;

       if((First == NULL) && (Last == NULL))
       {
            First = newn;
            Last = newn;
       }
       else
       {
            newn->next = First;
            First->prev = newn;
            First = newn;
       }
       First->prev = Last;
       Last->next = First;
       Count++;
    }

    template <class T>
    void DoublyCL<T> :: InsertLast(T No)
    {
        struct node<T> * newn = NULL;
        newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        if((First == NULL) && (Last == NULL))
        {
            First = newn;
            Last = newn;
        }
        else
        {
            Last->next = newn;
            newn->prev = Last;
            Last = newn;
        }
        First->prev = Last;
        Last->next = First;
        Count++;
    }

    template <class T>
    void DoublyCL<T> :: InsertAtPos(T No,int iPos)
    {
        struct node<T> * newn = NULL;

        if((iPos < 1) || (iPos > Count+1))
        {
            cout<<"Invalid Position \n";
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(No);
        }
        else if(iPos == Count+1)
        {
            InsertLast(No);
        }
        else
        {
            int i = 0;
            struct node<T> * temp = First;

            newn = new struct node<T>;

            newn->data = No;
            newn->next = NULL;
            newn->prev = NULL;

            for(i=1; i < iPos-1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
        }
        Count++;
    }

    template <class T>
    void DoublyCL<T> :: DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > Count+1))
        {
            cout<<"Invalid Position \n";
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == Count+1)
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            struct node<T> * temp = First;
            
            for(i=1; i < iPos-1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
        }
        Count--;
    }

    template <class T>
    void DoublyCL<T> :: DeleteFirst()
    {
        if((First == NULL) && (Last == NULL))
        {
            return;
        }
        else if(First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            First = First->next;
            delete Last->next;
            First->prev = Last;
            Last ->next = First;
        }
        Count--;
    }

    template <class T>
    void DoublyCL<T> :: DeleteLast()
    {
        if((First == NULL) && (Last == NULL))
        {
            return;
        }
        else if(First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            Last = Last->prev;
            delete First->prev;
            First->prev = Last;
            Last->next = First;
        }
        Count--;
    }

    template <class T>
    void DoublyCL<T> :: Display()
    {
        cout<<"\nElements of the linked list are : \n";

        if((First != NULL) && (Last != NULL))
        {
            do
            {
                cout<<"| "<<First->data<<" |<=>";
                First = First->next;
            }while(First != Last->next);
            cout<<"\n";
        }
    }

    template <class T>
    int DoublyCL<T> :: CountNode()
    {
        return Count;
    }

int main()
{

    cout<<"\n------------------------------------\n";
    cout<<"Doubly Circular Linked List \n";
    cout<<"------------------------------------\n";

    DoublyCL <int> iobj;
    DoublyCL <float> fobj;
    DoublyCL <double> dobj;
    DoublyCL <char> cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);

    cout<<"\nLinked list of integer is : ";
    iobj.Display();
    cout<<"\n";

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"\nLinked list of float is : ";
    fobj.Display();
    cout<<"\n";

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.999);

    cout<<"\nLinked list of double is : ";
    dobj.Display();
    cout<<"\n";

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"\nLinked list of character is : ";
    cobj.Display();
    cout<<"\n";

    return 0;
}