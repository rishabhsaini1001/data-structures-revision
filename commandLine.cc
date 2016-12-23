#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
  int count[5] = {0};
  for(int i=0;i<argc;i++)
  {
    cout<<endl<<argv[i];
      //cout<<(int)'1'<<'\n';

    switch(*argv[i])
    {
      case '1': count[1]++;
              break;
      case '4': count[4]++;
              break;
    };
  }
  cout<<"count of 1s"<<count[1]<<endl;
  cout<<"count of 4s"<<count[4]<<endl;
  return 0;
}
