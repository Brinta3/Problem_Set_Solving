#include<iostream>
using namespace std;
int main(){
int a=2,b=7,temp;
cout<<"a is:"<<a<<endl;
cout<<"b is:"<<b<<endl;
temp=a;
a=b;
b=temp;
cout<<"After swap:"<<endl;
cout<<"a is:"<<a<<endl;
cout<<"b is:"<<b<<endl;
return 0;
}
