#include <iostream>
#include <conio.h>
#include "Struct.h"

struct List {
	Section *head;
	Section *tail;
};



//��������� ������� ������
void emptyL (List &l) {                  
	l.head = NULL;
	l.tail = NULL;
}
//�������� �� ������ ������
bool isEmptyList (List &l) {                
	return (l.head == NULL);
}
//������� �������� � ������
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
//��������� �������� � ����� ������ 
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
//��������� � ���� ������� ��� ���������� ������ ����������
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

	delete l.head;
}


