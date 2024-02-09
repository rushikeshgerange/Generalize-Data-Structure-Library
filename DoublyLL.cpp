// Doubly linear linked list
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
class DoublyLL
{
    private:            
        struct node<T> * First;
        int Count;

    public:

        DoublyLL();
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
    DoublyLL<T> :: DoublyLL()
    {
        First = NULL;
        Count = 0;
    }

    template <class T>
    void DoublyLL<T> :: InsertFirst(T No)
    {
        struct node<T> * newn = NULL;
        newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        if(First == NULL)
        {
            First = newn;
        }
        else
        {
            newn->next = First;
            First->prev = newn;
            First = newn;
        }
        Count++;
    }

    template <class T>
    void DoublyLL<T> :: InsertLast(T No)
    {
        struct node<T> * newn = NULL;
        newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        if(First == NULL)
        {
            First = newn;
        }
        else
        {
            struct node<T> * temp = First;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newn->prev = temp;
            temp->next = newn;  
        }
        Count++;
    }

    template <class T>
    void DoublyLL<T> :: InsertAtPos(T No,int iPos)
    {
        struct node<T> * newn = NULL;

        if((iPos < 1 ) || (iPos > Count+1))
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
    void DoublyLL<T> :: DeleteAtPos(int iPos)
    {
        if((iPos < 1 ) || (iPos > Count+1))
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
            struct node<T> * temp = First;
            int i = 0;

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
    void DoublyLL<T> :: DeleteFirst()
    {
       if(First == NULL)
       {
            return;
       }
       else if(First->next == NULL)
       {
            delete First;
            First = NULL;
       }
       else
       {
            First = First->next;
            delete First->prev;
            First->prev = NULL;
       }
       Count--;
    }

    template <class T>
    void DoublyLL<T> :: DeleteLast()
    {
        if(First == NULL)
        {
            return;
        }
        else if(First->next == NULL)
        {
            delete First;
            First = NULL;
        }
        else
        {
            struct node<T> * temp = First;

            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        Count--;
    }

    template <class T>
    void DoublyLL<T> :: Display()
    {
       struct node<T> * temp = First;
       cout<<"\nElements of the linked list are : \n";
       cout<<"NULL <=>";

       while(temp != NULL)
       {
            cout<<"| "<<temp->data<<" |<=>";
            temp = temp->next;
       }
       cout<<"NULL \n";
    }

    template <class T>
    int DoublyLL<T> :: CountNode()
    {
        return Count;
    }

int main()
{
    int iRet = 0;

    cout<<"\n------------------------------------\n";
    cout<<"Doubly Linear Linked List \n";
    cout<<"------------------------------------\n";

    DoublyLL <int> iobj;
    DoublyLL <float> fobj;
    DoublyLL <double> dobj;
    DoublyLL <char> cobj;

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