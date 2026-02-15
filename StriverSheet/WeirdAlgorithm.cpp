#include <iostream>
using namespace std;

 void Algorithm(long n){
    cout<<n<<" ";
    while(n!=1){
        if(n%2==0){

            n/=2;
            cout<<n<<" ";
        }
        else
        {
            n = n*3+1;
            cout<<n<<" ";
        }
    }

    return;
}

int main(){
    cout<<"NEW VERSION\n";
  long n;
  cout<<"Enter a positive integer n: ";
  cin>>n;
  if(n<=0){
    cout<<"please enter a positive integer greater than 0";
    return 0;
  }
  Algorithm(n);
  return 0;
}