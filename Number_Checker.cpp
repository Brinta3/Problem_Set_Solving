#include<iostream>
using namespace std;
int main(){
int a, c;
cout<<"Enter an integer number:";
cin>>a;
if(a%2==0){
    cout<<"Number is Even";
}
else{
    cout<<"Number is Odd";
}
cout<<endl;
cout<<"Square is"<<a*a<<endl;
for(int i=1; i<a; i++){
    if(a%i==0){
        c=c+1;
    }
}
if(c==2){
    cout<<"Number is Prime";
}
else{
    cout<<"Number is Not Prime";
}
return 0;
}
