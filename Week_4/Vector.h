#include "Natur.h"

class Vector {

	unsigned  int size;			// ����� �������, �������� � ������� ������
	double *coord;		//���������� ��������� �� ������, �� ���� ���������� � ������ ���� double

public:	
	Vector();			//����������� ��� ���������
	Vector(int& n);		//����������� � ����������,�� ���� ����� �������
	Vector (const Vector &a); //����������� ����������
	~Vector();			// ����������
	double get(int i,bool b);				// ����� ������� ������� ������� �� �������� �������
	void set(int i, double d);		//����� ������� �������� ������� �� �������
	void sum(Vector &a,Vector &b);			//���������� ���� ���� �������
	void subtraction(Vector &a,Vector &b);	//���������� ������ ���� �������
	double multiplication(Vector &b,bool f); //���������� ���������� ������� ���� �������
	void print();					//���� ��������� ������� �� ���� ����������
	void enter();					//��� ���������
	void mod(Natur &nat,int n);    // ���� ������ �� ������� �� ������ ��������� nat �� n
	double angle(Natur &b);		//�������� ������� ���� �� ���������
	int check(int& n);			//�������� ������ ������� ����������� � ����������� � ���������� �� ���� ���� ����������� � ������� ������� 
};


void Vector::set(int i, double d) { //������ �������� ����� �������� � ������(��������� � ����), ������-��������
	if(i>=0 && i<size){ 				
		coord[i]=d;
	} 
	else printf("\n%s %i %s %f\n","Index is not correct in set method! Element" , i,"isnt equal ",d);
}

double Vector::get(int i,bool b=true ){			//����� �������� ���� ��������� ���������
	if(i>=0&& i<size){
		return coord[i];
	} 
	else {
		printf("\n%s\n","Index is not correct in get method! " );
	return b=false;		// �������� �� �������� ��� �������
	}
}

Vector:: Vector(){ 
	size=3;
	coord=new double[size]; 
		for(int i=0;i<size;++i)
			coord[i]=i;	
		printf("\n%s\n","Created vector  with size 3 " );
}

Vector:: Vector(int& n){
	size=check(n);
	
	coord=new double[size];
	
		for(int i=0;i<size;++i)
			coord[i]=i;	

}

Vector:: Vector(const Vector &a ){
	this->size=a.size;
	this->coord=new double[size]; 
	
		for(unsigned int i=0;i<size;++i){
			this->coord[i]=a.coord[i];
		}
}

Vector:: ~Vector(){
	if (coord!=NULL){
	delete[] coord;     //��������� ������ � �� ������
	}
	coord=NULL;
}


void Vector:: sum(Vector &a,Vector &b){
	if (a.size==b.size && this->size==a.size){     //���������� �� ������� ������� ���������
		for(unsigned int i=0;i<size;++i)
			coord[i]=a.coord[i]+b.coord[i];
	} 
	else printf("\n%s\n","We cannot add these vectors because they have different measurement");
}


void Vector:: subtraction(Vector &a,Vector &b){
	if (a.size==b.size && this->size==a.size){       //���������� �� ������� ������� ���������
		for(unsigned int i=0;i<size;++i)
			coord[i]=a.coord[i]-b.coord[i];
	} 
	else printf("\n%s\n","We cannot substrsct these vectors because they have different measurement");
}


double Vector:: multiplication(Vector &b,bool f=true){
	double mult=0;
	if (this->size==b.size){ 	                       //���������� �� ������� ������� ���������
		for(unsigned int i=0;i<size;++i)
			mult+=coord[i]*b.coord[i];
		return mult;}
	else {
		printf("\n%s\n","We cannot multiplicate these vectors because they have different measurement! ");}

	return f=false;                                    // �������� �� �������� ��� �������
}

void Vector:: print(){
	printf ("\n%s %i\n%s", "Size of vector is ",size,"Vector: ");
	for (unsigned int i=0;i<size;++i){
		printf ("%f %s",coord[i]," ");
	}

}

void Vector:: enter(){
	
	printf("%s\n","Enter the coordinates ");
	for (unsigned int i=0;i<size;++i){
		scanf("%lf",&coord[i]);  //���������� ����� ������� ���������      
	      
	}
}

void Vector:: mod(Natur &nat,int n ){
	if (size==nat.sizeN && n!=0 ){       //���������� �� ������� ������� ���������
		for(unsigned int i=0;i<size;++i){
			coord[i]=nat.coordN[i]%n;
		} 
	}
	else printf("\n%s\n","We cannot change this vector because they have different measurement or MOD not correct");
}



double Vector:: angle(Natur &b){
	double mult=0,lengs=0,lengsB=0,cosA=0;						//������� ������

	for(unsigned int i=0;i<size;++i){lengs+=pow(coord[i],2);}			//���������� ������� �������
	lengs=sqrt(lengs);

	for(unsigned int i=0;i<b.sizeN;++i){lengsB+=b.coordN[i]*b.coordN[i];}  //���������� ������� ������� � ����� �����
	lengsB=sqrt(lengsB);

	for(unsigned int i=0;i<size;++i) mult+=coord[i]*b.coordN[i];
	if(lengs!=0 && lengsB!=0){
		cosA=mult/(lengs*lengsB);
	}
	return cosA;                                    
}

int Vector::check(int& n){
	if (n<0){
do
 {								
	 printf("%s\t","It is not correct value of size! Size:");
	 scanf("%i",&n);
 }
 while(n<0);
	}
return n;	
}
