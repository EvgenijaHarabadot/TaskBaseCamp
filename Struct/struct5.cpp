#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#define x 5
using namespace std;

struct Goods{									//створення структури що описує товар
double cost;	
double amount;
double syma;
char kod[10];
char name[20];
};
void sort(Goods d[]){							//метод сортування за кодом
	Goods temp;
	bool p=true;
do{p=false;
	for (int i=(int)0;i<(int)x-(int)1;i++){
		if (strcmp(d[i].kod,d[i+1].kod)>0){
		temp=d[i]; 
		d[i]=d[i+1];
		d[i+1]=temp;
	p=true;	}
}
	}
while(p);
}

int main(){                                     //задання кодів та вартостей (база)
	Goods good[x];
	strcpy(good[0].kod,"333"); good[0].cost=(double)100; 
	strcpy(good[1].kod,"222"); good[1].cost=(double)1;
	strcpy(good[2].kod,"dfg"); good[2].cost=(double)21;
	strcpy(good[3].kod,"qwe"); good[3].cost=(double)30;
	strcpy(good[4].kod,"111"); good[4].cost=(double)5;
	
int r=(int)0;									//ввід даних
printf ("%s","Enter the amount of records   ");
scanf("%i",&r);
for(int j=(int)0;j<(int)x;j++){
	strcpy(good[j].name," ");
	good[j].syma=0;
	good[j].amount=0;
}
for(int i=(int)0;i<(int)r;i++){
	char k[10],n[20];
	double a=(int)0;	
	int f=(int)0;
	fflush(stdin);
	printf("%s \n", "Kod ");gets(k);
	printf("%s \n", "Name  ");gets(n);			//перевірка чи є введений товар у базі
	printf("%s \n", "Amount  ");scanf ("%lf",&a);
	for (int j=(int)0;j<(int)x;j++){
		if (strcmp(good[j].kod,k)==0)  {good[j].syma+=good[j].cost*a; 
		strcpy(good[j].name,n); 
		good[j].amount+=a;
		f+=(int)1;
		} 
		else f+=(int)0;
	} 
	if(f==(int)0) printf("%s\n","Goods does not in set");
}

sort(good);
												//сортування та вивід результатів на екран
printf("%-10s %-10s %-10s %-10s\n", "Kod", "Name","Amount","Sum of cost");
for (int j=(int)0;j<(int)x;j++){
printf("%-10s %-10s %10.2lf %10.2lf\n", good[j].kod, good[j].name,good[j].amount,good[j].syma);
}


getch();
exit(0);
 }