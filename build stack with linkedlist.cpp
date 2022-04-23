#include <iostream>
using namespace std;

template<class type>
class stack
{
    struct Node
    {
        type data;
        Node* next;
    };
    Node* Head;
    int s=0;
public:
    stack():Head(0) {}
    stack(type value,int intial_size)
    {
        Head=0;
        while(intial_size--)
        {
            Node* node=new Node;
            node->data=value;
            node->next=Head;
            Head=node;
            s++;
        }

    }
    void push(type d)
    {
        Node* node=new Node;
        node->data=d;
        node->next=Head;
        Head=node;
        s++;
    }
    void pop()
    {
        if(s==0)
            return;
        Node* cur=Head->next;
        delete Head;
        Head=cur;
        s--;
    }
    type &top()
    {
        if(Head==0){
            cout<<"the stack is empty";
        }else
        return Head->data;
    }
    int size()
    {
        return s;
    }
    void print()
    {
        if(Head==0){
            cout<<"the stack is empty";
            return;
        }
        Node* cur=Head;
        while(cur!=0)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
    ~stack()
    {
        Node* cur=Head;
        while(cur!=0)
        {
            Node* temp=cur->next;
            delete cur;
            cur=temp;
        }
        Head=0;
    }
};
int main()
{
    stack<int> s;
    s.push(1);
    s.push(55);
    s.push(123);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.print();
    return 0;
}
