#include<iostream>
using namespace std;
int main(){
int num;
cout<<"Enter an integer:";
cin>>num;
if(num==0){
    cout<<"The number is Zero";
}
else if(num>=0){
    cout<<"The number is Positive";
}
else{
    cout<<"The number is Negative";
}
return 0;
}
