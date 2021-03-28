#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void calculateAnswer(char enterVar);

int main()
{
	char yesOrNo;
	while (true)
	{
		cout << "Do you wish to decode or encode to ASCII [d/e]: max of 1" << endl << ">";
		cin >> yesOrNo;
		system("cls");
		while (yesOrNo)
		{
			calculateAnswer(yesOrNo);
			yesOrNo = '\0';
			continue;
		}
  }
	system("pause>0");
}

void calculateAnswer(char enterVar) {
	int numberStore{};
	char letters{};
	if (enterVar == 'd') {
		cout << "Provide an int you wish to decode from ASCII: Max of 1" << endl << ">";
		cin >> numberStore;
		cout << "Here is your decoded letter: " << char(numberStore) << endl;
	}
	else if (enterVar == 'e') {
		cout << "Provide a character you wish to encode to ASCII: Max of 1" << endl << ">";
		cin >> letters;
		cout << "Here is your encoded letter: " << int(letters) << endl;
	}
	else system("cls");
}
