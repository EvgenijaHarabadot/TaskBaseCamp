#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include<string>
#include <ctime> 
using namespace std;
														//��������� �������: ����� �� ��������
struct vocabulary{
char word[20];
char translation[20];
char f;
vocabulary(char c1[20],char c2[20],char f){
strcpy(word,c1);
strcpy(translation,c2);
f=f;
}
};

int main(){												
vector<vocabulary>voc;
int r;
printf ("%s","Enter the amount of words   ");				//��� �����
scanf("%i",&r);
char a[20],n[20];
for(int i=(int)0;i<(int)r;i++){
fflush(stdin);
	printf("%s %i\n","Record",i+1);
	printf("Word "); gets(a);
	printf( "Translation ");gets(n);
	voc.push_back(vocabulary(a,n,'t'));
}
char y[1];
printf("Do you want clear the window? (y/n)");           //�������� ������ ��� �������� "�"
scanf("%s",y); if(strcmp(y,"y")==0) system("cls");
printf ("%s","Enter the amount of question   ");		//���� ��� ��� ���������
scanf("%i",&r);
double rez=0;
srand( time(NULL)); 

if (r>voc.size()) {r=voc.size();}
														//�������� ����������� �������� �� ��������� �������

printf("\n\n%-5s %-5s\n","Word","Translation ");
int i=0;
while( i!=r)
{fflush(stdin);
int k=rand()%voc.size();
	if(voc[k].f!='f'){
		if(k>=0 && k<voc.size()){
		printf("%s %s",voc[k].word,"   "); gets(a); voc[k].f='f';
			if(strcmp(voc[k].translation,a)==0) { rez+=(double)1;}
		}
		else {printf("%s %s",voc[i].word,"   "); gets(a); voc[k].f='f';
			if(strcmp(voc[i].translation,a)==(int)0) { rez+=(double)1;}
		}
	++i;
	}

}




rez=(rez/r)*(double)100;
printf("%4.2lf %%",rez);								//���� ����������
getch();
exit(0);
}