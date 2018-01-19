#include <iostream>
#include<stdlib.h>
using namespace std;
class Node
{
				//node of a LinkedList

public:
    int info;
//info of node
    Node*next;			//pointer to next node
    Node()
{
        info = 0;
        next = NULL;
}
};
//class declaration for LinkedList
class LinkedList
{
private:
    Node *head;
    Node *tail;
    int n;				//initialization size of LinkedList
public:
//setting the initial size of the LinkedList
    LinkedList()
{
    head = NULL;
    tail = NULL;
    n=0;
}
//inserting node in the end
    void Insert( int x )
{
        Node *temp = new Node;
        temp -> info = x;
        temp  -> next = NULL;
        ++n;
       					 //checking if the LinkedList is empty
        if (head==NULL){
            head = temp;
            tail = temp;
        }
        else
{
            tail -> next = temp;
            tail = temp;
        }
    }
//Inserting node at given position
    void InsertAt(int x, int y)
{					//x=info and y=position
        if (y>n+1)
{
            cout<<"Not enough nodes."<<endl;
        }
        else if (y==n+1)
{
            Insert(x);
            ++n;
        }
        else if (y==1)
{
            Node *temp=new Node;
            temp -> info = x;
            temp -> next = head;
            head = temp;
            ++n;
        }
        else {
            Node *find;
//to find the position where the node is to be inserted
            find = head;
            for (int i=1;i<y-1;i++)
{
                find = find -> next;
            }
            Node *temp=new Node;
            temp -> info = x;
            temp -> next = find -> next;
            find -> next = temp;
            ++n;
        }
    }
//deleting an element from the end
    void Delete()
    {
        Node *find;
//to find the last node
        find = head;
        while (find->next!=tail){
            find = find -> next;
        }
        delete tail;
        tail = find;
        find -> next = NULL;
        --n;
//decrement of number of nodes of LinkedList
    }
//deleting an element at a given position
    void DeleteAt(int x)
{
        if (x>n)
            cout<<"Not enough elements."<<endl;
        else if(x==1){
            Node *temp;//temporary node to be deleted later
            temp=head;
            head=temp->next;
            delete temp;
            --n;
        }
        else {
            Node *find;
//to find the position of the node to be deleted
            find=head;
            for (int i=1;i<x-1;i++){
                find = find->next;
            }
            Node *temp;
            temp = find->next;
            find->next=temp->next;
            delete temp;
            --n;
        }
        }
//number of elements in the LinkedList
    int Count(){
    return n;}
//display the elements of the LinkedList
    void Display(){
        Node *disp;
        disp=head;
        while (disp!=NULL){
            cout<<endl<<endl<<disp->info<<endl;
            disp=disp->next;
        }
        cout<<endl;

    }
};
int main(){
    LinkedList List1;
    int s;
    do {
    cout<<"Choose one of the following: \n 1.Insert \n 2.InsertAt \n 3.Delete \n 4.DeleteAt\n 5.Count \n 6.Display \n 7.Exit\n\n";
    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
    cin>>s;
    switch(s)
    {
     case 1:
        cout<<"Enter the element to be added:\n"<<endl;
        int x;
        cin>>x;
        List1.Insert(x);
        system("CLS");
        break;
    case 2:
        cout<<"Enter the element to be inserted and it's position: \n"<<endl;
        int a,b;
        cin>>a>>b;
        List1.InsertAt(a,b);
        system("CLS");
        break;
    case 3:
        List1.Delete();
        system("CLS");
        break;
    case 4:
        cout<<"Enter the position of the element to be deleted:"<<endl;
        int c;
        cin>>c;
        List1.DeleteAt(c);
        system("CLS");
        break;
    case 5:
        cout<<"The number of elements in the LinkedList is: "<<List1.Count()<<endl;
        break;
    case 6:
        system("CLS");
        List1.Display();

         break;
    default:
        s=7;
        cout<<"\nPlease enter correct choice(1-6)!!";
        break;
    }

} while (s!=7);
return 0;
}
