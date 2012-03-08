
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <float.h>
#include "Struct.h"
#include "List.h"

using namespace std;

HMODULE	hLib;

Empty		 clear;
IsEmpty		 isEmpty;
Correct		 correct;
Set			 set;
Intersection inter;
Print		 print;


HMODULE InitPointers() {

		hLib = LoadLibrary(TEXT("DllSection.dll"));	
		if(!hLib)		return NULL;	
		clear	= (Empty)GetProcAddress(hLib, "Empty");
		isEmpty	= (IsEmpty)GetProcAddress(hLib, "IsEmpty");
		correct	= (Correct)GetProcAddress(hLib, "Correct");
		set	= (Set )GetProcAddress(hLib, "Set");
		inter =  (Intersection)GetProcAddress(hLib, "Intersection");
		print =(Print)GetProcAddress(hLib, "Print");	
		return hLib;
	}

void roots(List& vars, double b, double c);

void SystemIntr(List& vars, int n);

void printrez(List& vars);

void main(){
int n=0;

InitPointers();
	
List vars;	
List:emptyL(vars);
	
printf("%s\t\t","Enter the amount of the equation");
scanf("%d",&n);

SystemIntr(vars,n);
printrez(vars);

deleteNumber(vars,size(vars)-1);

FreeLibrary(hLib);
getch();
exit(0);
}

void roots(List& vars, double b, double c){
	double x1,x2;
	if ( (b*b-4*c) >= 0 )
	{
		x1 = (-b+sqrt(b*b-4*c))/2;
		x2 = (-b-sqrt(b*b-4*c))/2;
		if (x1 <= x2)
		{
			add(vars,MININT,x1);	
			add(vars,x2,MAXINT);
		} 
		else {
			add(vars,MININT,x2);	
			add(vars,x1,MAXINT);
		}
	}
}
void SystemIntr(List& vars, int n){
	int kp = 0, kq = 0, siz = 0;

	for(int i=0; i<n; i++) {

		printf("%s\n","Enter the coefficients for the equation");
		printf("%s\t\t","p");
		scanf("%d",&kp);													
		printf("%s\t\t","q");
		scanf("%d",&kq);

		roots(vars,kp,kq);

		siz = size(vars);

		if( !isEmptyList(vars) )
		{
			Section *s = vars.head;
			Section *p = vars.tail;

			while(p!=s->previous)
			{ 
				if(!isEmpty(*inter(*s,*p)))	
				{
					add(vars, inter(*s,*p)->a, inter(*s,*p)->b);
				}	
				if(!isEmpty(*(inter(*s->previous,*p))))
				{
					add(vars, inter(*s->previous,*p)->a, inter(*s->previous,*p)->b);
				}
				p=p->next;
			}

			if(siz!=size(vars))
			{
				deleteNumber(vars,siz);
			}


			s=NULL;
			p=NULL;
		}
	}
}
void printrez(List& vars){
	Section *s = vars.tail;
	while(s!=NULL)
	{
	print(*s);
	s=s->next;
	}

s=NULL;
}