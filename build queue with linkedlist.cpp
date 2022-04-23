#include <iostream>

using namespace std;

template<class type>
class queue
{
    struct Node
    {
        type data;
        Node* next;
    };
    Node* head=0;
    Node* tail=0;
    int s=0;
public:

    queue():head(0),tail(0) {}
    queue(type value,int intial_size)
    {
        while(intial_size--)
        {
            Node* node=new Node;
            node->data=value;
            node->next=0;
            if(head==NULL)
            {
                head=tail=node;
            }
            else
            {
                tail->next=node;
                tail=node;
            }
            s++;
        }
    }
    void push(type a)
    {
        Node* node=new Node;
        node->data=a;
        node->next=0;
        if(head==NULL)
        {
            head=tail=node;
        }
        else
        {
            tail->next=node;
            tail=node;
        }
        s++;
    }
    void pop()
    {
        if(head==0)
            return;
        Node* cur=head->next;
        delete head;
        head=cur;
        s--;
    }
    type& front()
    {
        return head->data;
    }
    type& back()
    {
        return tail->data;
    }
    int size()
    {
        return s;
    }
    void print()
    {
        Node* cur=head;
        while(cur!=0)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
    ~queue()
    {
        Node* cur=head;
        while(cur!=0)
        {
            Node* temp=cur->next;
            delete cur;
            cur=temp;
        }
        head=tail=0;
    }
};
int main()
{
    queue<char> q('A',20);
    q.push('t');
    q.push('j');
    q.push('w');
    q.push('q');
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<" "<<q.back()<<endl;
    q.print();
    return 0;
}
