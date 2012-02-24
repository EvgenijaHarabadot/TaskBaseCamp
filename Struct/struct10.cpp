#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include<string>
using namespace std;
																		//структура опису автомобіля
struct Avto{
char brend[10];
char number[10];
int year;
double run;
Avto(char b[],char n[],int y, double r){
strcpy(brend,b);
strcpy(number,n);
if (y>(int)0&&y<(int)2013) year=y;else year=2000;
run=fabs(r);
}
};

struct Information{													//структура даних марки , кількості маши даної марки та пробігу
char brend[10];
int in;
double run;
Information(char b[],int y, double r){
strcpy(brend,b);
in=abs(y);
run=fabs(r);
}
};




void sortYear(vector<Avto> &car){									//метод сортування за роками випуску
	Avto temp(" "," ",(int)1,(double)1);
	bool p=true;
do{
	p=false;
	for (int i=(int)0;i<(car.size()-(int)1);i++){
		if( car[i].year<car[i+1].year)
		{
		temp=car[i]; 
		car[i]=car[i+1];
		car[i+1]=temp;
	p=true;	}
	}
}
while(p);
}
//void sortBrend(vector<Avto> &car){								//допоміжне сортування за маркою машини
//	Avto temp(" "," ",(int)1,(double)1);
//	bool p=true;
//	do{p=false;
//	for (int i=(int)0;i<(car.size()-(int)1);i++){
//		if( strcmp(car[i].brend,car[i+1].brend)>0)
//		{
//		temp=car[i]; 
//		car[i]=car[i+1];
//		car[i+1]=temp;
//	p=true;	}
//}
//	}
//while(p);
//}







void brendRun(vector<Information> &info,Avto c){			//визначення середнього пробігу для кожної марки
int f=0;	
for(int i=(int)0;i<info.size();i++){
		if(strcmp(info[i].brend,c.brend)==0)	f=i;
		else f+=(int)0;
}

if (f==(int)0){
	info.push_back(Information(c.brend,(int)1,c.run));
}
else {info[f].in+=(int)1; info[f].run+=c.run;}

}

int main(){
vector<Avto>car;
vector<Information>info;
int x=0,y;
printf ("%s","Enter the amount of car    ");				//ввід даних
scanf("%i",&x);
printf("%s\n","Enter the data of car ");
char b[20],n[20];
double r;
for(int i=(int)0;i<(int)x;i++){
fflush(stdin);
	printf("%s %i\n","Car",i+1);
	printf("Brend "); gets(b);
	printf( "Number  ");gets(n);
	printf( "Year  "); scanf ("%i",&y);
	printf( "Run ");scanf ("%lf",&r);
	car.push_back(Avto(b,n,y,r));
}

sortYear(car);												//сортування та вивід даних
printf("\n\n%-20s %-20s %-5s %-5s\n","Brend","Number ","Year  ","Run ");
for(int i=(int)0; i<car.size();i++){
printf("%-20s %-20s %-5i  %4.2lf\n", car[i].brend,car[i].number,car[i].year,car[i].run);
}
//sortBrend(car);
info.push_back(Information("0",(int)0,(double)0)); 
for(int i=(int)0; i<car.size();i++){
brendRun(info,car[i]);										//вивід даних по середньому пробігу
}
double ser=(double)0;
printf("\n\n%-20s  %-5s\n","Brend" ,"Run ");
for(int i=(int)1; i<info.size();i++){
	ser=info[i].run/info[i].in;
	printf("%-20s   %4.2lf\n", info[i].brend,ser);
}


getch();
exit(0);

}
