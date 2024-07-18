#include <iostream>
#include <fstream>
#include "String.h"
#include <chrono>
#include <ctime>

using namespace std;

int main() {

	String a = "balls";
	String b = "avocado";

	cout << (a < b);


	a.Replace("avocado", "balls", true);

	cout << a.GetData();
}
