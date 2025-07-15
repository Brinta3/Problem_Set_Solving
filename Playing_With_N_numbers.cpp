#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter value of N:"<<endl;
cin>>n;
cout<<"number from 1 to N is:"<<endl;
for(int i=1; i<=n; i++){
    cout<<i<<endl;
}
cout<<"number from N to 1 is:"<<endl;
for(int i=n; i>=1; i--){
    cout<<i<<endl;
}
return 0;
}
