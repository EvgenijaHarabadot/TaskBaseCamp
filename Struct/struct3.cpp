#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
											//Масив назв місяців
static string month[]={"January   ", "February  ","March     ", "April     ", "May       ", "June      ", "July      ", "August    ", "September ", "October   ","November  ", "December  "};
											//структура що описує роботу цеха
struct department{
int m_i;
double plan;
double fact;
double percent;
department(int m,double p,double f,double d){ //конструктор з параметрами
	if (m>0&&m<=12) m_i=m;else m_i=0;
	plan=fabs(p);							//забезпечення коректності даних(більше нуля)
	fact=fabs(f);
	percent=fabs(d);
}
};

											//метод сортування за відсотком виконання плану
 void sort(vector<department> &d,int n){
	department temp((int)1,(double )1,(double )1,(double )1);
	bool p=true;
do{p=false;
	for (int i=(int)0;i<n-(int)1;i++){
		if (d[i].percent<d[i+1].percent){
		temp=d[i]; 
		d[i]=d[i+1];
		d[i+1]=temp;
		p=true;
		}
	}
}
while(p);
}


int main(){
int i,r=(int)0;
printf ("%s","Enter the amount of records   ");
scanf("%i",&r);
vector <department> depart;
for( i=(int)0;i<r;i++){							//ввід даних та створення елемента вектора 
	int m=(int)0;
	double d=(double)0,p=(double)0,f=(double)0;	
	printf("%s ", "Month ");scanf ("%i",&m);
	printf("%s ", "Plane  ");scanf ("%lf",&p);
	printf("%s ", "Fact  ");scanf ("%lf",&f);
	d=(f/p)*100;
depart.push_back(department(m,p,f,d));
}

sort(depart,r);
												//вивід результатів
printf("\n\n%-10s %-10s %-10s %-10s\n","Month ","Plane ","Fact ","Percent");
for( i=(int)0;i<r;i++){
	cout<<month[(depart[i].m_i)-(int)1];
	printf(" %-10.2lf %-10.2lf %4.2lf %%\n",depart[i].plan, depart[i].fact, depart[i].percent);
}

getch();
exit(0);

}