#include<iostream>
using namespace std;

struct node{
  int data;
  node* next;
};

class linkedList{
  node* head;
public:
  linkedList(int n, int A[]);//parameterised constructor with length and contents
  void insert(int entry, int position);//position from 0
  void deleteFromList(int position);//position from 1
  void reverse();
  void funFunction();//incomplete
  void display();
};

int main()
{
  int A[] = {1,2,3,4,5,6,7,8};
  linkedList list1(8,A);
  //list1.insert(14,14);
  //list1.deleteFromList(3);
  list1.reverse();
  list1.funFunction();
  list1.display();
  return 0;
}

linkedList::linkedList(int n, int A[])
{
  if(n>0)//if list is non-empty
  {
//adding head to the list
  //creating new node
    node* newnode = new node;
    newnode->data = A[0];
    newnode->next = NULL;
  //assigning head to list
    head = newnode;
  }
//adding rest of the nodes to the list
  node *previous = head;
  for(int i=1; i<n; i++)
  {
  //creating new node
    node* newnode = new node;
    newnode->data = A[i];
    newnode->next = NULL;
  //adding node to list
    previous->next = newnode;
    previous = newnode;
  }
}

void linkedList::insert(int entry, int position)
{
//creating new node with new data
  node *newnode = new node;
  newnode->data = entry;
  newnode->next = NULL;
//if list is empty
  if(head==NULL)
    head = newnode;
//if position is in starting
  else if(position == 0)
  {
    newnode->next = head;
    head = newnode;
  }
//if position is in middle or end
  else
  {
    node *iterator = head ;
    position--;//to align position with iterator
    while(iterator->next != NULL && position-- > 0)
    {
      iterator = iterator->next;
    }
    //if position is in middle of list
    if(iterator->next != NULL)
    {
      newnode->next = iterator->next;
      iterator->next = newnode;
    }
    //if position is at the end of the list
    else
      iterator->next = newnode;
  }
}

void linkedList::deleteFromList(int position)
{
  if(head != NULL)//if list is non-empty
  {
  //if starting node has to be deleted
    if(position == 1)
    {
      node* temp = head->next;
      delete head;
      head = temp;
    }
  //if node to be deleted is in middle or end
    else
    {
      node* iterator = head->next, *previous = head;
      position-=2;//alignment purpose with head
      while(iterator->next != NULL && position-->0)
      {
        iterator = iterator->next;
        previous = previous->next;
      }
  //if position is in middle(nor start nor end)
      if(iterator->next != NULL)
      {
        previous->next = iterator->next;
        delete iterator;
      }
  //if position is at the end
      else
        {
          previous->next = NULL;
          delete iterator;
        }
    }
  }
}

void linkedList::reverse()
 {
  if(head->next != NULL)//list contains more than 2 nodes
  {
    node* iterator = head->next, *lastOfList = head;
    while(lastOfList->next != NULL)
    {
      node* temp = iterator->next;
      iterator->next = head;
      head = iterator;
      lastOfList->next = temp;
      iterator = lastOfList->next;
    }
  }
 }
////////////////////////////////incomplete
void linkedList::funFunction()
{
  reverse();
  //complete
}
////////////////////////////////----------
void linkedList::display()
{
  while(head != NULL)
  {
      cout<<head->data<<" ";
      head = head->next;
  }
}
