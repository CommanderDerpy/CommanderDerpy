#include <iostream>
#include <cmath>

using namespace std;
float foo(int r, int n) {
	//base case
	if (n == 0) {
		return 1;
	}
	//good case?
	if (n > 0) {
		return r*foo(r,n-1);
	}
	//error case
	if (n < 0) {
		cout << "Error" << endl;
	}
}

int main() {

	cout << foo(16,4) << endl;
	cout << "Works"
	return 0;
}