#include<iostream>
using namespace std;

class stack{
  int dataStack[100];
  int top;
public:
  stack();//to initialise stack with no data
  stack(int n,int input[]);//to initialise stack with an array input in an ascending push manner
  void push(int data);//to push an integer
  int pop();//if no data returns -9999
  void display();//displays stack data from to in a pop fashion
};

int main()
{
  int B[] = {1,2,3,4,5,6,7,8,9,10};
  stack s1(19,B);
  s1.push(11);
  //cout<<s1.pop();
  s1.display();
  return 0;
}

stack::stack()
{
  top = -1;
}

stack::stack(int n, int input[])
{
  top = -1;
  for(int i=0;i<n;i++)
    push(input[i]);
}

void stack::push(int data)
{
  if(top+1<100)
    dataStack[++top] = data;
}

int stack::pop()
{
  if(top>-1)
    return dataStack[top--];
  else
    return -9999;
}

void stack::display()
{
  for(int i=top;i>-1;i--)
    cout<<dataStack[i]<<":";
}
