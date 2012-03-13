#include <iostream>
#include "stdafx.h"
#include "Section.h"
using namespace std;
extern "C"
{


	DLLexport void Empty (Section &s) {
		s.empty = true;
		s.a = 0;
		s.b = 0;	
	}


	DLLexport bool IsEmpty (Section &s) {
		return s.empty;
	}

	
	DLLexport bool Correct (double a,double b) { 
		 return (a >= b);	//чи правильно розташовані кінці відрізка
	}

	DLLexport void Set (Section &s, double a, double b) {
		if ( ! Correct(a,b) )      //якщо значення коректні присвоюємо їх відрізку
		{
			s.a = a;
			s.b = b;
			s.empty = false;
		}
		else s.empty = true;
	}

	DLLexport Section* Intersection ( Section &t1, Section &t2) {
		Section* s = new Section;
		if ( ! Correct(t1.a,t2.b) )                   //перевіряємо чи відрізок t1 має перетин з t2
		{
			if (! Correct(t2.a,t1.b))					
			{
				Set(*s, max(t2.a,t1.a), min(t2.b,t1.b)); 
			} 
			else Empty(*s);
		} 

		else Empty(*s);
		return s;	
	}

	DLLexport void Print (Section &s) {     //MININT і MAXINT позначають межі визначення, вони символізують - і + безмежнічть (виводиться +/-*) 
		if (s.a == MININT)
		{
			printf("%s %lf %s"," ( -*  ," ,  s.b, " ) ");
		}
		else	if (s.b == MAXINT)
		{
			printf("%s %lf %s"," (  " ,  s.a, ", +* ) ");
		}
		else
			printf("%s %lf %s %lf %s"," (  ",s.a ," , ",  s.b, " ) ");

	}	

}
	
	
	
	


