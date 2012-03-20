
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	unsigned int sum = 0;   //sum of  digits in number
	char ch;


	ifstream fr ( "INPUT.TXT" );		//open file to read
	ofstream fw ( "OUTPUT.TXT" );		//open file to write

if ( fr.fail() || fw.fail() ) {			//if file is not open correctly
cerr << "Error when opening a file" << endl;   
} 
else {										//if file is open or create

	while ( fr.get(ch) && ! fr.fail() )	{ //reads and verifies numbers

		if ( ch >=48 && ch <= 57 ) {
			sum += (ch-48);					//if number is divided to 3 then sum of digits this number also is divided to 3
		} 
		else {
			cout<<"This is not a number"<< endl; 
			sum = -1; 
			break;
		}
	}	


	if ( sum != -1 ) {
		if ( (sum % 3) == 0 )	//if number is divided to 3 then second player wins			
			fw<<"Win second";			
		else					//else if first player wants win, he must take remainder 
			fw<<"Win first if take"<<" "<<(sum % 3);	
	}
}

	fr.close();  //close file
	fw.close();

	system("pause");
	return 0;
}