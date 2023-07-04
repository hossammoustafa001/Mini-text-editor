#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

vector<string> arr;

void add_text()
{


	cout << "Enter your text:\t";
	string c;
	cin.ignore();
	getline(cin, c);
	arr.push_back(c);
	cout << "Line is added\n";
}
void show()
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ": " << arr.at(i) << endl;

	}

}
void FileReader()
{
	ifstream FirstList;
	FirstList.open("list.txt");
	string s;
	if (FirstList.is_open())
	{
		while (getline(FirstList, s))
		{
			arr.push_back(s);
		}
	}
}
int insertAt()
{
	string s;
	int x;
	cout << "Enter the line number:\t";
	cin >> x;
	if (x <= arr.size())
	{
		cout << "Enter your text:\t";
		cin.ignore();
		getline(cin, s);
		arr.insert(arr.begin() + x - 1, s);
		cout << "Line is inserted at " << x  << endl;
	    return x;
	}
	else
	{
		cout << "Number is greater than the list ";
		return -1;
	}
}
int DeleteAt(string &str)
{
	cout << "Enter the line number to delete:\t";
 	int x;
	cin >> x;
	if (x < arr.size())
	{
     	str = arr.at(x-1);
		arr.erase(arr.begin() + x - 1);
		cout << "line is deleted\n";
	    return x;
	}
	else if (x == arr.size())
	{
		str = arr.at(x - 1);
		arr.pop_back();
		cout << "line is deleted\n";

		return x;
	}
	else
	{
		cout << "Line is not found";
		return -1;
	}
}
void ShowAt()
{
	cout << "Enter the line number to display:\t";
	int x;
	cin >> x;
	if (x <= arr.size())
	{
		cout << arr.at(x - 1);
	}
	else
	{
		cout << "Line is not found";
	}
	
}
int Update(string &str)
{
	string s;
	int x;
	cout << "Enter the line number to update:\t";
	cin >> x;
	if (x == arr.size())
	{
	    str = arr.at(x - 1);
		cout << "Enter your new text:\t";
		cin.ignore();
		getline(cin, s);
		
		arr.erase(arr.begin() + x - 1);
		arr.push_back(s);
		cout << "line is updated\n";
	    return x;
	}
	else if (x < arr.size())
	{
			str = arr.at(x - 1);
			cout << "Enter your new text:\t";
			cin.ignore();
			getline(cin, s);

			arr.erase(arr.begin() + x - 1);
			arr.insert(arr.begin() + x - 1, s);
			cout << "line is updated\n";
			return x;
	}
	else
	{
		cout << "Line is not found";
		return -1;
	}

}
void search()
{
	int end = 0;
	int counter=0;
	string s;
	bool WordFound = false;
	cout << "Enter your word to search:\t";
	cin.ignore();
	getline(cin, s);
	for (int i = 0; i < arr.size(); i++)
	{
		while(end==arr[i].find("."))
		{
		    int found = arr[i].find(s);
			if (found != -1)
			{
				counter++;
				cout << i + 1 << endl;
				WordFound = true;
			}
		}

	}
	cout << counter;
	if (WordFound == false)
	{
		cout << "Word is not found";
	}

}
void searchAndReplace(string &str,string &str2)	
{
	int totChar = 0;
	cout << "Enter word to replace:\t" << endl;
	bool WordFound = false;
	string s;
	cin.ignore();
	getline(cin, s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ')// this condition is used to avoid counting space
		{
			totChar++;
		}

	}
	cout << "Enter your new word:\t" << endl;
	string str1;
	getline(cin, str1);

    	
	
	

		for (int i = 0; i < arr.size(); i++)
		{
			int found = arr[i].find(s);
			if (found != -1)
			{
				str = s;
				str2 = str1;
				arr[i].replace(found, totChar, str1);
				WordFound = true;

			}
			
		}

	
	
	if (WordFound == false)
	{
		cout << "Word is not found to be replaced";
		
	}
	else
	{
		cout << "all Words are replaced\n";
		
	}

}
void read()
{
	ofstream out;
	out.open("list.txt");
	for (int i = 0; i < arr.size(); i++)
	{
		out << arr[i] << endl;
	}
	out.close();
}
void undo(int operation,int index,string str, string str1)

