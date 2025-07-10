#include<iostream>
using namespace std;
int main(){
int a,b,c;
cout<<"Enter num1:";
cin>>a;
cout<<"Enter num2:";
cin>>b;
cout<<"Enter num3:";
cin>>c;
if(a>b && a>c){
    cout<<"a is biggest";
}
else if(b>a && b>c){
    cout<<"b is biggest";
}
else{
    cout<<"c is biggest";
}
return 0;
}
