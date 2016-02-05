// File:		ola1.cc
// Due Date:	February 9, 2016
// Author:		David Ludwig
// Description: Determine the type of credit card from a data file of card numbers.
// Course:		CSCI 2170 - 004
// Input:		Data file of card numbers: "cardNumber.txt"
// Output:		The card number along with the type of card

// Includes
#include <iostream>
#include <fstream>
#include <string>

// Use the std namespace
using namespace std;


bool validateAMEXCard(string number)
{
	// Check the prefix
	if (number.substr(0, 2) == "34" || number.substr(0, 2) == "37")

		// It is an AMEX card
		return true;

	// It is not an AMEX card
	return false;
}


bool validateDiscoverCard(string number)
{
	// Get the integer value after 622
	int range = (number[3] - '0') * 100 + (number[4] - '0') * 10 + number[5] - '0';

	// Check the prefix
	if (number.substr(0, 4) == "6011" ||
		number.substr(0, 2) == "65"   ||
		(
			number.substr(0, 3) == "622" &&
			range >= 126 && range < 926
		)
	)

		// It is a Discover Card
		return true;

	// It is not a Discover Card
	return false;
}


bool validateMasterCard(string number)
{

	// Check if it is within the range
	if (number[0] == '5' && number[1] - '0' < 6 && number[1] - '0' >= 0)

		// It is a MasterCard
		return true;

	// It is not a MasterCard
	return false;
}


bool validateVisaCard(string number)
{
	// Check the prefix
	if (number[0] == '4')

		// It is a Visa Card
		return true;

	// It is not a Visa Card
	return false;
}


string getCard(string number)
{
	// Check if the card is an AMEX card
	if (validateAMEXCard(number))

		// Return the card
		return "AMEX card";

	// Check if the card is a Discover Card
	else if (validateDiscoverCard(number))

		// Return the card
		return "Discover Card";

	// Check if the card is a MasterCard
	else if (validateMasterCard(number))

		// Return the card
		return "MasterCard";

	// Check if the card is a Visa Card
	else if (validateVisaCard(number))

		// Return the card
		return "Visa Card";

	// The card was not found
	return "Unknown card";
}


int main()
{
	// Declare variables
	ifstream cardNumbers;
	string   cardNumber = "";

	// Open the card numbers file
	cardNumbers.open("cardNumber.txt");
	
	// Prime read the first card number
	cardNumbers >> cardNumber;

	// Loop through the all of the numbers
	while (!cardNumbers.eof())
	{
		// Print out the card number
		cout << cardNumber;
		
		// Align the card types by adding tabs
		cout << ((cardNumber.length() < 16) ? "\t\t" : "\t");
		
		// Print the type of card
		cout << getCard(cardNumber) << endl;

		// Get the next card
		cardNumbers >> cardNumber;
	}

	// Close the file
	cardNumbers.close();

	// Finished
	return 0;
}