#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#define k 5
using namespace std;
/*Структура що описує положення прямокутника(!розміщеного паралельно осям координат)
двома протилежними вершинами*/
struct Point{
double x;
double y;
double z;
double w;
};

void enter(Point points[k],int r){				//метод що забезпечує увід даних
int i;
	for( i=(int)0;i<r;i++){
		double d=(double)0,p=(double)0,f=(double)0,m=(double)0;	
		printf("%s %i\n", "Rectangle ",i+(int)1);
		printf("%s \n ", "Enter top left vertex");
		printf("%s ", "X1 ");scanf ("%lf",&d);
		printf("%s ", "Y1 ");scanf ("%lf",&p);
		printf("%s \n", "Enter bottom right vertex");
		printf("%s ", "X2 ");scanf ("%lf",&f);
		printf("%s ", "Y2 ");scanf ("%lf",&m);
		points[i].x=d;points[i].y=p;points[i].z=f;points[i].w=m;
	}
}
void print(Point points[k],int r){				//метод що забезпечує вивід даних
int i;
	printf("\n\n %-10s %-10s %-10s %-10s\n","X1 ","Y1 ","X2 ","Y2 ");
	for( i=(int)0;i<r;i++){
		printf(" %-10.2lf %-10.2lf %-10.2lf %-10.2lf\n",points[i].x, points[i].y, points[i].z,points[i].w);
	}
}

void sort(Point d[k],int r){				 //метод сортування за лівою координатою
	Point temp;
bool p=true;
	do{p=false;
		for (int i=(int)0;i<r-1;i++){
			if (d[i].x>d[i+1].x){
			temp=d[i]; 
			d[i]=d[i+1];
			d[i+1]=temp;
			p=true;	
			}
		}
	}
	while(p);
}

void min(Point d[k],int r){					//метод визначення та виведення на екран найбільшої та 
											//	найменшої площі прямокутників
double s,dd,min=(double)0,max=(double)0;
//dd=sqrt((d[0].x-d[0].z)*(d[0].x-d[0].z)+(d[0].y-d[0].w)*(d[0].y-d[0].w));
s=abs(d[0].x-d[0].z)*abs(d[0].y-d[0].w);
//s=((double)1/4)*dd*(sqrt(((double)1/4)*dd*dd));
min=s;
max=s;
	for(int i=(int)0;i<r;i++){
		//dd=sqrt((d[i].x-d[i].z)*(d[i].x-d[i].z)+(d[i].y-d[i].w)*(d[i].y-d[i].w));
		//s=((double)1/4)*sqrt((double)3/4)*dd*sqrt((double)(((double)1/4)*dd*dd));
		s=fabs(d[i].x-d[i].z)*fabs(d[i].y-d[i].w);	
		if(s<min){min=s;}
		if(s>max){max=s;}
	}

cout<<" Min square = "<<min<<" Max square = "<<max;
}

int main(){
int r=0;
printf ("%s","Enter the amount of records   ");
scanf("%i",&r);
if (r>k)r=k;
Point points[k];									//створення масиву/вектора структур
enter(points,r);									// ввід даних
sort(points,r);										//сортування за лівою координатою
print(points,r);									//вивід відсортованих даних
min(points,r);										// знаходження найменшої та найбільшої площі

getch();
exit(0);											//коректне завершення роботи програми

}