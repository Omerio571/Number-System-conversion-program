#include <iostream>
#include <string>

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

bool ValidateBase(int num);
bool ValidateInput(char inputNum, uint8_t sourceBase);

string ConvertNum();

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
		uint8_t sourceBase{}; // should only contain 2,8,10 and 16
		uint8_t targetBase{}; // should only contain 2,8,10 and 16

		int inputStringSize{};
		int base{}; // placeholder

		if (firstCycle)
		{
			cout << "Welcome to the Numbering System Calculator!\n";
			cout << "------------------------------------------------------------\n";
			cout << "Please Enter the following inputs : \n\n";
			firstCycle = false;
		}

		// I will get the number and a valid source Base
		cout << "The number to convert: \n >> ";
		cin >> inputNum;
		cout << "The source base (i.e., the base to convert From): \n >> ";
		cin >> base;

		if (ValidateBase(base))
			sourceBase = (uint8_t)base;
		else
		{
			cout << "Invalid Source Base, please try again!\n\n";
			continue;
		}

		// Now that we have the number I will verify if the Input matches the given Base format
		inputStringSize = size(inputNum);

		for (int i = 0; i < inputStringSize; i++)
		{
			bool isItValid = ValidateInput(inputNum[i], base);

			if (!isItValid)
			{
				cout << "The value " << inputNum[i]
					<< " does not match the source Base " << base << "\n\n"; // FIX THIS PART

				break;
			}
		}

	} 
	while (programRunning);
		

	return 0;
}

// This function checks if the given number matches a Base
bool ValidateBase(int num)
{
	if (num == 2 || num == 8 || num == 10 || num == 16)
		return true;

	return false;
}

// This function will compare the given input with the sourceBase character by character and then validate or invalidate it
bool ValidateInput(char inputNumIndex, uint8_t sourceBase) // Fix THIS PART
{
	// char something = 'A'; here 'A' value = 65

	bool validating{ true };

	while (validating)
	{
		if (inputNumIndex >= '0' && inputNumIndex <= '9')
			break;

		else if (inputNumIndex >= 'A' && inputNumIndex <= 'F')
			inputNumIndex -= inputNumIndex + sourceBase;

		else if (inputNumIndex >= 'a' && inputNumIndex <= 'f')
			inputNumIndex -= inputNumIndex + sourceBase;
	}		

	return inputNumIndex < sourceBase;
}