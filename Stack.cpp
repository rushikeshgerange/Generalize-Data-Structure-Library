// Stack
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};
 
template <class T>
class Stack
{
    public:
        struct node<T> * First;
        int iCount;
    
    Stack();
    void Push(T No);
    T Pop();
    void Display();
};

    template <class T>
    Stack<T> :: Stack()
    {
        First = 0;
        iCount = 0;
    }

    template <class T>
    void Stack<T> :: Push(T No)
    {
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
            newn->next = First;
            First = newn;
        }
        iCount++;
    } 

    template <class T>
    T Stack<T> :: Pop()
    {
        struct node<T> * temp = First;
        T iValue = 0;

        if(First == NULL)
        {
            cout<<"Stack is empty...\n";
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
    void Stack<T> :: Display()
    {
        cout<<"\nElements of the stack are : \n";

        while(First != NULL) 
        {
            cout<<"| "<<First->data <<"| \n";
            First = First->next;
        }
    }

int main()
{
    cout<<"\n------------------------------------\n";
    cout<<"              Stack \n";
    cout<<"------------------------------------\n\n";

    Stack <int> iobj;
    Stack <float> fobj;
    Stack <double> dobj;
    Stack <char> cobj;

    iobj.Push(101);
    iobj.Push(51);
    iobj.Push(21);
    iobj.Push(11);

    iobj.Display();

    fobj.Push(101.99);
    fobj.Push(51.99);
    fobj.Push(21.99);
    fobj.Push(11.99);

    fobj.Display();

    dobj.Push(101.999);
    dobj.Push(51.9999);
    dobj.Push(21.9999);
    dobj.Push(11.9999);

    dobj.Display();

    cobj.Push('D');
    cobj.Push('C');
    cobj.Push('B');
    cobj.Push('A');

    cobj.Display();

    return 0;

}