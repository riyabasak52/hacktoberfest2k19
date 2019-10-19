#include "stdio.h"
#include "conio.h"
#include "iostream.h"
using namespace std;
int insertdata(int x);
void display();
void deleteint(int x);
int searchint(int x);

int compare_fn(int a,int b)
{
    //Write the compare function for the variables 'a' and 'b' and return the value
    return a>b?a:b;
}

int compare_no=1;

struct node
{
    int data;
    node *prev;
    node *next;
};

//A missing line here which initialises the top condition.
struct node * top=NULL;

int main()
{
    int ch,d,y;
    char ans='y';
    while(ans=='y')
    {
        cout<<"\n\t 1.Insert        2. Delete     3.EXIT\nEnter Choice : ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter An Element To be inserted : ";
            cin>>d;
            d=insertdata(d);
            display();
        }
        else if(ch==2)
        {
            cout<<"Enter Element To Be Deleted : ";
            cin>>d;
            deleteint(d);
            display();
        }
        else
            return 0;
    }
    return 0;
}

int searchint(int x)
{
    int count=0;
    node *searchele=top;
    while( searchele!=NULL)
    {
        if(compare_fn(x,searchele->data)==compare_no)
        {
        searchele=searchele->next;
        count+=1;
        }
        else
        break;
    }
    return count;
}
int insertdata(int x)
{
    if(top==NULL)
    {
        //Write a code for this particular condition where TOP == NULL
        node *n=new node;
        n->data=x;
        n->next=NULL;
        n->prev=NULL;
        top=n;

    }
    else if(compare_fn(top->data ,x)==compare_no)
    {
        node *n=new node;
        n->data=x;
        n->next=top;
        n->prev=NULL;
        top->prev=n;
        top=n;
    }
    else
    {
        int c=searchint(x);
        node *insertele=top;
        for(int i=0;i<c-1;i++)
        insertele=insertele->next;
        node *n=new node;
        n->data=x;
        node *b=insertele->next;
        node *N =insertele;
        N->next=n;
        n->prev=N;
        n->next=b;
        b->prev=n;
        //Write 3 lines of code which links all the nodes in the linked list while inserting the data into the list.
        if(b!=NULL)
        b->prev=n;
    }
}
void display()
{
    cout<<"Element In The Linked List Are : ";
    node *disp=top;
    while(disp!=NULL)
    {
        cout<<" "<<disp->data;
        if(disp->next==NULL)//write the particular condition for which the while condition needs to end
        {
        break;
        }
        disp=disp->next;
    }
}

void deleteint(int x)
{
    node *del=top;
    if(del->data == x)
    {
        if(top->next == NULL && top->prev == NULL)// Write the condition for which TOP should be NULL while deleting a particular node in a doubly linked list.
        {
            top=NULL;
            return;
        }
        del->next->prev=NULL;
        top=del->next;
    }
    else
    {
        node *delsuc=del->next;
        if(del==NULL)
        {
            cout<<"\nElement Not Found\n";
            return;
        }
        if(delsuc==NULL)
        {
            cout<<"\nElement Not Found\n";
            return;
        }
        while(delsuc->data != x)
        {
            del=del->next;
            delsuc=delsuc->next;
            if(del==NULL)
        {
        cout<<"\nElement Not Found\n";
        return;
        }
            if(delsuc==NULL)
        {
        cout<<"\nElement Not Found\n";
        return;
        }
        }
        del->next=delsuc->next;
        if(delsuc->next!=NULL)
            //Write the step for which a doubly linked list needs to be connected after deleting an element from the list.
            del->prev->next=delsuc;
            delsuc->prev=del->prev;
    }
}
