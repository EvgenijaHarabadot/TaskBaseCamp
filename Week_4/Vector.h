#include "Natur.h"

class Vector {

	unsigned  int size;			// розмір вектора, задається в головній прорамі
	double *coord;		//оголошення вказівника на вектор, що буде складатись зі зминих типу double

public:	
	Vector();			//конструктор без параметрів
	Vector(int& n);		//конструктор з параметром,що задає розмір вектора
	Vector (const Vector &a); //конструктор копиювання
	~Vector();			// деструктор
	double get(int i,bool b);				// метод повертає елемент вектора по заданому индексу
	void set(int i, double d);		//метод задання значення вектора по индексу
	void sum(Vector &a,Vector &b);			//обчислення суми двох векторів
	void subtraction(Vector &a,Vector &b);	//обчислення різниці двох векторів
	double multiplication(Vector &b,bool f); //обчислення скалярного добутку двох векторів
	void print();					//вивід розмірності вектора та його координати
	void enter();					//ввід координат
	void mod(Natur &nat,int n);    // задає вектор як залишок від ділення координат nat на n
	double angle(Natur &b);		//обчислює косинус кута між векторами
	int check(int& n);			//перевірка розміра вектора викликається в конструкторі з параметром та може бути використана в головній програмі 
};


void Vector::set(int i, double d) { //перший параметр номер елемента у векторі(починаючи з нуля), другий-значення
	if(i>=0 && i<size){ 				
		coord[i]=d;
	} 
	else printf("\n%s %i %s %f\n","Index is not correct in set method! Element" , i,"isnt equal ",d);
}

double Vector::get(int i,bool b=true ){			//номер елемента який необхідно повернути
	if(i>=0&& i<size){
		return coord[i];
	} 
	else {
		printf("\n%s\n","Index is not correct in get method! " );
	return b=false;		// значення що символізує про помилку
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
	delete[] coord;     //видалення память з під масиву
	}
	coord=NULL;
}


void Vector:: sum(Vector &a,Vector &b){
	if (a.size==b.size && this->size==a.size){     //перевіряємо чи вектори онакової розмірності
		for(unsigned int i=0;i<size;++i)
			coord[i]=a.coord[i]+b.coord[i];
	} 
	else printf("\n%s\n","We cannot add these vectors because they have different measurement");
}


void Vector:: subtraction(Vector &a,Vector &b){
	if (a.size==b.size && this->size==a.size){       //перевіряємо чи вектори онакової розмірності
		for(unsigned int i=0;i<size;++i)
			coord[i]=a.coord[i]-b.coord[i];
	} 
	else printf("\n%s\n","We cannot substrsct these vectors because they have different measurement");
}


double Vector:: multiplication(Vector &b,bool f=true){
	double mult=0;
	if (this->size==b.size){ 	                       //перевіряємо чи вектори онакової розмірності
		for(unsigned int i=0;i<size;++i)
			mult+=coord[i]*b.coord[i];
		return mult;}
	else {
		printf("\n%s\n","We cannot multiplicate these vectors because they have different measurement! ");}

	return f=false;                                    // значення що символізує про помилку
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
		scanf("%lf",&coord[i]);  //послідовний запис значень координат      
	      
	}
}

void Vector:: mod(Natur &nat,int n ){
	if (size==nat.sizeN && n!=0 ){       //перевіряємо чи вектори онакової розмірності
		for(unsigned int i=0;i<size;++i){
			coord[i]=nat.coordN[i]%n;
		} 
	}
	else printf("\n%s\n","We cannot change this vector because they have different measurement or MOD not correct");
}



double Vector:: angle(Natur &b){
	double mult=0,lengs=0,lengsB=0,cosA=0;						//довжини вектрів

	for(unsigned int i=0;i<size;++i){lengs+=pow(coord[i],2);}			//обчислення довжини вектора
	lengs=sqrt(lengs);

	for(unsigned int i=0;i<b.sizeN;++i){lengsB+=b.coordN[i]*b.coordN[i];}  //обчислення довжини вектора з цілих чисел
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
