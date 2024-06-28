#include "string.h"
#include <iostream>
#include <cstring>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						 // Constructors / Deconstructor //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

String::String()
{

	data = new char[1];
	data[0] = '\0';

}

String::String(char ch) 
{
	SetData(ch);
}

String::String(const char* str)
{	

	SetData(str);

}

String::String(String& copy)
{

	SetData(copy.GetData());

}

String::String(const String& copy)
{
	
	SetData(const_cast<char*>(copy.GetData()));

}

String::~String()
{

	delete data;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
								  // Overrides //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


bool String::operator==(const String& other)
{
	return IsEqual(other);
}

bool String::operator!=(const String& other)
{
	return (data != other.GetData());
}

bool String::operator<(const String& str)
{
	//NOTE returns true if LHS is first alphabetically, not case sensitive

	bool orderFound = false;
	int index = 0;

	String lhs = data;
	String rhs = str;

	rhs.ToLower();
	lhs.ToLower();

	while (orderFound == false) {
		if (lhs[index] > rhs[index]) {
			orderFound = true;
			return false;

		}
		else if (lhs[index] < rhs[index]) {
			orderFound = true;
			return true;
		}
		else {
			index++;
		}
	}
}

String& String::operator+(const String& str)
{
	return Suffix(str);
}

String& String::operator+=(const String& str)
{
	return Suffix(str);
}

String& String::operator=(const char* str)
{
	String tmp;
	tmp.SetData(str);
	return tmp;
}

String& String::operator=(const String& str)
{
	String tmp;
	tmp.SetData(const_cast<char*>(str.GetData()));
	return tmp;
}

char& String::operator[](size_t index)
{
	return data[index];
}

const char& String::operator[](size_t index) const
{
	return data[index];
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                  // Functions //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


const char* String::GetData() const
{
	return data;
}

void String::SetData(char toSet)
{
	data = new char[2];
	data[0] = toSet;
	data[1] = '\0';
}

void String::SetData(const char* toSet)
{
	int l = strlen(toSet);

	data = new char[l + 1];

	for (int i = 0; i < l; i++) {

		data[i] = toSet[i];

	}
	if (data[l - 1] != '\0') {
		data[l] = '\0';
	}
}

size_t String::len() const
{

	return strlen(data);

}

char& String::CharAt(size_t index)
{	
	return data[index];
}

const char& String::CharAt(size_t index) const
{
	return data[index];
}

bool String::IsEqual(const String& other) const
{
	int a = strlen(data);
	int b = other.len();

	if (a != b) {
		return false;
	}

	for (int i = 0; i < a; ++i) {
		if (data[i] == other[i]) {
			continue;
		}
		else {
			return false;
		}
	}	return true;
}

String& String::Suffix(const String& str)
{
	int strSize = str.len();
	int dataSize = strlen(data);
	int newStrSize = dataSize + strSize;

	String tmp = new char[dataSize + 1];
	tmp.SetData(data);

	data = new char[newStrSize + 1];

	for (int i = 0; i < dataSize; ++i) {
		data[i] = tmp[i];

	}
	for (int j = 0; j < strSize; ++j) {
		data[dataSize+j] = str[j];

	}
	if (data[newStrSize - 1] != '\0') {
		data[newStrSize] = '\0';
	}
	return *this;
}

String& String::Prefix(const String& str)
{
	int strSize = str.len();
	int dataSize = strlen(data);
	int newStrSize = dataSize + strSize;

	String tmp = new char[dataSize + 1];
	tmp.SetData(data);

	data = new char[newStrSize + 1];

	for (int i = 0; i < strSize; ++i) {
		data[i] = str[i];

	}
	for (int j = 0; j < dataSize; ++j) {

		data[strSize+j] = tmp[j];

	}

	if (data[newStrSize - 1] != '\0') {
		data[newStrSize] = '\0';
	}

	return *this;
}

const char* String::Cstr() const
{
	return GetData();
}

String& String::ToLower()
{
	//Uses ASCII values to clamp ranges for casechanges

	for (int i = 0; i < *GetData(); ++i) {
		if (data[i] >= capBnds[0] && data[i] <= capBnds[1]) {
			data[i] += asciiOffset;
		}
	}
	return *this;
}

String& String::ToUpper()
{
	//Uses ASCII values to clamp ranges for casechanges

	for (int i = 0; i < *GetData(); ++i) {
		if (data[i] >= lwrBnds[0] && data[i] <= lwrBnds[1]) {
			data[i] -= asciiOffset;
		}
	}

	return *this;
}

//size_t String::Find(const String& str)
//{
//	String 
//
//	return size_t();
//}

//size_t String::Find(const String& str)
//{
//	int l = str.len();
//
//	
//
//}
//
//size_t String::Find(size_t _startindex, const String& str)
//{
//	return size_t();
//}

String& String::Input()
{
	char input[32];

	std::cin.getline(input, 32, '\n');

	data = new char[strlen(input) + 1];

	SetData(input);

	return *this;
}

String& String::Print() 
{

	std::cout << data;

	return *this;
}

String& String::Print(char modifier)
{
	char mod = modifier;

	switch (mod) {

	case 'n':
		std::cout << data << std::endl;
		break;

	case 't':
		std::cout << data << "\t";
		break;

	case 'p':
		std::cout << " " << data;
		break;

	case's':
		std::cout << data << " ";
		break;

	default:
		std::cout << data;
		return *this;
	} 
}
