#include <conio.h>
#include <iostream>

using namespace std;
static signed long max(signed long &l){
l=(~((l&(1<<31))>>31))&l; return l;
}
/*if it is a negative number we get 1, else 0; reversed and multiplied by the number.*/

int main(int argc, char *argv[]){   //entry point
	char c[sizeof(long)];
signed long a;
cout<<"Enter the two number"<<endl;
cin>>a;
cout<<itoa(a,c,2);
max(a);
cout<<a<<endl;
getch();
exit(0);
}