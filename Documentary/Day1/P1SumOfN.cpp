#include<iostream>
using namespace std;
int main()
{
  int n,i=0;
  cout<<"Enter Last Number :";
  cin>>n;
  int sum = 0;

  while(i<=n)  
  {
    sum = i+sum;
    i++;


  }
  cout<<sum;
}