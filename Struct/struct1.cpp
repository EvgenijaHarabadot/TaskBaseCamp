#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include<string>
#define k 10
using namespace std;
/*���������� ��������� �� ����� ������*/
struct Book{
char name[20];
char author[20];
char notes[40] ;
int year;
};
/*����� �� ������ � ����� �������� ��������� ������ ������ 
� ����� �� �� ����� ������ � ���������� �������*/
 void sortByAuthor(Book books[k],int r){
	Book temp;
	bool p=true;
	do{p=false;
		for (int i=(int)0;i<(r-(int)1);i++){
			if( strcmp(books[i].author,books[i+1].author)>0)
			{
			temp=books[i]; 
			books[i]=books[i+1];
			books[i+1]=temp;
			p=true;	
			}
		}
	}
	while(p);
}
/*����� �� ������ � ����� �������� ��������� ������ ������ 
� �������� �� ����� � �� ���� ����� �� 1970 ����*/
void Year(Book books[k],int r){ 
printf("\n\n%s\n\n","Books before 1970 years");
printf("%-20s %-20s %-7s %-10s\n","Author ","Name ","Year ","Notes");
	for (int i=(int)0;i<r;i++){
		if (books[i].year<(int)1970 ) 
		printf("%-20s %-20s %-7i %-10s\n",books[i].author, books[i].name, books[i].year, books[i].notes);
	}
}

int main(){          
int i,y,r;
Book books[k];
printf ("%s","Enter the amount of books    ");
scanf("%i",&r);
if(r>k)r=k;
printf("%s\n","Enter the data of books  (Author, Name, Year ,Notes)");
char not[40];
fflush(stdin);                                   //��� ���������� �����
	for( i=(int)0;i<r;i++){
		printf("%s %i\n","Book ",i+1);
		printf("Author "); gets(not);strcpy(books[i].author,not);
		printf( "Name  ");gets(not);strcpy(books[i].name,not);
		printf( "Year  ");scanf ("%i",&y);
		fflush(stdin);	printf( "Notes  "); gets(not);
		strcpy(books[i].notes,not);
		if(y>0&&y<2013) books[i].year=y; else books[i].year=1970;
	}
												//������ ������ ����������
sortByAuthor(books,r);
												//���� ������������ �����
printf("\n\n%-20s %-20s %-7s %-10s\n","Author ","Name ","Year ","Notes");
	for( i=(int)0;i<r;i++){
		printf("%-20s %-20s %-7i %-10s\n",books[i].author, books[i].name, books[i].year, books[i].notes);
	}
Year(books,r);									//������ ������ ������ ������ �� ����� �� 1970

getch();										//������� ����� � ��������
exit(0);

}