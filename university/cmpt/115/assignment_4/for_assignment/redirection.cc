// File-redirection tutorial
// 

#include <iostream>
using namespace std;

int main() {

	int i1, i2, i3, i4;
	char c;
	char s[20];
	float f;
	
	cin >> i1 >> f >> i2 >> s >> i3 >> c >> i4;
	cout << "The integers read in from file are: " 
		<< i1 << " " << i2 << " " << i3 << " " << i4  << endl 
		<< "The float number read in from file is: " << f << endl
		<< "The character read in from file is: " << c << endl
		<< "The string read in from file is: " << s << endl;
	 	
  return 0;
}

