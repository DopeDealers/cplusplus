#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;


int main() {
	// Single character string
	// can modify this char value
	char character = 't';
	// Single character string
	// cannot modify this char value
	const char _CHARACTER = 'f';
	// Full string character
	// cannot modify this char value
	const char _CHARACTERFULL[] = "Hello my name is character";
	// Full string character
	// can modify this char value
	char characterFul[] = "Hello my name is character also!";

	// A replacement to normal C code in c++ for char[] is the
	// library called string
	// this is a string var not loaded into memory and if you want to
	// load it into memory use curly brackets, same can be said for
	// any datatype
	string stringTest; // not loaded into memory
	// stringTest = "Hey" | cout << stringTest; > Hey
	string stringMemory{}; // loaded into memory

	// With string you can also set up arrays with it
	// like so
	string stringArray = { "Hello!", "!!" }; // stringArray[1] >> !!

	// A non modifiable string var would be set up like so
	const string stringConst = "Hello!! i cannot be modified";

	// quickly ill wrap this up and show all the other datatypes in c/c++
	int intTest; // intTest = 1;
	const int _INTTEST = 50; // cant be changed!
	bool boolTest; // boolTest = false;
	const bool _BOOLTEST = true;
	double doubleTest; // doubleTest = 7.56;
	const double _DOUBLETEST = 5.76;
	float floatTest; // floatTest = 7.98;
	const float _FLOATTEST = 3.6534;

	// Simple hello world
	// alternatively you can use \n to break the line!
	cout << endl << "Hello World!" << endl;

	// Modifiable int array and modify the first int in array
	int hi[2] = { 0, 1 };
	hi[0] = 56;
	cout << hi[0];
	
	// hey been a minute!
	// Vectors. better arrays :shrug:
	// allowed to store any int value in this
	// and use loops to get these values and or
	// use to .at(index) method
	// or like a typical array use brackets [index]
	vector<int> intVector{9,6,3,88};
	
	// simple usage case for a vector
	for (unsigned int i{0}; i < intVector.size(); i++)
		cout << intVector.at(i) << endl; // again you can do intVector[i];
	
	// Lets jump into 2d vectors. these are pretty awesome
	// allows you to have MULTIPLE arrays within the vector
	// to store more data sexily 
	vector<vector<int>> 2dVectorInt {
		{993,7673,76357},
		{9283,6363,832}
	};
	// here im just getting the first entry for both arrays and combining them on output
	// for each entry
	for (unsigned int j{0}; j < 2dVectorInt.at(0).size(); j++) {
		unsigned int firstToAdd{2dVectorInt.at(j)};
		unsigned int secondToAdd{2dVectorInt.at(j)};
		cout << (firstToAdd + secondToAdd) << endl;
	}
	
	

	// or return 0;
	// i like to pause it just from my
	// small amount of learning so i can debug if i need to!
	system("pause>0");
}
