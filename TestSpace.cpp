#include <iostream>
#include <fstream>
#include "String.h"
#include <chrono>
#include <ctime>

using namespace std;

const char* TestLen();
const char* TestCharAt();
const char* TestIsEqual();
const char* TestToLower();
const char* TestToUpper();
const char* TestSuffix();
const char* TestPrefix();
const char* TestFind();
const char* TestReplaceFirst();
const char* TestReplaceAll();
const char* TestInput();
const char* TestPrint(char mod);
void TestHandler();

char tmBuff[30];

int main() {
	
	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);

	TestHandler();
	
}

const char* TestLen()
{
	String text = "elephant dog bird rat elephant";
	if(text.len() == 30) {
		return "Success";
	}
	return "Failure";
}

const char* TestCharAt()
{
	String text = "elephant dog bird rat elephant";
	if (text.CharAt(3) != 'p') {
		return "Failure";
	}
	return "Success";
}

const char* TestIsEqual()
{
	String text = "elephant dog bird rat elephant";
	if (text == "elephant dog bird rat elephant") {
		return "Success";
	}
	return "Failure";

}

const char* TestToLower()
{
	String text = "elePHant dOg bird RAt elepHANt";
	text.ToLower();
	if (text == "elephant dog bird rat elephant") {
		return "Success";
	}
	return "Failure";
}

const char* TestToUpper()
{
	String text = "elepHaNt dog bIRd raT elePhanT";
	text.ToUpper();
	if (text == "ELEPHANT DOG BIRD RAT ELEPHANT") {
		return "Success";
	}
	return "Failure";
}

const char* TestSuffix()
{
	String text = "elephant dog bird rat elephant";
	text.Suffix("bird");

	if (text == "elephant dog bird rat elephantbird") {
		return "Success";
	}
	return "Failure";
}

const char* TestPrefix()
{
	String text = "elephant dog bird rat elephant";
	text.Prefix("bird");

	if (text == "birdelephant dog bird rat elephant") {
		return "Success";
	}
	return "Failure";
}

const char* TestFind()
{
	String text = "elephant dog bird rat elephant";;

	if (text.Find("elephant") == 0) {
		return "Success";
	}
	return "Failure";
}

const char* TestReplaceFirst()
{
	String text = "elephant dog bird rat elephant";
	String find = "elephant";
	String replace = "dog";

	text.Replace(find, replace);

	if (text == "dog dog bird rat elephant") {
		return "Success";
	}
	return "Failure";
}

const char* TestReplaceAll()
{
	String text = "elephant dog bird rat elephant";
	String find = "elephant";
	String replace = "dog";

	text.Replace(find, replace, true);

	if (text == "dog dog bird rat dog") {
		return "Success";
	}
	return "Failure";
}

const char* TestInput()
{ 
	cout << "Please write: \"elephant\" \n";
	String text;

	text.Input();

	if (text == "elephant") {
		return "Success";
	}
	return "Failure";
}

const char* TestPrint(char mod)
{
	String text = "elephant dog bird rat elephant";
	int eotIndex = text.len();
	String ptr = text.Print(mod);

	switch (mod) {

		case 'n': //returns data with a new line after
			if (ptr[eotIndex] == '\n') {
				return "Success";
				break;
			} 
			return "Failure";
			break;
		case 't': //returns data with a tab after it
			if (ptr[eotIndex] == '\t') {
				return "Success";
				break;
			}
			return "Failure";
			break;

		case 'p': //returns data with a space before (p stands for prefix)
			if (ptr[0] == ' ') {
				return "Success";
				break;
			}
			return "Failure";
			break;

		case's': //returns data with a space after (s stands for suffix)
			if (ptr[eotIndex] == ' ') {
				return "Success";
				break;
			}
			return "Failure";
			break;

		default: //just returns data with no mods if the modifier param != valid mod
			if (ptr == "elephant dog bird rat elephant") {
				return "Success";
				break;
			}
			return "Failure";
			break;
	}
}

void TestHandler()
{
	fstream file;
	file.open("StringUtilityTests.txt", std::ios::app);
	if (!file.is_open()) {
		cout << "File is open, cannot access";
		return;
	}
	file << "Test Text: " << "elephant dog bird rat elephant" << '\n';
	file << "Date & Time: " << tmBuff;
	file << "Testing len(): " << TestLen() << endl;
	file << "Testing CharAt(): " << TestCharAt() << endl;
	file << "Testing IsEqual(): " << TestIsEqual() << endl;
	file << "Testing ToLower(): " << TestToLower() << endl;
	file << "Testing ToUpper(): " << TestToUpper() << endl;
	file << "Testing Suffix(): " << TestSuffix() << endl;
	file << "Testing Prefix(): " << TestPrefix() << endl;
	file << "Testing Find(): " << TestFind() << endl;
	file << "Testing Replace(First): " << TestReplaceFirst() << endl;
	file << "Testing Replace(All): " << TestReplaceAll() << endl;
	file << "Testing Input(): " << TestInput() << endl;
	file << "Testing Print(): " << TestPrint(' ') << endl;
	file << "Testing Print(newline): " << TestPrint('n') << endl;
	file << "Testing Print(tab): " << TestPrint('t') << endl;
	file << "Testing Print(Prefixed space): " << TestPrint('p') << endl;
	file << "Testing Print(Suffixed space): " << TestPrint('s') << endl << endl;

	file.close();
}
