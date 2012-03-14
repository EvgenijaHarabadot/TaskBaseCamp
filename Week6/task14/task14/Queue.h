#include "List.h"

class Queue : private List {

public:
	void empty ();				//creates empty list
	void clear ();				//deletes all element in list
	void print();				//outputs to  data about list
	bool enter ();				//enter data
	void odd();					//searchs odd element and deletes it
};

void Queue :: empty () {                  
	head = NULL;
	tail = NULL;
} 
void Queue:: clear() {

	if( !isEmpty() ) {
		Element *p = tail;
		while( p != NULL)
		{
			tail = tail->getP();
		if (tail) {
			tail->setN(NULL);
		}
			if(p) delete p; 
			p = tail;
		}

		p = NULL;	
	}
} 
void Queue:: print() {
	Element *p=head;
	printf("\n%s %d\n","Size of queue ", size());
	while (p)
	{
		printf("%s %d"," ",p->getX());
		p = p->getN();
	}
	
	p = NULL;
}
bool Queue:: enter () {
	int n,x;
	printf("\n%s","Enter the amount of records   ");
	scanf("%d",&n);
	if ( n > 0 ) {
		for (int i = 0; i < n; i++){
			scanf("%d",&x);
			add(x);
		}
		return true;
	}
	else return false;
}
void Queue:: odd () {
	Element *p=tail;
	if( !isEmpty() ) {
		while(p  &&  (p->getX())%2 == 0){
			p = p->getP();

		}
		if (p && index(p)!=-1) {
			List::clear ( index(p) ); 
			p = NULL;
		}
	}
}