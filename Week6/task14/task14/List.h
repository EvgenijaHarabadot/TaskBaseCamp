#include "element.h"

class List  {
protected:
Element *head;  //pointer to head element
Element *tail;  //pointer to last element

public:

bool isEmpty ();		//returns true if list is empty
void add (int x);      // adds new element 
unsigned int size ();		// returns amount of element in list

Element* pop (int n);			//returns element with number n
unsigned int index (Element *p);//returns number of element

void clear (int n);			//deletes element with number n

};

bool List:: isEmpty (){
	return (head == NULL);
}
void List::add (int x) {

	Element *e1 = new Element (x);     //creates new element
	e1-> setP ( NULL );
	e1-> setN ( NULL );

	if ( isEmpty() ) {			//if list is empty, this element will be first (with number 0)
		head = e1;
		tail = e1;
	}
	else {						//if list is not  empty, this element adds and it is tail
		e1->setP ( tail );
		tail->setN ( e1 );
		tail = e1;
	}
}
unsigned int List:: size () {
	unsigned i=0;

	if(!isEmpty()) {

		Element *p =  tail;
		while( p ) {
			++i;
			p = p->getP();	
		}
	}
	return i;
} 
unsigned int List:: index (Element *p) {
	unsigned i = 0;

	if ( !isEmpty() ) {	

		Element *p1 = tail;
		while( p1 != p && p1)
		{
			++i;
			p1 = p1->getP();
		}
		return i;
	}
	else return -1;  //returns if list is empty
}
Element*  List::pop (int n) {

	if ( !isEmpty() && n>=0 ) {   //if stack is not empty and  number n is correct
		Element *p=tail;

		while ( index(p) != n )
		{
			p = p->getP();	
		}
		return p;	
	}
	else return NULL;              
}
void List:: clear (int n) {

	if( !isEmpty() && pop(n) ) {		//if stack is not empty and element with number n exist
		Element *p = pop(n);				
		if (size() == 1) {
			p->setN ( NULL );
			p->setP ( NULL );
			tail = NULL;
			head = NULL;
		}
		else 
			if (p == tail) {
				tail = tail->getP();
				tail->setN ( NULL );
			}
			else	
				if ( p == head ) {  
					head = head->getN();
					head->setP ( NULL );
				}
				else {
					p->getP()->setN ( p->getN() );
					p->getN()->setP ( p->getP() );

				}
				if(p) delete p; p = NULL;
	}
} 