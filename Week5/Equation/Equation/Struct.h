#ifndef DllHeader
#define DllHeader

struct Section {

double a,b;
bool empty;

Section *next;
Section *previous;
};



typedef void (*Empty) (Section &s);
typedef bool (*IsEmpty) (Section &s);
typedef bool (*Correct) (double a, double b);
typedef void (*Set) (Section &s, double a, double b);
typedef Section* (*Intersection) ( Section &t1, Section &t2);
typedef void (*Print) (Section &s);


#endif