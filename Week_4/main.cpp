#include <iostream>
#include <conio.h>
#include "Vector.h"

void main(){

 int n = 0; 
 						//��� ������ ������� ����� �� ���� �� ������ ���������
	 printf("%s\t","Size");
	 scanf("%i",&n);
 
								//��������� ������� � ������� n
	Vector *second = new Vector(n);
	Vector *first = new Vector(n);
	Vector *result = new Vector(n);

	first->enter();				//��� ��������� ��� ������� �������
	

	printf("\n\n\n%s","First vector"); //���� ����� ��� ������ ������
	first->print();

	printf("\n\n\n%s","Second vector"); //���� ����� ��� ������ ������
	second->print();

	printf("\n\n\n%s","Sum of first and second vectors");//���������� � ���� ���� ���� �������,�� ����� �� ��������
	result->sum(*first,*second);	
	result->print();

	printf("\n\n\n%s","Subtraction of first and second vectors");//���������� � ���� ������ ���� �������,�� ����� �� ��������(�� ������� ��������� ������)
	result->subtraction(*first,*second);
	result->print();

	printf("\n\n\n%s","Multiplication of first and second vectors");//���������� � ���� ���������� ������� ���� �������,���� � ���� ������� �� ��������
	printf("\n%f",first->multiplication(*second));


	Natur *nat = new Natur(n);  //��������� ������ ����� �����, n-���������	

	nat->enter();			//������ �������� ��������� ������� ����� �����

	printf("\n\n%s\t","Mod N= "); // n-�������� �� �� ����������
	scanf("%i",&n);

	first->mod(*nat,n);		// ��������� ������ ������ �� ������� �� ������ ������� ����� ����� �� n
	printf("\n\n%s\n","Vector Mod N ");
	first->print();			//������� ���������


	printf("\n\n%s %f","cos between two vectors  ",first->angle(*nat)); //���������� ������� ���� �� ���������

	delete first;   first=NULL;		 //��������� ����� � �� ����� 
	delete second ; second=NULL;
	delete result;  result=NULL;
	delete nat;     nat=NULL;
	getch();
	exit(0);
}