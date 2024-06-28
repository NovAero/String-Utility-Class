#include "string.h"
#include <iostream>
#include <cstring>

//Constructors/Deconstructors

String::String()
{
	data = new char[1];
	data[0] = '\0';

}

String::String(char _char) 
{
	setData(_char);
}

String::String(const char* _str)
{	

	setData(_str);

}

String::String(String& _copy)
{

	setData(_copy.getData());

}

String::String(const String& _copy)
{
	
	setData(const_cast<char*>(_copy.getData()));

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

	data = new char[l];	

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

char& String::charAt(size_t _index)
{	
	return data[_index];
}

const char& String::charAt(size_t _index) const
{
	return data[_index];
}

bool String::isEqual(const String& _other) const
{
	return false;
}


//Overrides

bool String::operator!=(const String& _other)
{
	return !(data == _other.getData());
}

char& String::operator[](size_t _index)
{
	return data[_index];
}

const char& String::operator[](size_t _index) const
{
	return data[_index];
}