{
	switch (operation)
	{
	case 1:
	arr.pop_back();
	break;
	case 2:
		if (index < arr.size())
		{
			arr.erase(arr.begin() + index - 1);
		}
		else if (index == arr.size())
		{
			arr.pop_back();
		}
		break;
	case 4:
		if (index < arr.size())
		{
			arr.insert(arr.begin() + index - 1, str);
		}
		else if (index-1 == arr.size())
		{
			arr.push_back(str);
		}
		break;
	case 5 :
		if (index < arr.size())
		{
			arr.erase(arr.begin() + index - 1);
			arr.insert(arr.begin() + index - 1, str);
		}
		else if (index == arr.size())
		{
			arr.pop_back();		
			arr.push_back(str);
		}
		break;
	case 7:
		int totChar = 0;
		for (int i = 0; str1[i] != '\0'; i++) {
			if (str1[i] != ' ')// this condition is used to avoid counting space
			{
				totChar++;
			}

		}
		for (int i = 0; i < arr.size(); i++)
		{
			int found = arr[i].find(str1);

			if (found != -1)
			{
				
				arr[i].replace(found, totChar, str);
				
			}

		}
		break;


	}
}
void menu()
{
	stack<int> Choice1;
	stack<int> index;
	int choice;
	stack<string>string1;
	stack<string>string2;
	string str = "";
	string str1 = "";
	bool found = false;

	

	while (true)
	{

		cout << "\n\t\t\t\t\t\t\t\t\Welcome to mini text editor\n";
		cout << "\t\t\t\t\t\t\t\t\..............................\n\n\n\n\n";
		cout << "1-Add line\n";
		cout << "2-Insert line\n";
		cout << "3-Get line text\n";
		cout << "4-Delete line\n";
		cout << "5-Update line\n";
		cout << "6-Find all\n";
		cout << "7-Find and replace all\n";
		cout << "8-Show\n";
		cout << "9-Undo\n";
		cout << "10-Exit\n";
		cout << "Enter the number of your choice:\t";

		cin >> choice;

		if (choice == 1 || choice == 2 || choice == 4 || choice == 5 || choice == 7)
		{
			Choice1.push(choice);

		}
		if (index.empty())
		{
			index.push(-2);
		}
		if (string1.empty())
		{
			string1.push("");
		}
		if (string2.empty())
		{
			string2.push("");
		}

		switch (choice)
		{
		case 1:
			add_text();
			break;
		case 2:
			if (index.top() == -2)
			{
				index.pop();
			}
			index.push(insertAt());
			break;
		case 3:
			ShowAt();
			break;
		case 4:
			if (index.top() == -2)
			{
				index.pop();
			}
			index.push(DeleteAt(str));
			if (string1.top() == "")
			{
				string1.pop();
			}
			string1.push(str);

			break;
		case 5:
			if (index.top() == -2)
			{
				index.pop();
			}
			index.push(Update(str));
			if (string1.top() == "")
			{
				string1.pop();
			}
			string1.push(str);
			break;
		case 6:
			search();
			break;
		case 7:
			searchAndReplace(str, str1);
			string1.push(str);
			string2.push(str1);
			break;
		case 8:
			show();
			break;
		case 9:
			if (!Choice1.empty())
			{
				if (index.top() != -1)
				{
					undo(Choice1.top(), index.top(), string1.top(), string2.top());
					Choice1.pop();
					index.pop();
					string1.pop();
					string2.pop();
					cout << "Undo Done";
				}
				else
				{
					cout << "no more operations to undo";
				}
			}
			else
			{
				cout << "no more operations to undo";
			}
			break;
		case 10:
			break;
		default:
			cout << "Invalid choice" << endl;
		}

		if (choice == 10)
		{
			break;
		}
		if (choice < 1 || choice>10)
		{
			cout << "Please Enter a valid choice\n";
		}
	
		
		
	}
}




int main()
{
	FileReader();
	menu();
	read();

	
	
	return 0;
}