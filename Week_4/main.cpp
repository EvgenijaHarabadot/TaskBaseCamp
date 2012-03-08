#include <iostream>
#include <conio.h>
#include "Vector.h"

void main(){

 int n = 0; 
 						//ввід розміру вектора дотих пір поки він небуде коректним
	 printf("%s\t","Size");
	 scanf("%i",&n);
 
								//створення векторів з розміром n
	Vector *second = new Vector(n);
	Vector *first = new Vector(n);
	Vector *result = new Vector(n);

	first->enter();				//ввід коордтнат для першого вектора
	

	printf("\n\n\n%s","First vector"); //вивід даних про перший вектор
	first->print();

	printf("\n\n\n%s","Second vector"); //вивід даних про другий вектор
	second->print();

	printf("\n\n\n%s","Sum of first and second vectors");//обчислення і вивід суми двух векторів,що задані як параметр
	result->sum(*first,*second);	
	result->print();

	printf("\n\n\n%s","Subtraction of first and second vectors");//обчислення і вивід різниці двух векторів,що задані як параметр(від першого віднімається другий)
	result->subtraction(*first,*second);
	result->print();

	printf("\n\n\n%s","Multiplication of first and second vectors");//обчислення і вивід скалярного добутку двух векторів,один з яких заданий як параметр
	printf("\n%f",first->multiplication(*second));


	Natur *nat = new Natur(n);  //створюемо вектор цілих чисел, n-розмірність	

	nat->enter();			//задаємо значення координат вектора цілих чисел

	printf("\n\n%s\t","Mod N= "); // n-кратність на що перевіряємо
	scanf("%i",&n);

	first->mod(*nat,n);		// утворюємо перший вектор як залишок від ділення вектора цілих чисел на n
	printf("\n\n%s\n","Vector Mod N ");
	first->print();			//виводим результат


	printf("\n\n%s %f","cos between two vectors  ",first->angle(*nat)); //обчислюэмо косинус кута мж векторами

	delete first;   first=NULL;		 //видалення памяті з під обєктів 
	delete second ; second=NULL;
	delete result;  result=NULL;
	delete nat;     nat=NULL;
	getch();
	exit(0);
}