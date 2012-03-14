/*	Сформувати з введених беззнакових цілих чисел список типу черга. 
Використовуючи функцію, яка витирає зі списку останній елемент, 
що містить непарне число, вилучити зі сформованої черги три останніх непарних числа.*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Queue.h"
using namespace std;



void main(){

Queue l;
l.empty();

l.enter(); //enter number
l.print(); 
l.odd();	// deletes last odd element
l.odd();
l.odd();
l.print();
l.clear();	//deletes all element

getch();
	
}