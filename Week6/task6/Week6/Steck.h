#include "Point.h"
#include "Distance.h"
class Steck : private Distance { //organises stack

Point *top;  //pointer to top element

public:
void empty ();			//creates empty stack
bool IsEmpty ();			//returns true if stack is empty
void push (double x, double y); // adds new element with coordinates	
Point* pop (int n);			//returns element with number n
unsigned int Index (Point *p);//returns number of element
unsigned int size ();		// returns amount of element in stack
void clear ();				//deletes all element in stack
void clear (int n);			//deletes element with number n
int * minD ();				//returns numbers of elements, which have the smallest distance
void print();				//outputs to  data about stack
};


void Steck:: empty (){                  
	top = NULL;
}

bool Steck:: IsEmpty (){
	return (top == NULL);
}

void Steck::push (double x, double y) {
	
	Point *e1 = new Point (x,y);     //creates new element
	e1-> Set(NULL);

	if ( IsEmpty() ) {			//if stack is empty, this element will be first (with number 0)
		top = e1;
	}
	else {						//if stack is not  empty, this element adds and it is top
		e1->Set(top);
		top = e1;
	}
}

unsigned int Steck:: Index (Point *p) {
	unsigned i = 0;

	if ( !IsEmpty() ) {	

		Point *p1 = top;
		while( p1 != p )
		{
			++i;
			p1 = p1->Get();
		}
		return i;
	}
	else return -1;  //returns if stack is empty
}

void Steck:: clear() {

	if( !IsEmpty() ) {
		Point *p = top;
		while( p != NULL )
		{
			top = top->Get();
			if(p) delete p; 
			p = top;
		}
		p = NULL;	
	}
} 

void Steck:: clear (int n) {

	if( !IsEmpty() && pop(n) ) {		//if stack is not empty and element with number n exist
		Point *p = pop(n);				
		//deletes all elements from the top
		if (p == top) {
			top = top->Get();
		}
		else	
			if ( p->Get() == NULL ) {  
					pop(n-1)->Set(NULL);
			}
			else {
				if ( pop(n-1) ) {
					pop(n-1)->Set(p->Get());
				}
			}
			if(p) delete p; p = NULL;
	}
} 
 
unsigned int Steck:: size() {
	unsigned i=0;

	if(!IsEmpty()) {

		Point *p =  top;
		while( p ) {
			++i;
			p = p->Get();	
		}
	}
	return i;
} 

Point*  Steck::pop (int n) {

	if ( !IsEmpty() && n>=0 ) {   //if stack is not empty and  number n is correct
		Point *p=top;

		while ( Index(p) != n )
		{
			p = p->Get();	
		}
		return p;	
	}
	else return NULL;              
}

int*  Steck:: minD() {
	double min;
	int *e=new int[2];
	min=dist(pop(0),pop(1));

	e[0]=Index(pop(0)) ;  e[1]=Index(pop(1));
	for ( int i = 0;  i < size();  i++ ) {
		for ( int j = i+1;  j < size();  j++ ) {

			if(min > dist( pop(i), pop(j) ) ) {
				min=dist( pop(i), pop(j) ); 
				e[0]=Index(pop(i)) ; 
				e[1]=Index(pop(j));
			}
		}

	}
	return e;
}

void Steck:: print() {
	Point *p=top;
	printf("%s %d","Size of stack  ", size());
	while (p)
	{
		p->print();
		p = p->Get();
	}
	
	p = NULL;
}