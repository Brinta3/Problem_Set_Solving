#include<iostream>
using namespace std;
int main(){
int num;
cout<<"Enter an integer:";
cin>>num;
if(num>0 && num<11){
    cout<<"number available "<<num;
}
else{
    cout<<"Unavailable";
}
return 0;
}
