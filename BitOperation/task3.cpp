#include <conio.h>
#include <iostream>

using namespace std;

static unsigned long  compare					   //function that compare two bit
(int i,int j,unsigned long &l){unsigned long z,w;
 z=1<<(i);
 z=z&l;
 w=1<<(j);
 w=w&l;
 z=z>>(i);
 w=w>>(j);
 l=(z^w);
 return l;
}
/*Determine the value of the bits  with given numbers. 
Operation >>i and >>j returns the bit  in first position; 
^ returns 1 if two these value is not equal.
*/

static void two(unsigned long &l){                  //function that returns  number in binary system
unsigned long t;
cout<<"Namber "<<l <<" in binary system"<<endl;
t=(1<<(sizeof(unsigned long)*8-1));
for (int i=0; i<(sizeof(unsigned long))*8; i++)
{if(l&(t>>i))
cout<<1; else cout<<0;}cout<<endl;
}

int main(int argc, char *argv[]){                   //entry point
unsigned long number=0,l=0,m=0;
cout<<"Enter the number and position"<<endl;
cin>>number;
two(number);
cin>>l;
cin>>m;
compare(l,m,number);
cout<<number;
getch();
exit(0);
}