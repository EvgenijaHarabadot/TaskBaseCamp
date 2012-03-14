#include <iostream>

class Element { //description unsigned number

	unsigned int x;  //unsigned number
	Element *pr;	//pointer to  previous element
	Element *next;	//pointer to  next element

public:
Element ();					 //constructor without parameters
Element ( int x1);		//constructor with parameters 
Element(const Element &p);		//constructor copy
~Element ();					//destructor
void all();

void  setP (Element *e);	//method sets value of  previous element
void  setN (Element *e);	//method sets value of  next element
Element*  getP();				//method returns value of  previous element
Element*  getN();				//method returns value of  next element
unsigned int getX();		//method returns value of  x

};


void Element :: all () {
	x = 0;
	pr = NULL;
	next = NULL;
}
Element:: Element() {
	all();
}
Element:: Element (const Element &p) {
	x = p.x;
	next = p.next; 
	pr = p.pr;
}
Element:: Element ( int x1) {
	all();
	if ( x1 >=0 ) x = x1;
}
Element :: ~Element() {
	pr = NULL;
	next = NULL;
}
unsigned int Element:: getX (){
	return x;
}
void Element:: setP (Element *e){
	pr = e;
}
void Element:: setN (Element *e){
	next = e;
}
Element* Element:: getP(){
	return pr;
}
Element* Element:: getN(){
	return next;
}
