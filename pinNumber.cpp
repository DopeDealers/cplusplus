#include <string>
#include <iostream>
using namespace std;

int main()
{
	int pinNumbers[4] = {},
	tempPinNumberArray[4] = {};
	int errorCounter = 0;
	string errorPinChecking, tempPinNumbers;
	cout << "Please provide us with a pin to use!" << endl << ">";
	cin >> tempPinNumbers;
	cout << tempPinNumbers.length();

	while (tempPinNumbers.length() != 4)
	{
		cout << "Please provide us with a pin to use!" << endl << "> ";
		cin >> tempPinNumbers;
	}
	pinNumbers[0] = stoi(tempPinNumbers) / 1000 % 10,
	pinNumbers[1] = stoi(tempPinNumbers) / 100 % 10,
	pinNumbers[2] = stoi(tempPinNumbers) / 10 % 10,
	pinNumbers[3] = stoi(tempPinNumbers) % 10;
	do
	{
		system("cls");
		cout << "Enter your pin." << endl << "> ";
		cin >> errorPinChecking;
		tempPinNumberArray[0] = stoi(errorPinChecking) / 1000 % 10,
		tempPinNumberArray[1] = stoi(errorPinChecking) / 100 % 10,
		tempPinNumberArray[2] = stoi(errorPinChecking) / 10 % 10,
		tempPinNumberArray[3] = stoi(errorPinChecking) % 10;

		if (tempPinNumberArray[0]<<tempPinNumberArray[1]<<tempPinNumberArray[2]<<tempPinNumberArray[3] != pinNumbers[0]<<pinNumbers[1]<<pinNumbers[2]<<pinNumbers[3])
			errorCounter++;
	} while (errorCounter < 3 && tempPinNumberArray[0] << tempPinNumberArray[1] << tempPinNumberArray[2] << tempPinNumberArray[3] != pinNumbers[0] << pinNumbers[1] << pinNumbers[2] << pinNumbers[3]);

	if (errorCounter < 3) {
		cout << endl << "Your pin was " << pinNumbers[0] << pinNumbers[1] << pinNumbers[2] << pinNumbers[3] << endl;
		cout << endl << "Loading the Application!" << endl;
		return 0;
	} else {
		cout << endl << "Your pin is incorrect. exiting app" << endl;
		return 0;
	}

	system("pause>0");
}
