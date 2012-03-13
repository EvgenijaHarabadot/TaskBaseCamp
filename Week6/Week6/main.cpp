#include <iostream>
#include <string>
#include <conio.h>
#include "Steck.h"
using namespace std;

/* Введену послідовність записів з координатами (x,y) точок площини занести в список типу стек. 
Визначити пару точок, віддаль між якими найменша, і вилучити їх зі списку.
Використати функцію, яка визначає віддаль між двома заданими точками площини. */



bool enter(Steck &st);		//enter value of coordinate
void delMinD(Steck &st);	//delete elements, which have the smallest distance

void main(){

	Steck st;
	st.empty();

	if ( enter(st) ) {	

		delMinD(st);
		st.print();
}
		st.clear();             // delete stack
		getch();
	
}

bool enter (Steck &st) {
	int n;
	double x,y;

	printf("%s","Enter the amount of points   ");
	scanf("%d",&n);
	if ( n > 0 ) {
		for (int i = 0; i < n; i++){
			scanf("%lf %lf",&x,&y);
			st.push(x,y);
		}
		return true;
	}
	else return false;
}

void delMinD (Steck &st) {

	if (st.size() > 1) {
		int i1=st.minD()[0];
		int i2=st.minD()[1];
		st.clear(i1);
		st.clear(i2-1);
	}
}


