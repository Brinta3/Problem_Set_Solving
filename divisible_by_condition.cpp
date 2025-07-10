#include<iostream>
using namespace std;
int main(){
int a;
cout<<"Enter an Integer:";
cin>>a;
if(a%3==0 && a%5==0){
    cout<<"Divisible by 3 and 5";
}
else{
    cout<<"Not divisible by 3 and 5";
}
return 0;
}
