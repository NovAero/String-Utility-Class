#include <iostream>
#include "string.h"
using namespace std;

int main() {

	String emptyString;

	String string1 = "0123456789";
	String string2 = string1;

	cout << (string1 == string2);

}	