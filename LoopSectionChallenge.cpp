
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	char checkForQuitChar{};
	char storePrintList{};
	int tempCinStorageForAdding{};
	vector<int> numberStorage{};
	
	do
	{
		cout << "\nP - Print numbers\nA - Add numbers\nM -  Display mean of number\nS -  Display the smallest number\nL - Display the largest number\nQ - Quit the program\nInput > ";
		cin >> storePrintList;
		
			switch (storePrintList)
			{
			case 'p':
			case 'P': {
				if (numberStorage.size() != 0) {
					cout << "Numbers: ";
					for (size_t i{ 0 }; i < numberStorage.size(); i++)
						cout << numberStorage.at(i) << " ";
				}
				else
					cout << "No numbers to print!" << endl;
				break;
			}
			case 'q':
			case 'Q': {
				checkForQuitChar = 'Q';
				cout << "Thanks for using my app!" << endl;
				break;
			}
			case 's':
			case 'S': {
				int tempS = numberStorage.at(0);
				if (numberStorage.size() != 0) {
					for (int i{ 0 }; i < numberStorage.size(); i++)
						if (tempS > numberStorage.at(i))
							tempS = numberStorage.at(i);
					cout << "The smallest number in the storage is: " << tempS << endl;
				}
				else
					cout << "Unable to calculate the smallest number in the list..\n";
				break;
			}
			case 'l':
			case 'L': {
				int tempL = numberStorage.at(0);
				if (numberStorage.size() != 0) {
					for (int i{ 0 }; i < numberStorage.size(); i++)
						if (tempL < numberStorage.at(i))
							tempL = numberStorage.at(i);
					cout << "The largest number in the storage is: " << tempL << endl;
				}
				else
					cout << "Unable to calculate the largest number in the list..\n";
				break;
			}
			case 'a':
			case 'A': {
				cout << "Please enter a number you would like to add to the list!\nInput > ";
				cin >> tempCinStorageForAdding;
				numberStorage.push_back(tempCinStorageForAdding);
				// reset the int just in case
				tempCinStorageForAdding = 0;
				break;
			}
			case 'm':
			case 'M': {
				int averageTemp = 0;
				if (numberStorage.size() != 0) {
					for (size_t val : numberStorage)
						averageTemp += val;
					cout << "The average number in the list is: " << (averageTemp % 5) << endl;
				}
				else
					cout << "Unable to calculate the average of the list";
				break;
			  }
			default:
				cout << "Invalid option!\n";
				break;
			}
			
		

	} while (checkForQuitChar != 'Q');

    return 0;
}
