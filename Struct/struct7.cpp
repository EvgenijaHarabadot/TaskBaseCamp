#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include<string>
#define k 3
using namespace std;
													//структура що описує автора назву видавництво та рік видання
struct Book{
char name[20];
char author[20];
char edition[20] ;
int year;
Book(char s1[20],char s2[],char s3[],int i){
strcpy(author,s1);
strcpy(name,s2);
strcpy(edition,s3);
if(i>(int)0&&i<(int)2013) year=i;else year=(int)2012;
}
};
 void sortByAuthor(vector<Book> &books){			//сортування за роком видання
	Book temp(" "," "," ",(int)1);
	bool p=true;
	do{p=false;
	for (int i=(int)0;i<(int)(books.size()-(int)1);i++){
		if( books[i].year<books[i+1].year)
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

void Subject(vector<Book> &books){					//визначення та вивід на екран інформації про книжки с/с++
printf("\n\n%s\n","Books about C/C++");
printf("%-20s %-20s %-7s %-10s\n","Author ","Name ","Year ","Edition");
for (int i=(int)0;i<(int)(books.size());i++){
	if (strstr(books[i].name,"C/C++")>0||strstr(books[i].name,"c/c++")>0) {
		printf("%-20s %-20s %-7i %-10s\n",books[i].author, books[i].name, books[i].year, books[i].edition);
	}
}
}



int main(){
int i,y;
int r;
vector<Book> books;									//ввід даних
printf ("%s","Enter the amount of books    ");
scanf("%i",&r);
printf("%s\n","Enter the data of books  (Author, Name, Edition, Year)");
char a[20],n[20],not[20];

for( i=(int)0;i<(int)r;i++){
fflush(stdin);
	printf("%s %i\n","Book ",i+(int)1);
	printf("Author "); gets(a);
	printf( "Name  ");gets(n);
	printf( "Edition  "); gets(not);
	printf( "Year  ");scanf ("%i",&y);
	books.push_back(Book(a,n,not,y));
}
	
sortByAuthor(books);											//виклик методу сортування
printf("\n\n%-7s %-20s %-20s  %-10s\n","Year ","Author ","Name ","Edition");
																//групування книжок за рокамим та вивід
printf("%-7i %-20s %-20s  %-10s\n",books[0].year, books[0].author, books[0].name, books[0].edition);
for(i=(int)1; i<books.size();i++){
	if(books[i].year==books[i-1].year){
printf("%-7s %-20s %-20s %-10s\n", "    ", books[i].author, books[i].name, books[i].edition);
	}
else printf("%-7i %-20s %-20s  %-10s\n", books[i].year, books[i].author, books[i].name, books[i].edition);
}
Subject(books);
getch();
exit(0);

}