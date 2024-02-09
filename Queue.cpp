// Queue
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class Queue
{
    public:
        struct node<T> * First;

    Queue();
    void Enqueue(T No);
    T Dequeue();
    void Display();
};

    template <class T>
    Queue<T> :: Queue()
    {
        First = NULL;
    }

    template <class T>
    void Queue<T> :: Enqueue(T No)
    {
        struct node<T> * temp = First;

        struct node<T> * newn = NULL;
        newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;

        if(First == NULL)
        {
            First = newn;
        }
        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
    }

    template <class T>
    T Queue<T> :: Dequeue()
    {
        struct node<T> * temp = First;
        T iValue = 0;

        if(First == NULL)
        {
            cout<<"Queue is empty...\n";
            return -1;
        }
        else
        {
            iValue = First->data;
            First = First->next;
            delete temp;
        }
        return iValue;
    }

    template <class T>
    void Queue<T> :: Display()
    {
        cout<<"\nElements of the Queue are : \n";

        while(First != NULL) 
        {
            cout<<"| "<<First->data <<"| \n";
            First = First->next;
        }
    }

int main()
{
    cout<<"\n------------------------------------\n";
    cout<<"              Queue \n";
    cout<<"------------------------------------\n\n";


    Queue <int> iobj;
    Queue <float> fobj;
    Queue <double> dobj;
    Queue <char> cobj;

    iobj.Enqueue(11);
    iobj.Enqueue(21);
    iobj.Enqueue(51);
    iobj.Enqueue(101);

    iobj.Display();

    fobj.Enqueue(11.99);
    fobj.Enqueue(21.99);
    fobj.Enqueue(51.99);
    fobj.Enqueue(101.99);

    fobj.Display();

    dobj.Enqueue(11.9999);
    dobj.Enqueue(21.9999);
    dobj.Enqueue(51.9999);
    dobj.Enqueue(101.999);

    dobj.Display();

    cobj.Enqueue('A');
    cobj.Enqueue('B');
    cobj.Enqueue('C');
    cobj.Enqueue('D');

    cobj.Display();
    
    return 0;
}