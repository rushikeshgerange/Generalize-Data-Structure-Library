// Singly Circular linked list
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class SinglyCL 
{
    private:            
        struct node<T> * First;
        struct node<T> * Last;
        int Count;

    public:

        SinglyCL();
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
    SinglyCL<T> :: SinglyCL()
    {
        First = NULL;
        Last = NULL;
        Count = 0;
    }

    template <class T>
    void SinglyCL<T> :: InsertFirst(T No)
    {
       struct node<T> * newn = NULL;
       newn = new struct node<T>;
       
       newn->data = No;
       newn->next = NULL;

       if((First == NULL) || (Last == NULL))
       {
            First = newn;
            Last = newn;
       }
       else
       {
            newn->next = First;
            First = newn;
            Last->next = First;
       }
       Count++;
    }

    template <class T>
    void SinglyCL<T> :: InsertLast(T No)
    {
        struct node<T> * newn = NULL;
        newn = new struct node<T> ;

        newn->data = No;
        newn->next = NULL;

        if((First == NULL) && (Last == NULL))
        {
            First = newn;
            Last = newn;
        }
        else
        {
            Last->next = newn;
            Last = newn;
            Last->next = First;
        }
        Count++;
    }

    template <class T>
    void SinglyCL<T> :: InsertAtPos(T No,int iPos)
    {
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
            struct node<T> * temp = First;
            int i = 0;

            struct node<T> * newn = NULL;
            newn = new struct node<T>;

            newn->data = No;
            newn->next = NULL;

            for(i=1; i < iPos-1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
        Count++;
    }    

    template <class T>
    void SinglyCL<T> :: DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > Count))
        {
            cout<<"Invalid Position \n";
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == Count)
        {
            DeleteLast();
        }
        else
        {
            struct node<T> * temp = First;
            struct node<T> * targetednode = NULL;
            int i = 0;

            for(i=1; i < iPos-1; i++)
            {
                temp = temp->next;
            }
            targetednode = temp->next;
            temp->next = temp->next->next;
            delete targetednode;
            Count--;
        }
    }

    template <class T>
    void SinglyCL<T> :: DeleteFirst()
    {
        if((First == NULL) || (Last == NULL))
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
            Last->next = First;
            Count--;
        }
       
    }

    template <class T>
    void SinglyCL<T> :: DeleteLast()
    {
        if((First == NULL) || (Last == NULL))
        {
            return;
        }
        else if(First == Last)
        {
            delete First;
            First = NULL;
            Last  = NULL;
        }
        else
        {
            struct node<T> * temp = First;

            while(temp->next != Last)
            {
                temp = temp->next;
            }
            delete Last;
            Last = temp;
            Last->next = First;
        }
        Count--;
    }

    template <class T>
    void SinglyCL<T> :: Display()
    {
        cout<<"\nElements of the linked list are : \n";
        
        if((First != NULL) && (Last != NULL))
        {   
            do
            {
                cout<<"| "<<First->data<<" |->";
                First = First->next;
            } while (First != Last->next);
        }
    }

    template <class T>
    int SinglyCL<T> :: CountNode()
    {
        return Count;
    }



int main()
{
    cout<<"\n------------------------------------\n";
    cout<<"Singly Circular Linked List \n";
    cout<<"------------------------------------\n";

    SinglyCL <int> iobj;
    SinglyCL <float> fobj;
    SinglyCL <double> dobj;
    SinglyCL <char> cobj;

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