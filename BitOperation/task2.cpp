#include <conio.h>
#include <iostream>

using namespace std;
long* maxTwo(long a[])
{long b[2], c[2];                                  //function that returns  min and max number
b[0] = a[0] - a[1];
 b[1] = a[1] - a[0];
 b[0] = (unsigned)b[0] >> (sizeof(long)*8-1);
 b[1] = (unsigned)b[1] >> (sizeof(long)*8-1);
c[0] = a[b[1]];
 c[1] = a[b[0]];
 return c;
}
/* 0 returned  if a[0] is greated than  a[1] , 1 - otherwise. 
It determines order of the first element. Similarly, the second.*/

int main(int argc, char *argv[]){                  //entry point
signed long a[2];
cout<<"Enter the two number"<<endl;
cin>>a[0];
cin>>a[1];
cout<<maxTwo(a)[0]<<" "<<maxTwo(a)[1]<<endl;
getch();
exit(0);
}