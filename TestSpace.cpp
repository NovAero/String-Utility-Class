#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

String TestLen(String text);
String TestCharAt(String text);
String TestIsEqual(String text);
String TestToLower();
String TestToUpper();
String TestSuffix(String text);
String TestPrefix(String text);
String TestFind(String text);
String TestReplaceFirst(String text);
String TestReplaceAll(String text);
String TestInput(String text);
String TestPrint(String text, char mod);

int main() {

	String text = "elephant dog bird rat elephant";

	String find = "elephant";
	String replace = "dog";	

	cout << "Test Text: " << text.GetData() << '\n';
	cout << "Date: " <<__DATE__ << " Time: " << __TIME__ << '\n';

	cout << "Testing len(): " << TestLen(text).GetData() << endl;
	cout << "Testing CharAt(): " << TestCharAt(text).GetData() << endl;
	cout << "Testing IsEqual(): " << TestIsEqual(text).GetData() << endl;
	cout << "Testing ToLower(): " << TestToLower().GetData() << endl;
	cout << "Testing ToUpper(): " << TestToUpper().GetData() << endl;
	cout << "Testing Suffix(): " << TestSuffix(text).GetData() << endl;
	cout << "Testing Prefix(): " << TestPrefix(text).GetData() << endl;
	cout << "Testing Find(): " << TestFind(text).GetData() << endl;
	cout << "Testing Replace(First): " << TestReplaceFirst(text).GetData() << endl;
	cout << "Testing Replace(All): " << TestReplaceAll(text).GetData() << endl;
	cout << "Testing Input(): " << TestInput(text).GetData() << endl;
	cout << "Testing Print(): " << TestPrint(text, ' ').GetData() << endl;
	cout << "Testing Print(newline): " << TestPrint(text, 'n').GetData() << endl;
	cout << "Testing Print(tab): " << TestPrint(text, 't').GetData() << endl;
	cout << "Testing Print(Prefixed space): " << TestPrint(text, 'p').GetData() << endl;
	cout << "Testing Print(Suffixed space): " << TestPrint(text, 's').GetData() << endl;
}

String TestLen(String text)
{
	if(text.len() != 30) {
		return "Failure";
	}
	return "Success";
}

String TestCharAt(String text)
{
	if (text.CharAt(3) != 'p') {
		return "Failure";
	}
	return "Success";
}

String TestIsEqual(String text)
{
	if (text.IsEqual("elephant dog bird rat elephant") != true) {
		return "Failure";
	}
	return "Success";

}

String TestToLower()
{
	String text = "elepHaNt dog bIRd raT elePhanT";
	text.ToLower();
	if (text.IsEqual("elephant dog bird rat elephant") == false) {
		return "Failure";
	}
	return "Success";
}

String TestToUpper()
{
	String text = "elepHaNt dog bIRd raT elePhanT";
	text.ToUpper();
	if (text.IsEqual("ELEPHANT DOG BIRD RAT ELEPHANT") == false) {
		return "Failure";
	}
	return "Success";
}

String TestSuffix(String text)
{
	String sText = text;
	sText.Suffix("bird");

	if (sText.len() != text.len() + strlen("bird")) {
		return "Failure";
	}
	else if (sText.Find("elephant dog bird rat elephantbird") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestPrefix(String text)
{
	String pText = text;
	pText.Prefix("bird");

	if (pText.len() != text.len() + strlen("bird")) {
		return "Failure";
	}
	if (pText.Find("birdelephant") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestFind(String text)
{
	String find = "elephant";
	if (text.Find(10,find) != 22) {
		return "Failure";
	}
	return "Success";
}

String TestReplaceFirst(String text)
{
	String find = "elephant";
	String replace = "dog";
	String temp = text;
	temp.Replace(find, replace);

	if (temp.Find("dog dog bird rat elephant") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestReplaceAll(String text)
{
	String find = "elephant";
	String replace = "dog";
	String temp = text;
	temp.Replace(find, replace, true);

	if (temp.Find("dog dog bird rat dog") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestInput(String text)
{ 
	return  "";
}

String TestPrint(String text, char mod)
{
	int eotIndex = text.len();
	String ptr = text.Print(mod);


	switch (mod) {

		case 'n': //returns data with a new line after
			if (ptr[eotIndex] != '\n') {
				return "Failure";
			} 
			return "Success";
			break;
		case 't': //returns data with a tab after it
			if (ptr[eotIndex] != '\t') {
				return "Failure";
			}
			return "Success";
			break;

		case 'p': //returns data with a space before (p stands for prefix)
			if (ptr[0] != ' ') {
				return "Failure";
			}
			return "Success";
			break;

		case's': //returns data with a space after (s stands for suffix)
			if (ptr[eotIndex] != ' ') {
				return "Failure";
			}
			return "Success";
			break;

		default: //just returns data with no mods if the modifier param != valid mod
			if (ptr != text) {
				return "Failure";
			}
			return "Success";
	}
}