#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
															//Задання точки через три координати
struct Point{
double x;
double y;
double z;
Point(double d1,double d2,double d3){
x=d1;
y=d2;
z=d3;
}
};
															//метод що ввідить дані
void enter(vector<Point> &points){
int i,r=(int)0;
printf ("%s","Enter the amount of records   ");
scanf("%i",&r);
for( i=(int)0;i<(int)r;i++){
	double d=0,p=0,f=0;	
	printf("%s %i\n", "Point ",i+(int)1);
	printf("%s ", "X ");scanf ("%lf",&d);
	printf("%s ", "Y ");scanf ("%lf",&p);
	printf("%s ", "Z ");scanf ("%lf",&f);
points.push_back(Point(d,p,f));
}
}
void print(vector<Point> &points){							//метод що виводить дані
	int i;
	printf("\n\n %-10s %-10s %-10s\n","X ","Y ","Z");
	for( i=(int)0;i<points.size();i++){
	printf(" %-10.2lf %-10.2lf %-10.2lf \n",points[i].x, points[i].y, points[i].z);
}
}
															//сортування за координатою z
void sort(vector<Point> &d){
	Point temp((double)1,(double)1,(double)1);
	bool p=true;
	do{p=false;
	for (int i=(int)0;i<d.size()-(int)1;i++){
		if (d[i].z>d[i+1].z){
		temp=d[i]; 
		d[i]=d[i+1];
		d[i+1]=temp;
		p=true;	
		}
	}
}
while(p);
}

void min(vector<Point> &d){								//знаходження двох точок між якими ввідаль є мінімальною
double min=(double)0,max=(double)0,x1,y1,z1,x2,y2,z2;
int n1,n2;
min=sqrt(((d[0].x-d[1].x)*(d[0].x-d[1].x))+((d[0].y-d[1].y)*(d[0].y-d[1].y))+((d[0].z-d[1].z)*(d[0].z-d[1].z)));
x1=d[0].x; y1=d[0].y; z1=d[0].z;  x2=d[1].x; y2=d[1].y; z2=d[1].z; n1=1; n2=2;
for(int i=(int)0;i<d.size()-1;i++){
	for(int j=i+1;j<d.size();j++){
	max=sqrt(((d[i].x-d[j].x)*(d[i].x-d[j].x))+((d[i].y-d[j].y)*(d[i].y-d[j].y))+((d[i].z-d[j].z)*(d[i].z-d[j].z)));
		if(min>max){
		min=max; x1=d[i].x; y1=d[i].y; z1=d[i].z;  x2=d[j].x; y2=d[j].y; z2=d[j].z; n1=(i+1); n2=(j+1);
		}
	}
}
cout<<"min between  vertex "<<n1<<"("<<x1<<","<<y1<<","<<z1<<") and vertex "<<n2<<"("<<x2<<","<<y2<<","<<z2<<") ="<<min<<"\n";
}

int main(){

vector<Point> points;
enter(points);
sort(points);
print(points);
min(points);
getch();
exit(0);

}