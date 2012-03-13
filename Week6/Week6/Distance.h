
class Distance  { //class for definition method  search of distance between points

public:
	double dist (Point *p, Point *p1);

};

double Distance :: dist(Point *p,Point *p1){  //returns distance between points

	return sqrt(pow(p1->GetX() - p->GetX(),2) +pow(p1->GetY() -p->GetY(),2));

}



