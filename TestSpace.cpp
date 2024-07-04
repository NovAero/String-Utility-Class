#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

String TestLen();
String TestCharAt();
String TestIsEqual();
String TestToLower();
String TestToUpper();
String TestSuffix();
String TestPrefix();
String TestFind();
String TestReplaceFirst();
String TestReplaceAll();
String TestInput();
String TestPrint(char mod);

int main() {

	String find = "elephant";
	String replace = "dog";	

	fstream file;

	file.open("StringUtilityTests.txt", std::ios::out | std::ios::app);
	if (!file.is_open()) {
		cout << "File is open. Aborting";
		return 1;
	}

	file << "Test Text: " << "elephant dog bird rat elephant" << '\n';
	file << "Date: " <<__DATE__ << " Time: " << __TIME__ << '\n';

	file << "Testing len(): " << TestLen().GetData() << endl;
	file << "Testing CharAt(): " << TestCharAt().GetData() << endl;
	file << "Testing IsEqual(): " << TestIsEqual().GetData() << endl;
	file << "Testing ToLower(): " << TestToLower().GetData() << endl;
	file << "Testing ToUpper(): " << TestToUpper().GetData() << endl;
	file << "Testing Suffix(): " << TestSuffix().GetData() << endl;
	file << "Testing Prefix(): " << TestPrefix().GetData() << endl;
	file << "Testing Find(): " << TestFind().GetData() << endl;
	file << "Testing Replace(First): " << TestReplaceFirst().GetData() << endl;
	file << "Testing Replace(All): " << TestReplaceAll().GetData() << endl;
	file << "Testing Input(): " << TestInput().GetData() << endl;
	file << "Testing Print(): " << TestPrint(' ').GetData() << endl;
	file << "Testing Print(newline): " << TestPrint('n').GetData() << endl;
	file << "Testing Print(tab): " << TestPrint('t').GetData() << endl;
	file << "Testing Print(Prefixed space): " << TestPrint('p').GetData() << endl;
	file << "Testing Print(Suffixed space): " << TestPrint('s').GetData() << endl << endl;

	file.close();
}

String TestLen()
{
	String text = "elephant dog bird rat elephant";
	if(text.len() != 30) {
		return "Failure";
	}
	return "Success";
}

String TestCharAt()
{
	String text = "elephant dog bird rat elephant";
	if (text.CharAt(3) != 'p') {
		return "Failure";
	}
	return "Success";
}

String TestIsEqual()
{
	String text = "elephant dog bird rat elephant";
	if (text.IsEqual("elephant dog bird rat elephant") != true) {
		return "Failure";
	}
	return "Success";

}

String TestToLower()
{
	String text = "elephant dog bird rat elephant";
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

String TestSuffix()
{
	String text = "elephant dog bird rat elephant";
	text.Suffix("bird");

	if (text == "elephant dog bird rat elephantbird") {
		return "Success";
	}
	return "Failure";
}

String TestPrefix()
{
	String text = "elephant dog bird rat elephant";
	text.Prefix("bird");

	if (text == "birdelephant dog bird rat elephant") {
		return "Success";
	}
	return "Failure";
}

String TestFind()
{
	String text = "elephant dog bird rat elephant";
	String find = "elephant";
	if (text.Find(10,find) != 22) {
		return "Failure";
	}
	return "Success";
}

String TestReplaceFirst()
{
	String text = "elephant dog bird rat elephant";
	String find = "elephant";
	String replace = "dog";

	text.Replace(find, replace);

	if (text.Find("dog dog bird rat elephant") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestReplaceAll()
{
	String text = "elephant dog bird rat elephant";
	String find = "elephant";
	String replace = "dog";

	text.Replace(find, replace, true);

	if (text.Find("dog dog bird rat dog") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestInput()
{ 
	String text = "elephant dog bird rat elephant";
	//Cant test user input, testing for file I filled in
	char* temp = new char[text.len() + 1];

	fstream file;
	file.open("inputTest.txt", std::ios::in);
	if (!file.is_open()) {
		return "Failure";
	}
	file.getline(temp, sizeof(file));

	file.close();

	if (temp[text.len()] != '\0') {
		temp[text.len()] = '\0';
	}
	text.SetData(temp);

	if (text.Find("elephant dog bird rat elephant") != 0) {
		return "Failure";
	}
	return "Success";
}

String TestPrint(char mod)
{
	String text = "elephant dog bird rat elephant";
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
			if (ptr.Find("elephant dog bird rat elephant") != 0) {
				return "Failure";
			}
			return "Success";
	}
}