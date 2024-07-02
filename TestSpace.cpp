#include <iostream>
#include "String.h"
using namespace std;

int main() {

	String string1 = "rat bird chicken elephant snake elephant lion elephant giraffe";
	String stringcopy = "rat bird chicken elephant snake elephant lion elephant giraffe";
	String string2 = "elephant";
	String string3 = "dog";

	string1.Print('n');

	string1.Replace(string2, string3);

	string1.Print('n');

	stringcopy.Print('n');

	stringcopy.Replace(string2, string3, true);

	stringcopy.Print('n');

}