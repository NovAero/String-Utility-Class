#include <iostream>
#include "string.h"

int main() {

	String emptyString;

	String string1 = "01234567asdasdasd";
	String& ptr = string1;
	String string2 = ptr;

	for (int i = 0; i < string2.len(); i++) {
		std::cout << string2[i];
	}

	std::cout << std::endl << string2.len();

	std::cout << std::endl << string2.charAt(2);
}