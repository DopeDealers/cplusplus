#include <iostream>
#include <string>
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

	// or return 0;
	// i like to pause it just from my
	// small amount of learning so i can debug if i need to!
	system("pause>0");
}
