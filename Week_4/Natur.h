class Natur{

unsigned int sizeN;			// ����� �������, �������� � ������� ������
	int *coordN;		//���������� ��������� �� ������, �� ���� ���������� � ������ ���� int


public:	
	friend class Vector; //������� � ������ �������,�� ����������� �  ����� doule. ����� ����� ����� ����������� �� ��� ���� ���� � ������
	Natur();			//����������� ��� ���������
	Natur(int& n);		//����������� � ����������,�� ���� ����� �������
	Natur (const Natur &a); //����������� ����������
	~Natur();			// ����������
	void enter();	//��� ���������
	int check(int& n);
};


Natur:: Natur(){ 
	sizeN=3;
	coordN=new int[sizeN]; 
		if(coordN!=NULL){
	for(int i=0;i<sizeN;++i)
		coordN[i]=i;	
	printf("\n%s\n","Created vector  with size 3 " );
		}
		else {printf("%s","Error"); exit(1);}
}

Natur:: Natur(int& n){
	sizeN=check(n);
	coordN=new int[sizeN];
	if(coordN!=NULL){
	for(int i=0;i<sizeN;++i)
		coordN[i]=i;	

}
	else {printf("%s","Error"); exit(1);}
}

Natur:: Natur(const Natur &a ){
	this->sizeN=a.sizeN;
	this->coordN=new int[sizeN]; 
	if(coordN!=NULL){
	for(int i=0;i<sizeN;++i){
		this->coordN[i]=a.coordN[i];
	}
	}
	else {printf("%s","Error"); exit(1);}
}

Natur:: ~Natur(){
	if (coordN!=NULL){
	delete[] coordN;  //��������� ������ � �� ������
	}	
	coordN=NULL;
}



void Natur:: enter(){
	
	printf("\n\n%s\n","Enter the coordinates nature vector");
	for (int i=0;i<sizeN;++i){
		scanf("%i",&coordN[i]);       //���������� ����� ������� ��������� 

	}
}

int Natur::check(int& n){
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