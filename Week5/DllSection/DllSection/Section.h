#ifndef DllHeader
#define DllHeader
#define DLLexport  __declspec(dllexport)
#include <iostream>

extern "C" {
// опис с труктури, кінці відрізків та прапорец, що вказує чи порожній відрізок (порожній-true ,інакше-false)
struct Section {

double a,b;
bool empty;

};

DLLexport void Empty (Section &s);							 // функція що ставить кінці відрізка в нуль і перемикає прапорець					
DLLexport bool IsEmpty (Section &s);						 //функція повертає значення прапорця, чи  відрізок не порожній
DLLexport bool Correct (double a, double b);				 //фнукція перевіряє чи ккоректно задані кінці відрізка
DLLexport void Set (Section &s, double a, double b);		 // задає значення кінців відрізка
DLLexport Section* Intersection ( Section &t1, Section &t2); //шукає перетин двох відрізків
DLLexport void Print (Section &s);							 //друкує відрізок 
}

#endif