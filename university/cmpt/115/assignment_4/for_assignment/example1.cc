//CMPT115 lab practice

using namespace std;

#include<cstdlib>
#include<iostream>
#include<iomanip>

int main(void) {
	float testValue;
	
	cout << "Enter a float value: \n";
	cin >> testValue;
	
	outputAbsoluteValue(testValue);
	
	return EXIT_SUCCESS;
}

float absoluteValue(float value)
{
	if (value < 0)
	{
		return -value;
	}
	else
	{
		return value;
	}
}

void outputAbsoluteValue(float value)
{
	cout << setw(10) << setprecision(4) << absoluteValue(value) << "\n";
}