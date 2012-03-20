#include <iostream>
#include <fstream>
using namespace std;

int main() {

	int n,m,turn;   //height and length of rectangle

	ifstream fr ( "INPUT.TXT" );		//open file to read
	ofstream fw ( "OUTPUT.TXT" );		//open file to write

	if ( fr.fail() || fw.fail() ) {			//if file is not open correctly
		cerr << "Error when opening a file" << endl;   
	} 

	else {										//if file is open or create

		fr>>n>>m;								//read the data

		if  (1 <= n && n <= 32767 && 1 <= m  && m <= 32767 ) {   //if data are correct
			fw<<"Amount of rotation is ";	

			//if height is greater than the length, amount of rotation is equal 2*m -1, else   2*(n -1)
			n > m ?  fw<< 2*m -1 : fw<< 2*(n -1) ;
		}
		else cout<<"Data in file are incorrect"<<endl;
	}

	fr.close();  //close file
	fw.close();

	system("pause");
	return 0;
}