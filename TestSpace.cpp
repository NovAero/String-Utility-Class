#include <iostream>
#include <fstream>
#include "String.h"

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

int main() {

	cout << "Test Text: " << "elephant dog bird rat elephant" << '\n';
	cout << "Date: " <<__DATE__ << " Time: " << __TIME__ << '\n';

	cout << "Testing len(): " << TestLen()<< endl;
	cout << "Testing CharAt(): " << TestCharAt() << endl;
	cout << "Testing IsEqual(): " << TestIsEqual() << endl;
	cout << "Testing ToLower(): " << TestToLower() << endl;
	cout << "Testing ToUpper(): " << TestToUpper() << endl;
	cout << "Testing Suffix(): " << TestSuffix() << endl;
	cout << "Testing Prefix(): " << TestPrefix() << endl;
	cout << "Testing Find(): " << TestFind() << endl;
	cout << "Testing Replace(First): " << TestReplaceFirst() << endl;
	cout << "Testing Replace(All): " << TestReplaceAll() << endl;
	cout << "Testing Input(): " << TestInput() << endl;
	cout << "Testing Print(): " << TestPrint(' ') << endl;
	cout << "Testing Print(newline): " << TestPrint('n') << endl;
	cout << "Testing Print(tab): " << TestPrint('t') << endl;
	cout << "Testing Print(Prefixed space): " << TestPrint('p')<< endl;
	cout << "Testing Print(Suffixed space): " << TestPrint('s')<< endl << endl;
	
	system("pause");
}

const char* TestLen()
{
	String text = "elephant dog bird rat elephant";
	if(text.len() != 30) {
		return "Failure";
	}
	return "Success";
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

	if (text.Find("dog dog bird rat elephant") == 0) {
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

	if (text.Find("dog dog bird rat dog") == 0) {
		return "Success";
	}
	return "Failure";
}

const char* TestInput()
{ 
	cout << "Please write: \"elephant\"";
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