#include<iostream>
using namespace std;

void copy(char input[], char output[])
{
  int i=0;
  while((output[i] = input[i]) != '\0')
  {
    i++;
  }
}

int main()
{
  char input[] = "hello world";
  char output[20];
  copy(input,output);
  cout<<output;
  return 0;
}
