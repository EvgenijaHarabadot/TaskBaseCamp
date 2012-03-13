#ifndef DllHeader
#define DllHeader
#define DLLexport  __declspec(dllexport)
#include <iostream>

extern "C" {
// description of the structure; the end segments and the box that indicates whether empty segment (empty-true, otherwise-false)
struct Section {

double a,b;
bool empty;

};

DLLexport void Empty (Section &s);							 // function that puts the end of the segment to zero and  flag true				
DLLexport bool IsEmpty (Section &s);						 //function returns a flag a segment is empty or not 
DLLexport bool Correct (double a, double b);				 //function checks or properly set the end of the segment
DLLexport void Set (Section &s, double a, double b);		 // sets the ends of the segment
DLLexport Section* Intersection ( Section &t1, Section &t2); //looks for an intersection of two segments
DLLexport void Print (Section &s);							 //prints data of the segment
}

#endif