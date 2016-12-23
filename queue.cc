#include<iostream>
using namespace std;

class queue{
  int dataQueue[10];
  int front;
  int end;
public:
  queue();//constructor for empty queue
  queue(int n, int input[]);//constructor to initialise queue with array in a ascending enqueue manner
  void enqueue(int data);//add data to end of queue
  int dequeue();//return -9999 if empty
  void display();
};

int main()
{
  int A[] = {1,2,3,4,5,6,7,8,9};
  queue q(9,A);
    q.dequeue();
  q.enqueue(10);
  //cout<<q.dequeue();
  q.display();
  return 0;
}

queue::queue()
{
  front = 0;
  end = 0;
}

queue::queue(int n, int A[])
{
  front = 0;
  end = 0;
  for(int i=0;i<n;i++)
    enqueue(A[i]);
}

void queue::enqueue(int data)
{
  if((end+1)%10 != front)
    dataQueue[end++] = data;
}

int queue::dequeue()
{
  if(front != end)
    return dataQueue[front++];
  else
    return -9999;
}

void queue::display()
{
  for(int i=front; end != i; i=(i+1)%10)
    cout<<dataQueue[i]<<":";
}
