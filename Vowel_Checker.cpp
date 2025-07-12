#include<iostream>
using namespace std;
int main(){
char eng;
cout<<"Enter an English single character:";
cin>>eng;
switch (eng){
case 'a':
    cout<<"a is vowel";
    break;
case 'e':
    cout<<"e is vowel";
    break;
case 'i':
    cout<<"i is vowel";
    break;
case 'o':
    cout<<"o is vowel";
    break;
case 'u':
    cout<<"u is vowel";
    break;
default:
    cout<<"Character is Consonant";
}
return 0;
}
