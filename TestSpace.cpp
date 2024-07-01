#include <iostream>
#include "string.h"
using namespace std;

int main() {

	String string1 = "that this those this";
	String string2 = "this";
	String string3 = "deeznuts";

	string1.Print('n');
	string1.Replace(string2, string3, true);
	string1.Print('n');

}