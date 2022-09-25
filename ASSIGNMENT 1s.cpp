//ABHIJEET CHANDRA
//21105116
//ASSIGNMENT 1
#include<bits/stdc++.h>
using namespace std;

//member is a node of our linked list containing data : Name and age of family members 

struct member
{
    string name;
    int age;
    member *previous;
    member *next;

};

class family
{ 
    
   member *tail=NULL;
   member *head=NULL;

   public:

 //function to add new members from head or from front
    
    void new_member_front(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(tail==NULL)
            tail=person;
        if(head==NULL)
           person->previous=NULL;
        else
           {person->previous=head;
            head->next= person;}

        person->next=NULL;
        head=person;

    }
 //function to add new members from back or from tail
        void new_member_back(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(head==NULL)
            head=person;
        if(tail==NULL)
           person->next=NULL;
        else
           {person->next=tail;
           tail->previous=person;}

        person->previous=NULL;
        tail=person;

    }
    
    void deleteFromTail(int n)//n is the number of members to be deleted
    {
        cout<<endl;

        if(head==NULL)
          { cout<<"no members left in the list.";
            return;
          }

        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
            member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            member *temp = tail;
            tail= tail->next;
            tail->previous=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }

    void deleteFromHead(int n)//n is the number of members to be deleted
    {
        cout<<endl;
        if(head==NULL)
          { cout<<"no members left in the list.";
            return;
          }


        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
             member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        

        for(int i=0;i<n;i++)
        {
            member *temp = head;
            head=head->previous;
            head->next=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }

//to simultaneously remove and store the member at head
    member* popHead()
    {   
        if(head==NULL)
           {cout<<"no members left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member *temp= head;
        head=head->previous;
        head->next=NULL;
        temp->previous=NULL;

        return temp;
    }

//to simultaneously remove and store the member at tail

    member* popTail()
    {
        if(head==NULL)
           {cout<<"no members left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member* temp= tail;
        tail=tail->next;
        tail->previous=NULL;
        temp->next=NULL;
        
        return temp;
    }

//to display family starting from tail
    void displayFromTail()
    {
        cout<<endl;
         if(head==NULL)
           {cout<<"no members left in the list."; 
           return;}
        
        member* temp = tail;
        cout<<"Tail <-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->next;
        }
        cout<<"Head";
    }

//to display family starting from head

    void displayFromHead()
    {  cout<<endl;
         if(head==NULL)
           {cout<<"no members left in the list.";
           return;}
        member* temp = head;
        cout<<"Head<-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->previous;
        }
        cout<<"Tail";
    }

};

int main()
{ 
    family chandra;
    chandra.new_member_front("vishal",7);
    chandra.new_member_front("ishika",18);
    chandra.new_member_front("vinay",25);
    chandra.new_member_front("yash",35);
    chandra.new_member_back("khushi",10);
    chandra.displayFromHead();
    cout<<endl;
    chandra.displayFromTail();
    cout<<endl;
    chandra.deleteFromHead(2);
    chandra.displayFromHead();
    chandra.displayFromTail();
   
    cout<<endl<<chandra.popTail()->name;
    chandra.displayFromTail();
    return 0;
}

//Bonus Question:
//Since there are only two ways to transverse we can link different members in a family using linked list only accoring to their ages else there are many cases to be 
// considered 
//like elder and younger in the hierarchy like the elder one on the head and the younger one on the tail....