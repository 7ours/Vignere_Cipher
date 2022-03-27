#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// declartion of functions i made and used in program.
void encryption(string message, string keyword);
string upper_letters(string word);
bool check_input(string text, string keyword);
void decryption(string message, string keyword);
int choose_mode();
void program();

int main()
{
	program();
}

void encryption(string message, string keyword)
{
	int x = 0;
	cout << "The encrypted message => ";
	for (int i = 0; i < message.length(); i++)
	{
		if ( (65 <= message[i] && message[i] <= 90) )
		{
			cout << char(((message[i] + keyword[x]) % 26) + 65);
			x++;
			if (x == (keyword.length()))
			{
				x = 0;
			}
		}
		else
		{
			x++;
			cout << message[i];
		}
	}
}

string upper_letters(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((97 <= word[i] && word[i] <= 122))
		{
			word[i] -= 32;
		}
	}
	return word;	
}

bool check_input(string text, string keyword)
{	
	if (text.length() <= 80 && keyword.length() <= 8)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void decryption(string message, string keyword)
{
	int x = 0;
	int original_text;
	cout << "The original message => ";
	for (int i = 0; i < message.length(); i++)
	{
		int n = 0;
		if ((65 <= message[i] && message[i] <= 90))
		{
			while (true)
			{																// (a+x) % m = b ---> x= nm + b - a.
		 		original_text = (n * 26) + (message[i] - 65) - keyword[x];  // encryption --> (message[i]+keyword[x]) % 26 = final + 65
																			// decryption --> message[i] = 26* n + (final - 65 ) - keyword[x]
																			// n --> any integer number will produce new solution
				n++;														// right solution will be letter in ASCII and uppercase so between 65,90.
				if (65 <= original_text && original_text <= 90)
				{
					cout << char(original_text);
					break;
				}
			}
			x++;
			if (x == (keyword.length()))
			{
				x = 0;
			}
		}
		else
		{
			x++;
			cout << message[i];
		}
	}
}

int choose_mode()
{
	int choice;
	cout << "Welcome to our program, Enter 1 for encryption or 2 for decryption." << endl;
	cin >> choice;
	cin.ignore();
	if (choice != 1 && choice != 2)
	{
		cout << "Invalid input please try again." << endl;
		choose_mode();
	}
	return choice;
}

void program()
{
	string message, keyword;

	if (choose_mode() == 1)
	{
		cout << "Enter message you want to encrypt please: " << endl;
		getline(cin, message);
		cout << "Enter keyword please: " << endl;
		getline(cin, keyword);
		if (check_input(message, keyword))
		{
			encryption(upper_letters(message), upper_letters(keyword));
		}
		else
		{
			cout << "Invalid input please try again." << endl;
			program();
		}
	}
	else
	{
		cout << "Enter message you want to decrypt please: " << endl;
		getline(cin, message);
		cout << "Enter keyword please: " << endl;
		getline(cin, keyword);
		if (check_input(message, keyword))
		{
			decryption(upper_letters(message), upper_letters(keyword));
		}
		else
		{
			cout << "Invalid input please try again." << endl;
			program();
		}
	}
}


