#include <conio.h>
#include <iostream>


/*Використовуючи тільки бітові та арифметичні операції, написати функцію, 
яка повертає наступне парне число за заданим беззнаковим довгим цілим числом.*/


using namespace std;

static unsigned long nextPaired						//function that returns next even number
(unsigned long &l){
 l=l+((unsigned long)2>>(l&(unsigned long)1)); return l;
}
/*  If the youngest  bit in number is 1 it means that number is odd, else even. 
If this number is odd we add one, else add two. */


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
cout<<"Enter the number"<<endl;
cin>>number;
two(number);
nextPaired(number);
cout<<"The next paired number is  "<<number<<endl;
two(number);
getch();
exit(0);
}
