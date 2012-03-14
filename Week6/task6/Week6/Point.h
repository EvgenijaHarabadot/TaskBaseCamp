#include <iostream>

class Point { //description point

	double x,y;  //coordinates
	Point *pr;	//pointer to  previous element

public:

Point ();					 //constructor without parameters
Point (double x1, double x2);//constructor with parameters (value of coordinates)
Point(const Point &p);			//constructor copy
~Point ();					//destructor

void   Set (Point *e);		//method sets value of  previous element
Point* Get();				//method returns value of  previous element
double GetX();				//method returns value of  coordinate X
double GetY();				//method returns value of  coordinate Y
void   print ();			//outputs to  data about point
};

Point:: Point() {
x = 0;
y = 0;
pr = NULL;
}
Point:: Point (const Point &p) {
x=p.x;
y=p.y;
pr=p.pr;
}
Point:: Point (double x1, double x2) {
x = x1;
y = x2;
pr = NULL;
}
Point :: ~Point() {
	pr=NULL;
}
double Point:: GetX (){
	return x;
}
double Point:: GetY (){
	return y;
}
void Point:: Set (Point *e){
pr = e;
}
Point* Point:: Get(){
 return pr;
}
void Point:: print() {
printf("\n%s %lf %s %lf\n", "X: ", GetX(), "  Y: ",GetY());
}
