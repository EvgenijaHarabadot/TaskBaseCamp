#include <iostream>
#include <conio.h>
#include <stdarg.h>

#define G 1
using namespace std;
/* ��������� ������`������ ������*/

				//���������� ���� �������� ������
struct element{              
	int i;													
	element *next;					                               
	element *previous;				

};
				//���������� ������ 
struct list {
	element *head;   //�������� �� ������ ������ (n-� �������)
	element *tail;   //�������� �� ���� (0-� �������)
};

//��������� ������� ������
void empty (list &l) {                  
	l.head = NULL;
	l.tail = NULL;
}

//�������� �� ������ ������ : �������� ������ ���� ������
bool isEmpty (list &l){                
	return (l.head == NULL);
}

//������� �������� � ������
int size (list &l){
	element *e = l.tail;
	int i = 0;
	while (e != NULL)
	{  // ������� ������ �������
		++i;
		e=e->next;
	}
	e = NULL;
	return i;
}

//������� ������� �� �������
element* get(list &l,int i){
	if(i>=0 && i<size(l))
	{ //�������� ������ ��������
		element *d;
		if(i<=size(l)/2)
		{	//������ � ������
			d=l.tail;
			while (i)
			{				
				d=d->next;
				--i;
			}
			return d;
		}
		else
		{
			d=l.head;	
			int n=size(l)-i;//������ � ������
			while (n)
			{				
				d=d->next;
				--n;
			}
			return d;
		}

	}
	else  return NULL;
	d=NULL;
}

//��������� �������� � ����� ������ 
void add(list &l,int i){
	element *e1 = new element();  //����� ������� ���� �������� �� ������
	e1->i = i;
	e1->next = NULL;
	e1->previous = NULL;			//���� �� ������ ������(0) � ������
	if ( isEmpty(l) ) 
	{
		l.head = e1;
		l.tail = e1;
	}
	else 
	{		// ���� �������� � ������ ��� �: ������ ������ ������� � ����� � ���������� ������ ������
		l.head->next = e1;
		e1->previous = l.head;
		l.head = e1;
	}
	e1=NULL;
}

//��������� �������� � ������� �������
void add(list &l,int n,int i){  //n-����� ������� (� ����), �- �������� ����
	element *e1=new element();  // ����� �������
	if(isEmpty(l))
	{			//���� �� ������ ������(0) � ������
		l.head=e1;	
		l.tail=e1;
		e1->i=i;
		e1->next=NULL;
		e1->previous=NULL;
	}
	else
	{
		if(n<size(l)) 
		{
			element *e=get(l,n);
			e1->next=e;
			e1->previous=e->previous;
			e1->previous->next=e1;
			e1->next->previous=e1;
			e1->i=i;
		} 
		else 
		{
			if(n == size(l))
			{
				add(l,i);
			}
		}
	}
	e1=NULL;
}

//��������� �������� � ������� ������ 
void addFirst(list &l,int i){
	element *e1=new element();
	e1->i=i;
	e1->next=NULL;
	e1->previous=NULL;
	if(isEmpty(l))
	{
		l.head=e1;
		l.tail=e1;

	}
	else 
	{
		l.tail->previous=e1;
		e1->next=l.tail;
		l.tail=e1;
	}
	e1=NULL;
}

//������� � ������ ������� ���������. n-����� ������ ���� ���������
void addAll(list &l,int n,...){
	va_list p;					//���������� ��������� �� ������ ���������
	va_start(p,n);				//������������ ��������� �� ������ ����� �� ���������� ������� ����� ������� ���������	

	for(int j=0;j<n;++j)
	{
		add(l,(int)va_arg(p,int)); //���� ��������� 
	}
	va_end(p);                     //���������� ������ � ����������
}

//��������� ������� ��������
void deleteFirst(list &l){
	if(!isEmpty(l)){
		if(l.tail->next==NULL && l.head->previous==NULL){
			element *d=l.tail;
			empty(l);
			delete d;}
		else{
			element *d=l.tail;
			l.tail=l.tail->next;
			l.tail->previous=NULL;
			delete d;
		}
	}
}

//��������� ��������� ��������
void deleteLast(list &l){
	if(!isEmpty(l)){
		if(l.tail->next==NULL && l.head->previous==NULL){
			element *d=l.tail;
			empty(l);
			delete d;}
		else{
			element *d=l.head;
			l.head=l.head->previous;
			l.head->next=NULL;
			delete d;
		}
	}
}

