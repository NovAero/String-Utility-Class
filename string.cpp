#include "string.h"
#include <iostream>

//Constructors/Deconstructors

String::String()
{
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* _str)
{

	data = new char[sizeof(_str)];

	for (int i = 0; i < sizeof(_str); i++) {

		data[i] = _str[i];

	}
}

String::String(const String& _other)
{

	data = new char[sizeof(_other)];

	for (int i = 0; i < sizeof(_other); i++) {

		data[i] = _other[i];

	}
}

String::~String()
{

	delete data;

}

//Overrides

char& String::operator[](size_t _index)
{
	char* ptr = data;
	return ptr[_index];
}

const char& String::operator[](size_t _index) const
{
	const char* ptr = data;
	return ptr[_index];
}
