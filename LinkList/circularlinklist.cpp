#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtAnyPos(Node* &head,int pos,int value)
{
    //Allocate node to new element
    Node* newNode = new Node(value);
    
    newNode->next = NULL;
    //check position >0
    if(pos<1)
    {
        cout<<"Position should be >=1"<<endl;
    }
    else if(pos == 1)
    {
        //if the position is 1, make next of the
         //new node as head and new node as head
        Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head=newNode;  
    }
    else
    {
      Node* temp = head;
      for(int i=1;i<pos-1;i++)
      {
          if(temp != NULL)
          {
            temp = temp->next;
          }
          
      }
      if(temp != NULL)
      {
          newNode->next = temp->next;
          temp->next = newNode; 

      }
      else
      {
        cout<<"The previous node is null"<<endl;
      }
    }
   

}

void  insertATHead(Node*&head,int val)
{
Node* n = new Node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    
    Node* temp = head;
    while(temp->next != head)
      {
        temp = temp->next;
      }
    temp->next = n;
    n->next = head;
    head=n;

}

void insertTail(Node*&head,int val)
{

    if(head == NULL)
    {
        insertATHead(head,val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next=n;
    n->next = head;
}

void Display(Node*&head)
{
    Node* temp = head;
    do
    {
       cout<<temp->data<<" ";
       temp=temp->next;
    } while(temp!=head);
    cout<<temp->data;
    cout<<endl;
}

deleteHead(Node*&head)
{
     Node* temp = head;
     while(temp->next != head)
     {
       temp = temp->next;

     }
     Node* todelete = head;
     temp->next = head->next;
     head = head->next;
     delete todelete;
}

void Deletion(Node*&head,int pos)
{

    if(pos==1)
    {
        deleteHead(head);
        return;
    }
    Node* temp = head;
    int count=1;
    while(count != pos-1)
    {
        temp=temp->next;
        count++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

int main()
{
    Node* head = NULL;
   int choice;
   int a,b,ele,pos;
   while(choice != 5)
   {
       cout<<"**************************************"<<endl;
       cout<<"Press 1 : Insert"<<endl;
       cout<<"Press 2 : Delete"<<endl;
       cout<<"Press 3 : Display"<<endl;
       cout<<"Press 4 : Insert At Any position"<<endl;
       cout<<"Press 5 : Exit"<<endl;
       cout<<"**************************************"<<endl;
       cout<<"Enter Your Choice :"<<endl;
       cin>>choice;
       switch(choice)
       {
            case 1:
                  cout<<"Enter the element you want to insert : "<<endl;
                  cin>>a;
                  insertTail(head,a);
                  break;
            case 2:
                  cout<<"Enter the position of element you want to delete : "<<endl;
                  cin>>b;
                  Deletion(head,b);
                  break;
            case 3:
                   Display(head);
                   break;
            case 4:
                  cout<<"Enter the element you want to insert : "<<endl;
                  cin>>ele;
                  cout<<"Enter the position of element you want to insert : "<<endl;
                  cin>>pos;
                  insertAtAnyPos(head,pos,ele);
                  Display(head);
                  break;
       }
   };
    return 0;
}

//OUTPUT
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert : 
// 4
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position      
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert : 
// 7
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position      
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert : 
// 6
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 2
// Enter the position of element you want to delete : 
// 6
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 3
// 4 7 4
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 4
// Enter the element you want to insert : 
// 35
// Enter the position of element you want to insert : 
// 1
// 35 4 7 35
// PS C:\ADS> 
   