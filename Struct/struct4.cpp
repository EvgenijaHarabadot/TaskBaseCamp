#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
										//опис структури
struct Key{                                 
char k[20];
char d[40];
Key(char c1[],char c2[]){
strcpy(k,c1);
strcpy(d,c2);
}
};
										//метод сортування за ключем
void sort(vector<Key> &d,int n){
Key temp("\n","\n");
	bool p=true;
do{p=false;
	for (int i=(int)0;i<n-(int)1;i++){
		if (strcmp(d[i].k,d[i+1].k)>0){
		temp=d[i]; 
		d[i]=d[i+1];
		d[i+1]=temp;
		p=true;	
		}
	}
}
while(p);
}
										//перевірка та додавання нового елемента в вектор
void add(vector<Key> &d,Key d1,int n){
	if (strcmp(d1.k,d[n-1].k)>=(int)0){
		d.push_back(d1);}else printf("%s %s %s %s","Entered an element",d1.k,d1.d, "destructs order \n");
}
										//метод виводу даних на екран
void print(vector<Key> set){
printf("\n%-25s %-20s\n","Key", "Value");
for( int i=(int)0;i<(int)set.size();i++){
printf("%-25s %-20s\n",set[i].k, set[i].d);
	}
}




int main(){
vector <Key> set;

int r=(int)0;
printf ("%s","Enter the amount of sets    ");
scanf("%i",&r); 
printf("\n%s\n","Enter the key and value ");
char  a[20],n[40];
for(int i=(int)0;i<(int)r;i++){
	fflush(stdin);
	 printf("%s %i \n","Set ",i+1);
	printf("Key: ");
	 gets(a);
	printf("Value :");
	gets(n);
	set.push_back(Key(a,n));
 }

sort(set,r);

print(set);

printf("\n%s\n","Enter the two new sets "); /*спроба увести два нових записа, 
											вони додаються якщо непорушують відсортованість масиву*/
											
for(int i=(int)0;i<(int)2;i++){
	printf("%s %i\n","Set ",i+1);
	printf("%s ", "Key  ");
	 gets(a);
	printf("%s ", "Value  ");
	 gets(n);
	Key k1(a,n);
	add(set,k1,set.size());
	}


print(set);

getch();
exit(0);
}
