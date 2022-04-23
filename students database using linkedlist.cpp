#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string name;
    int id;
    double GPA;
    student* next;
    student():name(""),id(0),GPA(0){}
    student(string name,int id,double GPA){
        this->name=name;
        this->id=id;
        this->GPA=GPA;
    }
};
class StudentList
{
    student* head;
public:
    StudentList():head(0) {}
    void insert(student a)
    {
        student* node=new student;
            node->name=a.name;
            node->id=a.id;
            node->GPA=a.GPA;
        if(head==0 || head->id>a.id)
        {
            node->next=head;
            head=node;
            return;
        }
        student* prev=head;
        student* cur=head->next;
        while(cur!=0 && cur->id<=a.id)
        {
            prev=cur;
            cur=cur->next;
        }
        node->next=cur;
        prev->next=node;
    }
    void delet(int a)
    {
        if(head==0)
            return;
                if(head->id==a)
            {
                student* temp=head->next;
                delete head;
                head=temp;
                return;
            }
        student* prev=head;
        student* cur=head->next;
        while(cur!=0 && cur->id!=a)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur!=0)
        {
            prev->next=cur->next;
            delete cur;
        }
    }
    void display()
    {
        student* cur=head;
        int n=1;
        while(cur!=0)
        {
            cout<<"student "<<n++<<" "<<cur->name<<" "<<cur->id<<" "<<cur->GPA<<endl;
            cur=cur->next;
        }
    }
    void search(int a)
    {
        if(head->id==a)
        {
            cout<<head->name<<" "<<head->id<<" "<<head->GPA<<endl;
            return;
        }
        student* cur=head;
        while(cur!=0)
        {
            if(cur->id==a)
            {
                cout<<cur->name<<" "<<cur->id<<" "<<cur->GPA<<endl;
                return;
            }
            cur=cur->next;
        }
        cout<<"Not found";
    }
    ~StudentList()
    {
        student* cur=head;
        while(cur!=0)
        {
            student* temp=cur->next;
            delete cur;
            cur=temp;
        }
        head=0;
    }

};
int main()
{
   StudentList list;
    student s1("ahmed",20188006,3.4);
    student s2("akram",20188060,3.9);
    student s3("salma",20188014,4.0);
    student s4("mona",20188028,2.1);
    list.insert(s1);
    list.insert(s2);
    list.insert(s3);
    list.insert(s4);
    list.delet(20188006);
    list.delet(20188060);
    list.search(20188014);
    list.display();

    return 0;
}
