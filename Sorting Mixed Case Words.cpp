/*christopherKnight
This program takes an input of an external text document of 1000 mixed case words
It put the strings from the text file into an array and sorts the array alphabetically
Finally, the program allows the user to see the string stored at any index in the array */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
bool inOrder(string a, string b);
void exchange(string& y, string& z);

int main() {

	int const n = 1000;
	string theArray[n];
	int indexDesired;
	char ch;

	ifstream fin;
	fin.open("C:\\Users\\cekni\\OneDrive\\Desktop\\List of 1000 Mixed Case Words.txt");
	for (int i = 0; i < n; i++) {
		getline(fin, theArray[i]);
	}
	fin.close();

	for (int i = n - 1; i > 0; i--) {
		for (int k = 0; k < n - 1; k++) {
			if (inOrder(theArray[k], theArray[k + 1]) == false) {
				exchange(theArray[k], theArray[k + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << theArray[i] << ", ";
	}

	cout << "\nPlease enter which Array index you would like to know the contents of: ";
	cin >> indexDesired;
	cout << endl << "Index " << indexDesired << " contains " << theArray[indexDesired] << "!" << endl;

	return 0;
}

bool inOrder(string a, string b) {
	char ch1, ch2;
	for (int x = 0; x < a.length(); x++) {
		if (isupper(a[x])) {
			ch1 = tolower(a[x]);
			a[x] = ch1;
		}
	}

	for (int x = 0; x < b.length(); x++) {
		if (isupper(b[x])) {
			ch2 = tolower(b[x]);
			b[x] = ch2;
		}
	}
	return a <= b;
}

void exchange(string& y, string& z) {
	string t = y;
	y = z;
	z = t;
}