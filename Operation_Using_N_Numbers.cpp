#include<iostream>
using namespace std;
int main(){
int n;
int sum;
cout<<"Enter value of N:"<<endl;
cin>>n;
cout<<" Even numbers from 1 to N is:"<<n<<endl;
for(int i=1; i<=n; i++){
        if(i%2==0){
    cout<<i<<endl;
        }
}
cout<<" Odd numbers from 1 to N is:"<<n<<endl;
for(int i=1; i<=n; i++){
        if(i%2!=0){
    cout<<i<<endl;
        }
}
for(int i =1; i<=n; i++){
    sum=sum+i;
    //sum+=i;
}
cout<<"The sum of n numbers:"<<sum;
return 0;
}
