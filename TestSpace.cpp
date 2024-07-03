#include <iostream>
#include "String.h"

using namespace std;

void TestLen(String text);
void TestCharAt(String text, int index);
void TestIsEqual(String lhs, String rhs);
void TestToLower(String TEXT);
void TestToUpper(String text);
void TestSuffix(String text, String suffix);
void TestPrefix(String text, String prefix);
void TestFind(String find, String text);
void TestReplaceFirst(String text, String find, String replace);
void TestReplaceAll(String text, String find, String replace);
void TestInput(String text);
void TestPrint(String text);
void TestPrintMod(String text);

int main() {

	String text = "elephant dog bird rat elephant";
	String _text = "ELEphAnt";
	String find = "elephant";
	String replace = "dog";	

	cout << "Testing: len (Length)\n";
	TestLen(text);
	cout << "Testing: CharAt\n";
	TestCharAt(text, 3);
	TestCharAt(text, 5);
	TestCharAt(text, 100);
	cout << "Testing: IsEqual\n";
	TestIsEqual(text, find);
	TestIsEqual(_text, find);
	TestIsEqual(find, find);
	cout << "Testing: ToLower\n";
	TestToLower(_text);
	cout << "Testing: ToUpper\n";
	TestToUpper(_text);
	cout << "Testing: Suffix (Append)\n";
	TestSuffix(text, find);
	cout << "Testing: Prefix (Prepend)\n";
	TestPrefix(text, replace);
	cout << "Testing: Find\n";
	TestFind(find, text);
	cout << "Testing: Replace\n";
	TestReplaceFirst(text, find, replace);
	TestReplaceAll (text, find, replace);
	cout << "Testing: Input\n";
	TestInput(text);
	cout << "Testing: Print\n";
	TestPrint(text);
	TestPrintMod(text);
}

void TestLen(String text)
{
	cout << '\"' << text.GetData() << "\" is: " << text.len() << " characters long. \n \n";
}

void TestCharAt(String text, int index)
{

	if (index > text.len()) {
		cout << index << " is out of bounds! \n";
		cout << "Even though the index is longer, it wont return anything outside the bounds! \n";
		cout << "Setting the index to 0 so test can continue\n";
		index = 0;
	}
	char c = text.CharAt(index);
	cout << "The character at Index " << index << " (character " << index+1 << ") of " << text.GetData() << " is: " << c << "\n \n";
}

void TestIsEqual(String lhs, String rhs)
{
	bool equality = lhs.IsEqual(rhs);
	String print;

	if (equality == true) {
		print = "the same!";
	}
	else {
		print = "different";
	}

	cout << lhs.GetData() << " and " << rhs.GetData() << " are " << print.GetData() << "\n \n";

}

void TestToLower(String TEXT)
{
	cout << TEXT.GetData() << " to lowercase! ~ ";
	TEXT.ToLower();
	cout << TEXT.GetData() << "\n \n";

}

void TestToUpper(String text)
{
	cout << text.GetData() << " to uppercase! ~ ";
	text.ToUpper();
	cout << text.GetData() << "\n \n";
}

void TestSuffix(String text, String suffix)
{
	cout << text.GetData() << " is the first word, add \"" << suffix.GetData() << "\" to the end: \n";
	text.Suffix(suffix);
	cout << text.GetData() << "\n \n";

}

void TestPrefix(String text, String prefix)
{
	cout << text.GetData() << " is the first word, add \"" << prefix.GetData() << "\" infront: \n";
	text.Prefix(prefix);
	cout << text.GetData() << "\n \n";
}

void TestFind(String find, String text)
{
	int index = text.Find(find);

	if (index == -1) {
		cout << "\"" << find.GetData() << "\" is not in \"" << text.GetData() << "\"\n \n";
	}
	else {
		cout << "\"" << find.GetData() << "\" was found at index: " << index << " of \"" << text.GetData() << "\"\n \n";
	}
}

void TestReplaceFirst(String text, String find, String replace)
{
	cout << "Finding: \"" << find.GetData() << "\" in \"" << text.GetData() << "\", to replace the first with: \"" << replace.GetData() << "\"\n";
	text.Replace(find, replace);
	cout << "New text is: " << text.GetData() << "\n \n";

}

void TestReplaceAll(String text, String find, String replace)
{
	cout << "Finding \"" << find.GetData() << "\" in \"" << text.GetData() << "\", to replace all with: \"" << replace.GetData() << "\"\n";
	text.Replace(find, replace, true);
	cout << "New text is: " << text.GetData() << "\n \n";

}

void TestInput(String text)
{
	cout << "Type two words of any amount of char [Total must be less than 255]" << '\n';
	text.Input();
	cout << "You said: " << text.GetData() << "\n \n";

}

void TestPrint(String text)
{
	cout << "Printing: \"" << text.GetData() << "\": to the console by itself:\n";
	text.Print();
	cout << "printed with bad formatting :( \n\n";
}

void TestPrintMod(String text)
{
	cout << "Printing: " << text.GetData() << " to the console with a newline(n), tab(t), space before(p), and space after(s)!\n";
	text.Print('n');
	text.Print('t');
	cout << ";\n;";
	text.Print('p');
	cout << '\n';
	text.Print('s');
	cout << "; \n\n" ;
}
