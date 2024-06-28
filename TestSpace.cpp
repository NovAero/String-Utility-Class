#include <iostream>
#include "string.h"
using namespace std;

int main() {

	String emptyString;

	String string1 = "THAS";
	String string2 = "that";

	std::cout << (string1 < string2);
}