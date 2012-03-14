#include <iostream>
#include <conio.h>
#include "Struct.h"

struct List { //create list of segments
	Section *head; //pointer to head element
	Section *tail; //pointer to last element
};



//creates empty list
void emptyL (List &l) {                  
	l.head = NULL;
	l.tail = NULL;
}
//returns true if list is empty
bool isEmptyList (List &l) {                
	return (l.head == NULL);
}
//returns amount of element in list
int size (List &l) {
	Section *e = l.tail;
	int i=0;
	while(e != NULL)
	{
		++i;
		e=e->next;
	}
	e = NULL;
	return i;
}
//adds new element to end of list
void add (List &l, double a, double b) {
	Section  *e1 = new Section;
	e1->a=a;
	e1->b=b;
	e1->empty=false;
	e1->next=NULL;
	e1->previous=NULL;

	if(isEmptyList(l))
	{
		l.head=e1;
		l.tail=e1;
	}
	else {
		l.head->next=e1;
		e1->previous=l.head;
		l.head=e1;
	}
}
//deletes  n elements
void deleteNumber (List &l, int n) {
	for (int i=0; i<n ; i++){
		Section *d=l.tail;

		if(d!=NULL)
		{
			l.tail=l.tail->next;
			l.tail->previous=NULL;
			delete d; d=NULL;
		}
	}			
}


