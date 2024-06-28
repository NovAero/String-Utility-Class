#include "string.h"
#include <iostream>
#include <cstring>

//Constructors/Deconstructors

String::String()
{

	data = new char[1];
	data[0] = '\0';

}

String::String(char ch) 
{
	setData(ch);
}

String::String(const char* str)
{	

	setData(str);

}

String::String(String& copy)
{

	setData(copy.getData());

}

String::String(const String& copy)
{
	
	setData(const_cast<char*>(copy.getData()));

}

String::~String()
{

	delete data;

}

// Functions

const char* String::getData() const
{
	return data;
}

void String::setData(char toSet)
{
	data = new char[2];
	data[0] = toSet;
	data[1] = '\0';
}

void String::setData(const char* toSet)
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

char& String::charAt(size_t index)
{	
	return data[index];
}

const char& String::charAt(size_t index) const
{
	return data[index];
}

bool String::isEqual(const String& other) const
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


//Overrides


bool String::operator==(const String& other)
{
	return isEqual(other);
}

bool String::operator!=(const String& other)
{
	return (data != other.getData());
}

String& String::operator=(const String& str)
{
	String temp;
	temp.setData(const_cast<char*>(str.getData()));
	return temp;
}

char& String::operator[](size_t index)
{
	return data[index];
}

const char& String::operator[](size_t index) const
{
	return data[index];
}
