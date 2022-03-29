#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// declartion of functions i made and used in program.

// encryption function takes message and keyword then prints encrypted message.
void encryption(string message, string keyword);

// function takes any string and returns all of it in uppercase.
string upper_letters(string word);

// function checks if input is valid because message length should be less than 80 and keyword length should be less than 8.
// if input is invalid fuction will ask user to try again.
bool check_input(string text, string keyword);

// decryption function takes message and keyword then prints decrypted message.
void decryption(string message, string keyword);

// function which asks user if he want to use encryption or decryption and returns his choice.
string choose_mode();

// function contains all funtions and the final result.
void program();

int main()
{
	program(); // call the program function.
}

void encryption(string message, string keyword)
{
	int x = 0;
	cout << "The encrypted message => ";
	for (int i = 0; i < message.length(); i++) // loop on all characters in message and add it to keyword.
	{
		if ( (65 <= message[i] && message[i] <= 90) ) // checks if character is alphabetic or not if it's alphabetic then it will be encrypted if not it will remain.
		{
			cout << char(((message[i] + keyword[x]) % 26) + 65); // equation of encryption.
			x++;
			if (x == (keyword.length())) // if it reatched the end of keyword it will starts form beginning again.
			{
				x = 0;
			}
		}
		else
		{
			x++;
			cout << message[i]; // prints the character without changes if it's alphabetic.
		}
	}
}

string upper_letters(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((97 <= word[i] && word[i] <= 122)) // checks the lowercase letters only and convert it ot uppercase.
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

string choose_mode()
{
	string choice;
	cout << "Welcome to our program, Enter 1 for encryption or 2 for decryption." << endl;
	cin >> choice;
	cin.ignore();
	if (choice != "1" && choice != "2")
	{
		cout << "Invalid input please try again." << endl;
		choose_mode();
	}
	return choice;
}

void program()
{
	string message, keyword;

	if (choose_mode() == "1") // at first ask user if he wants to use encryption or decryption and checks if input is valid or not.
	{
		// takes the message and keyword from user.
		cout << "Enter message you want to encrypt please: " << endl;
		getline(cin, message);
		cout << "Enter keyword please: " << endl;
		getline(cin, keyword);
		if (check_input(message, keyword)) // checks if input is valid or not.
		{
			encryption(upper_letters(message), upper_letters(keyword));
		}
		else
		{
			cout << "Invalid input please try again." << endl; // if input is invalid prints this message and ask user to try again.
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


