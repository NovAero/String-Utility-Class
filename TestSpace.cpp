#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main() {

	String balls = "ants";
	String balls2 = "abcse";

	bool isFirst = (balls < balls2);

	cout << isFirst;
}