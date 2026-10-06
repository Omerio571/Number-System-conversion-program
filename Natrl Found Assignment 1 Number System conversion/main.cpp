#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// I will be using Comments as my strategy
// I will be firstly taking the values, InputNumber, and SourceBase from the user.
// I will then check if the InputNumber is valid for the specific Source Base using the "ValidInput()" Function.
// I will then ask for the Target base.
// If the targetBase is the same as the sourceBase then the program will be completed
// Otherwise we will first convert the input number into decimal aka Base 10 // ConvertToDecimal()
// We will do this by multiplying by the Base. 
	// Example x = 101, binary(2), size = 3
	// --> x[i] * sourceBase ^ size(x) - 1
	// ---> use i = 0
	// ---> x[1] * 2 ^ 3 - 1
	// which will get us 
	// --> 1* 2^2 = 4 and we will do the same thing and add onto this ...
// If it is already at Base 10 we won't do anything.
// Now we check the targetBase, and depending on what it is we modulate the decimal number // ConvertFromDecimal()
// We do this until we have all the remainders and then we combine them into a string and the program is done
// We then ask if they want to do another conversion.

bool ValidatedBase(int num, uint8_t& sourceBase, string whichBase);
bool ValidateInput(char inputNum, uint8_t sourceBase);

int ReturnRealVal(char numIndex, uint8_t base);
string ConvertNum(string inputNum, uint8_t sourceBase, uint8_t targetBase);

int ConvertToDecimal();
string ConvertFromDecimal();

int main()
{
	bool programRunning{ true };
	bool firstCycle{ true };

	do
	{
		// I will first initialize all my variables
		string inputNum{}; // the reason it is a string is we also need to get 'A' - 'F'
		string outputNum{"Nothing Changed"};
		char endProgram{};

		uint8_t sourceBase{}; // should only contain 2,8,10 and 16
		uint8_t targetBase{}; // should only contain 2,8,10 and 16

		int inputStringSize{};
		int base{}; // placeholder

		if (firstCycle)
		{
			cout << "Welcome to the Numbering System Calculator!\n";
			cout << "------------------------------------------------------------\n";
			cout << "Please Enter the following inputs : \n";
			firstCycle = false;
		}

		// I will get the number and a valid source Base
		cout << "\nThe number to convert: \n >> ";
		cin >> inputNum;
		cout << "The source base (i.e., the base to convert From): \n >> ";
		cin >> base;

		if (!ValidatedBase(base, sourceBase, "Source Base")) continue;

		// Now that we have the number I will verify if the Input matches the given Base format
		inputStringSize = size(inputNum);

		bool isItValid{};

		for (int i = 0; i < inputStringSize; i++)
		{
			isItValid = ValidateInput(inputNum[i], base);

			if (!isItValid)
			{
				cout << "\nThe value " << inputNum[i]
					<< " does not match the source Base " << base << "\n\n";

				break;
			}
		}
		if (!isItValid) continue;

		cout << "The target base (i.e., the base to convert To): \n >> ";
		cin >> base;

		if (!ValidatedBase(base, targetBase, "Target Base")) continue;

		outputNum = ConvertNum(inputNum, sourceBase, targetBase);

		cout << "\nThe result of converting the number " << inputNum
			<< " from base " << (int)sourceBase
			<< " to base " << (int)targetBase 
			<<" is: \n >> " << outputNum;

		// Just checks if the user wants to continue or not.
		while (programRunning)
		{
			cout << "\nDo you wish to continue with other numbers?\n"
				<< "Enter(Y) to continue\n"
				<< "Enter(N) to quit \n >> ";

			// This string just allows me to search for the first entry of the input instead of looking through every input as a character of the string.
			string justAChecker{};

			cin >> justAChecker;

			endProgram = justAChecker[0];

			if (endProgram == 'y' || endProgram == 'Y')
				break;
			else if (endProgram == 'n' || endProgram == 'N')
				programRunning = false;
			else
			{
				cout << "\n\nWe didn't get that please try again!\n";
				continue;
			}
		}
	} 
	while (programRunning);

	return 0;
}

// This function checks if the given number matches a Base
bool ValidatedBase(int num, uint8_t& base, string whichBase)
{
	base = (uint8_t)num;

	if (num == 2 || num == 8 || num == 10 || num == 16)
		return true;

	cout << "\nInvalid " << whichBase << ", please try again!\n\n";
	return false;
}

// This function will compare the given input with the sourceBase character by character and then validate or invalidate it
bool ValidateInput(char inputNumIndex, uint8_t sourceBase)
{
	inputNumIndex = ReturnRealVal(inputNumIndex, sourceBase);

	return inputNumIndex < sourceBase;
}

int ReturnRealVal(char numIndex, uint8_t base)
{
	if (numIndex >= '0' && numIndex <= '9')
		numIndex -= '0';

	else if (numIndex >= 'A' && numIndex <= 'F')
		numIndex -= 'A' + 10;

	else if (numIndex >= 'a' && numIndex <= 'f')
		numIndex -= 'a' + 10;

	return numIndex;
}

string ConvertNum(string inputNum, uint8_t sourceBase, uint8_t targetBase)
{
	if (sourceBase == targetBase) return inputNum;

	string returnVal{};
	int decimalVal{};
	short stringSize{ (short)size(inputNum) };
	

	for (int i = 0; i < stringSize; i++)
	{
		decimalVal += (ReturnRealVal(inputNum[i], sourceBase) * pow(sourceBase, (stringSize - (i + 1))));
	}

	if(targetBase == 10)
		 returnVal = to_string(decimalVal);
	else
	{

	}

	return returnVal;
}