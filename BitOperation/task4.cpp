#include <conio.h>
#include <iostream>

using namespace std;

static void change(unsigned long &l,int i, int j)
{

int zs;
zs=((l&(1<<i))>>i)^((l&(1<<j))>>j);
l=((zs<<i)|(zs<<j))^l;

}
/*  If values of the bits  with given numbers are not equal we get 1 (zs=1). 
We get number  with two 1 in i and j position. Operation ^ changes value.
 */


static void two(unsigned long &l){                  //function that returns  number in binary system
unsigned long t;
cout<<"Namber "<<l <<" in binary system"<<endl;
t=((unsigned long)1<<(sizeof(unsigned long)*8-1));
for (int i=0; i<(sizeof(unsigned long))*8; i++)
{if(l&(t>>i))
cout<<1; else cout<<0;}cout<<endl;
}

int main(int argc, char *argv[]){                     //entry point
unsigned long number=0;
int l,m;
cout<<"Enter the number"<<endl;
cin>>number;
two(number);
cout<<"Enter the position"<<endl;
cin>>l;
cin>>m;
change(number,l,m);
cout<<number<<endl;
two(number);
getch();
exit(0);
}