#include"Sequence.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	
	Sequence dna("dna.txt");
	cout <<"Total: "<< dna.length() << endl;
	cout << "A: " << dna.numberOf('A') << endl << "C: " << dna.numberOf('C') << endl;
	cout << "G: " << dna.numberOf('G') << endl << "T: " << dna.numberOf('T') << endl;
	string longestconsecutive=dna.longestConsecutive();
	cout << longestconsecutive << endl;
	string longestrepeated = dna.longestRepeated();
	cout << longestrepeated << endl;

	return 0;

}
