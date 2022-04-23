#include <iostream>

using namespace std;
bool t=true,t2=true;
template<class type>
class list
{
    struct Node
    {
        type data;
        Node* next;
        Node* back;
    };
    Node* head=0;
    Node* tail=0;
    int s=0;
public:
    list():head(0),tail(0) {}
    list(type value,int intial_size)
    {
        while(intial_size--)
        {
            if(head==NULL)
            {
                Node* node=new Node;
                node->data=value;
                node->next=0;
                node->back=0;
                head=tail=node;
            }
            else
            {
                Node* node=new Node;
                node->data=value;
                node->next=0;
                node->back=tail;
                tail->next=node;
                tail=node;

            }
            s++;
        }
    }
    class iterator
    {
        Node* cur;
    public:
        iterator(Node* n)
        {
            cur=n;
        }
        void operator ++()
        {
            if(cur->next==0)
                    throw "out of range";
            cur=cur->next;
        }
        void operator --()
        {
            if(cur->back==0)
                throw "out of range";
            cur=cur->back;
        }
        void operator ++(type)
        {
           if(cur->next==0)
                    throw "out of range";
            cur=cur->next;
        }
        void operator --(type)
        {
            if(cur->back==0)
                throw "out of range";
            cur=cur->back;
        }
        type& operator *()
        {
            return cur->data;
        }
        bool operator == (const iterator &p)
        {
            return cur==p.cur;
        }
        bool operator != (const iterator &p)
        {
            return cur!=p.cur;
        }
    };

    void push_back(type d)
    {
        Node* node=new Node;
        node->data=d;
        if(head==NULL)
        {
            node->next=head;
            node->back=0;
            head=tail=node;
        }
        else
        {
            node->next=0;
            node->back=tail;
            tail->next=node;
            tail=node;
        }
        s++;
    }
    void insert(type value,iterator i)
    {

        Node* node=new Node;
        Node* prev=head;
        Node* cur=head->next;
        Node* endd=tail;
        iterator j(prev),k(cur),v(endd);
        if(j==i)
        {
            node->data=value;
            node->next=head;
            node->back=0;
            head=node;
        }
        else if(v==i)
        {
            node->data=value;
            node->next=tail;
            node->back=tail->back;
            tail->back->next=node;
            tail->back=node;
        }
        else
        {
            while(k!=i)
            {
                prev=cur;
                cur=cur->next;
                k++;
            }
            node->data=value;
            node->next=cur;
            node->back=prev;
            prev->next=node;
            cur->back=node;
        }
        s++;
    }
    iterator erase(iterator position)
    {
        Node* prev=head;
        Node* cur=head->next;
        Node* endd=tail;
        iterator j(prev),k(cur),v(endd);
        if(j==position)
        {
            Node* temp=head->next;
            delete head;
            head=temp;
            head->back=0;
            iterator m(head->next);
            s--;
            return m;
        }
        else if(v==position)
        {
            Node* temp=tail->back;
            delete tail;
            tail=temp;
            tail->next=0;
            iterator m(0);
            s--;
            return m;
        }
        else
        {
            while(k!=position)
            {
                prev=cur;
                cur=cur->next;
                j++;
                k++;
            }
            prev->next=cur->next;
            cur->next->back=prev;
            delete cur;
            iterator m(prev->next);
            s--;
            return m;
        }

    }
    list<type>& operator = (list<type> another_list)
    {
        Node* m=another_list.head;
        while(m!=0)
        {
            Node* node=new Node;
            if(this->head==NULL)
            {
                node->data=m->data;
                node->next=0;
                node->back=0;
                this->head=this->tail=node;
            }
            else
            {
                node->data=m->data;
                node->back=this->tail;
                node->next=0;
                this->tail->next=node;
                this->tail=node;
            }
            m=m->next;
        }
        this->s=another_list.s;
        return *this;
    }
    list::iterator begin()
    {
        return iterator(head);
    }
    list::iterator end()
    {
        return iterator(tail->next);
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
            cout<<cur->data;
            cur=cur->next;
        }
    }
    ~list()
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
    try{
    list<int> l(9,1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    list<int>::iterator it=l.begin();
    it++;it++;
    l.insert(1,it);
    l.erase(it);
    /*if(l.erase(it)==0){
        throw "out of range";
    }*/
    /*for(it=l.begin(); it!=l.end(); it++) ///it==the new begin of the modified list
    {
        cout<<*it;
    }*/
    cout<<endl;
    cout<<l.size();
    }catch(...){
        cout<<"out of range";
    }

    /*list<int> L2;
    L2=l;
    list<int>::iterator b=L2.begin();
    for(b=L2.begin(); b!=L2.end(); b++)
    {
        cout<<*b;
    }*/

    return 0;
}
