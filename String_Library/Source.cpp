#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{

	//INPUT

	int ch = 0;
	int size = 20;

	cout << "\nInput Options:\n";
	cout << "\n1. User Input";
	cout << "\n2. File Input";
	cout << "\n\nDo you want to input the file from user or file? ";
	cin >> ch;

	MyString S;

	switch (ch)
	{
	case 1:
		S.UserInput(size);
		break;

	case 2:
		S.FileInput();
		break;

	default:
		cout << "\nWrong Input!";
	}

	if (ch > 2)
		exit(0);

	system("CLS");

	cout << "Text: ";
	S.Print();


	//MENU (MAIN FUNCTIONS)

	cout << "\n\nMenu:\n";
	cout << "\n1. Split Text";
	cout << "\n2. Tokenize Text";
	cout << "\n3. Check if Texts are Equal";
	cout << "\n4. Trim Text";
	cout << "\n5. Merge Text";
	cout << "\n6. Search Text";
	cout << "\n7. Find First Index";
	cout << "\n8. Find Last Index";
	cout << "\n9. Find All Indexes";
	cout << "\n10. Remove First Index";
	cout << "\n11. Remove Last Index";
	cout << "\n12. Remove Character At";
	cout << "\n13. Remove All Character";
	cout << "\n14. Add Character";
	cout << "\n15. Add Sub-Text";
	//Clear [DONE] DIDNT WRITE IN MAIN - HAD LESS TIME FOR SUBMISSION
	//ATOI [DONE] DIDNT WRITE IN MAIN - HAD LESS TIME FOR SUBMISSION
	//ITOA [DONE] DIDNT WRITE IN MAIN - HAD LESS TIME FOR SUBMISSION

	ch = 0;

	cout << "\n\nEnter your choice: ";
	cin >> ch;

	MyString* Ss;
	MyString S2;

	char d = 0;
	int count = 0;
	char* subText = new char[100];
	int* search;
	int index = 0;
	char temp = '\0';

	switch (ch)
	{
	case 1:
		d = '\0';
		count = 0;

		Ss = S.Split(' ', count);
		
		for (int i = 0; i < count; i++)
		{
			Ss[i].Print();
			cout << endl;
		}
		break;

	case 2:
		d = '\0';
		count = 0;

		cout << "\nEnter the delimiter: ";
		cin >> d;

		Ss = S.Tokenize(d, count);

		for (int i = 0; i < count; i++)
		{
			Ss[i].Print();
			cout << endl;
		}
		break;

	case 3:
		cout << "\nEnter a sub-text to check if it's equal to the text: ";
		cin.ignore();
		cin.getline(subText, 99);

		S2.Initialize(subText);

		if (S2.Cmp(S) == 0)
			cout << "\nIt is Equal!\n";
		else
			cout << "\nIt is not Equal!\n";
		
		break;

	case 4:
		S.Trim();
		S.Print();

		break;

	case 5:
		cout << "\nEnter a sub-text to merge to the text: ";
		cin.ignore();
		cin.getline(subText, 99);

		S2.Initialize(subText);

		S = S.Concati(S2);
		S.Print();

		break;

	case 6:
		cout << "\nEnter a text to search: ";
		cin.ignore();
		cin.getline(subText, 99);

		S2.Initialize(subText);

		count = 0;

		search = S.SubStringSearch(S2, count);
		
		if (count != 0)
		{
			cout << "The indexes of the found text are: ";

			for (int i = 0; i < count; i++)
				cout << search[i] << ", ";
		}
		else
			cout << "\nText not found!";

		break;

	case 7:

		temp = '\0';
		cout << "\nWhat character do you want to find the first index of? ";
		cin >> temp;

		index = 0;

		index = S.Find_First(temp);
		cout << "\nIndex: " << index;

		break;

	case 8:

		temp = '\0';
		cout << "\nWhat character do you want to find the last index of? ";
		cin >> temp;

		index = 0;

		index = S.Find_Last(temp);
		cout << "\nIndex: " << index;

		break;

	case 9:

		temp = '\0';
		cout << "\nWhat character do you want to find the all indexes of? ";
		cin >> temp;

		count = 0;

		search = S.Find_All(temp, count);
		cout << "\nIndexes: ";

		for (int i = 0; i < count; i++)
			cout << search[i] << ", ";

		break;

	case 10:

		temp = '\0';
		cout << "\nWhat character do you want to remove the first index of? ";
		cin >> temp;

		S.Remove_First(temp);

		cout << "\nText: ";
		S.Print();

		break;

	case 11:

		temp = '\0';
		cout << "\nWhat character do you want to remove the last index of? ";
		cin >> temp;

		S.Remove_Last(temp);

		cout << "\nText: ";
		S.Print();

		break;

	case 12:

		ch = 0;
		cout << "\nWhat index do you want to remove the character? ";
		cin >> ch;

		S.Remove_At(ch);

		cout << "\nText: ";
		S.Print();

		break;

	case 13:

		temp = '\0';
		cout << "\nWhat character do you want to remove? ";
		cin >> temp;

		S.Remove_All(temp);

		cout << "\nText: ";
		S.Print();

		break;

	case 14:

		temp = '\0';
		cout << "\nWhat character do you want to add? ";
		cin >> temp;

		ch = 0;
		cout << "\nAt what index do you want to add? ";
		cin >> ch;

		S.Insert_At(ch, temp);

		cout << "\nText: ";
		S.Print();

		break;

	case 15:
		cout << "\nWhat sub-text do you want to add? ";
		cin.ignore();
		cin.getline(subText, 99);

		S2.Initialize(subText);

		ch = 0;
		cout << "\nAt what index do you want to add? ";
		cin >> ch;

		S.Insert_At(ch, subText);

		cout << "\nText: ";
		S.Print();

		break;


	}

	return 0;

}