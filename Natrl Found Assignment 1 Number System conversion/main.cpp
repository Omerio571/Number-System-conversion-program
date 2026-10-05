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

enum Base
{
	binary = 2,
	octal = 8,
	decimal = 10,
	hexadecimal = 16
};

bool ValidInput(string inputNum, Base sourceBase);
string ConvertNum();
int ConvertToDecimal();
string ConvertFromDecimal();

int main()
{

	return 0;
}

bool ValidInput(string inputNum, Base sourceBase)
{

}