//��������� ��� �������� ������
void deleteAll(list &l){
	int n=size(l);
	for(int i=0;i<n;++i)
	{
		deleteFirst(l);
	}

}

//��������� �� ������� ��� ���������
void deleteElement(list &l,int i,element* (*f)(list &,int)){
	if((*f)(l,i)!=NULL) {
		element *d =(*f)(l,i);
	if (d->next==NULL) deleteLast(l); else
		if (d->previous==NULL) deleteFirst(l); else{
			d->previous->next=d->next;
			d->next->previous=d->previous;
			delete d;
		}
	}
}

//��������� �������� �������� � ������� n z
void set(list &l, int n,int z=0){
	if(get(l,n)!=NULL)	{			//���� ������� � ����� ������� ����
		get(l,n)->i=z;
	}
}

//���������� �������� � ������� ���������
element* search(list &l, int n){
	if(!isEmpty(l))	{
		element *t=l.tail;
		int i=0;
		while (t->next!=NULL){
			if(t->i==n) return get(l,i);
			t=t->next;
			++i;
		}
	}
	return NULL;
}

//���� ������� �������� ������
void print(list &l){
	element *p=l.tail;
	while(p!=NULL)
	{
		printf("%d %s",p->i," ");
		p=p->next;
	}
}





int main() {

	list vars;													// ���������� ������ ������
	empty(vars);												// ��������� ������� ������

	int n=0,r=0,action=1;

	printf("%s %s %s %s %s %s %s %s\n","0- Exit; ","1- Add first; ","2- Add last; ",
		"3- Add to position","4- Set the value; ","5- Get the value;","6-Delete by value; "," 7-Delete by number");


	while (action!=0){
		printf("\n%s\t\t","Choose the action");
		scanf("%d",&action);
		switch(action){
		case 0: break;
		case 1:																	//��������� �������� � �����  ������
			printf("%s\t","Enter the amount of element");
			scanf("%d",&n);
			for(int i=0;i<n;++i)
			{
				scanf("%d",&r);													
				add(vars,r);												      
			}
			printf("\n%s ","List: ");
			print(vars);
			printf("\n%s %d\n","Size of list is  ",size(vars));
			break;
		case 2:																	//��������� �������� � �����  ������
			printf("%s\t","Enter the amount of element"); 
			scanf("%d",&n);
			for(int i=0;i<n;++i)
			{
				scanf("%d",&r);													
				addFirst(vars,r);												          
			}
			printf("\n%s ","List: ");
			print(vars);
			printf("\n%s %d\n","Size of list is  ",size(vars));
			break;
		case 3:																//���������� �������� � ������ �������(� ����)
			printf("%s\t","Enter the position of element and value");		
			scanf("%d",&n);
			scanf("%d",&r);
			add(vars,n,r);
			print(vars);
			break;
		case 4:																//������������ �������� ��� �������� ��������
			printf("%s\t","Enter the number of element and value"); 
			scanf("%d",&n);
			scanf("%d",&r);
			set(vars,n,r);
			printf("\n%s %d %s %d %s\n","Set value ", r," for ", n ," element: ");
			print(vars);
			break;

		case 5:																//��������  �������� �� ������
			printf("%s\t","Enter the number of element "); 
			scanf("%d",&n);
			if(get(vars,n)!=NULL){
				printf("\n%s %d\n","Value of  element  ",get(vars,n)->i);						
			}
			break;

		case 6:																//���������  �������� �� ������� ���������
			printf("%s\t","Enter the  value of element  "); 
			scanf("%d",&n);
			deleteElement(vars,n,search);
			printf("\n%s ","After delete  : ");
			print(vars);
			break;
		case 7:																//��������� �������� �� �������
			printf("%s\t","Enter the  value of element  "); 
			scanf("%d",&n);
			deleteElement(vars,n,get);
			printf("\n%s ","After delete  : ");
			print(vars);
			break;

		default:															//������������ ������� � ������ ������� ���������
			addAll(vars,3,1,2,3);
			addAll(vars,6,1,2,3,4,5,6);
			printf("\n%s ","List: ");
			print(vars); 
			deleteAll(vars);
printf("\n%s %d\n","Size of list after delete all is  ",size(vars));
		}
	}

	getch();
	exit(0);
}