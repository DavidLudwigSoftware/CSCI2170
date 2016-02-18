// File:		ola2.cc
// Due Date:	February 22, 2016
// Author:		David Ludwig
// Description: Validate credit cards and determine the type of card
// Course:		CSCI 2170 - 004
// Input:		Data file of card numbers: "cardNumber.txt"
// Output:		The card number along with the type of card, and a statement of the validity

// Includes
#include <iostream>
#include <fstream>
#include <string>

// Use the std namespace
using namespace std;

// Define constants
const int CARD_UNKNOWN  = -1;
const int CARD_AMEX     =  0;
const int CARD_DISCOVER =  1;
const int CARD_MASTER   =  2;
const int CARD_VISA     =  3;


bool checkAMEXCard(string number)
{
    // Check the prefix
    if (number.substr(0, 2) == "34" || number.substr(0, 2) == "37")

        // It is an AMEX card
        return true;

    // It is not an AMEX card
    return false;
}


bool checkDiscoverCard(string number)
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


bool checkMasterCard(string number)
{

    // Check if it is within the range
    if (number[0] == '5' && number[1] - '0' < 6 && number[1] - '0' >= 0)

        // It is a MasterCard
        return true;

    // It is not a MasterCard
    return false;
}


bool checkVisaCard(string number)
{
    // Check the prefix
    if (number[0] == '4')

        // It is a Visa Card
        return true;

    // It is not a Visa Card
    return false;
}


int getCard(string number)
{
    // Check if the card is an AMEX card
    if (checkAMEXCard(number))

        // Return the card
        return CARD_AMEX;

    // Check if the card is a Discover Card
    else if (checkDiscoverCard(number))

        // Return the card
        return CARD_DISCOVER;

    // Check if the card is a MasterCard
    else if (checkMasterCard(number))

        // Return the card
        return CARD_MASTER;

    // Check if the card is a Visa Card
    else if (checkVisaCard(number))

        // Return the card
        return CARD_VISA;

    // The card was not found
    return CARD_UNKNOWN;
}

int calculateCheckDigit(string cardNumber)
{
    // Return the check digit
    return cardNumber[cardNumber.length() - 1] - '0';
}

bool isValidCard(string cardNumber, int cardType)
{
    // Declare the variables
    string rev = "";
    int digit;
    int sum = 0;

    // Check the length
    if (
            !((cardType == CARD_AMEX && cardNumber.length() == 15) ||
             ((
                  cardType == CARD_DISCOVER ||
                  cardType == CARD_MASTER   ||
                  cardType == CARD_VISA)    && cardNumber.length() == 16) ||
             (cardType == CARD_VISA && cardNumber.length() == 13))
        ){
         // It's invalid
        return false;
    }

    // Get the check digit
    int checkDigit = calculateCheckDigit(cardNumber);

    // Reverse the card number
    for (int i = cardNumber.length() - 2; i >= 0; i--)
    {
        // Get the digit from the card number
        digit = cardNumber[i] - '0';

        // Determine if the digit is in an odd position
        if ((cardNumber.length() - 1 + i) & 1)
        {
            // Multiply the digit by 2 and subtract 9 if greater than 9
            digit = (digit * 2 > 9) ? digit * 2 - 9: digit * 2;
        }

        // Add the digit to the total
        sum += digit;

        // Append the number
        rev += cardNumber[i];
    }

    // Check if the sum and check digit add to a multiple of 10
    if ((sum + checkDigit) % 10 == 0)

        // It's a valid card number
        return true;

    // It's an invalid card number
    return false;
}

int main()
{

    // Declare variables
    ifstream cardNumbers;
    string   cardNumber = "";
    string   cards[] = {"American Express card", "Discovercard", "MasterCard", "Visa Card"};
    int      card;

    // Open the card numbers file
    cardNumbers.open("cardNumber.txt");

    if (!cardNumbers.is_open())
    {
        cout << "Failed to open cardNumber.txt";
        return 1;
    }

    // Prime read the first card number
    cardNumbers >> cardNumber;

    // Loop through the all of the numbers
    while (!cardNumbers.eof())
    {
        // Print out the card number
        cout << cardNumber;

        // Align the card types by adding tabs
        cout << ((cardNumber.length() < 16) ? "\t\t" : "\t");

        // Get the type of card
        card = getCard(cardNumber);

        // Check if the card is a known card
        if (card != -1)
        {
            // Check if the card number is valid
            if (isValidCard(cardNumber, card))

                // Print the card as valid and card type
                cout << "Valid " << cards[card] << endl;

            else

                // Print the card as invalid and the card type
                cout << "Invalid " << cards[card] << endl;
        }
        else
        {
            // Print the card is unknown
            cout << "Unknown card" << endl;
        }

        // Get the next card
        cardNumbers >> cardNumber;
    }

    // Close the file
    cardNumbers.close();

    // Finished
    return 0;
}
