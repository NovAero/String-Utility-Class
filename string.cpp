#include "string.h"
#include <iostream>
#include <cstring>

//Constructors/Deconstructors

String::String()
{
	data = new char[1];
	data[0] = '\0';

}

String::String(const char* _str)
{	

	int length = strlen(_str);
	data = new char[(length) + 1];
	
	for (int i = 0; i < strlen(_str);i++) {

		data[i] = _str[i];

	}

	*iterPtr = length;
	std::cout << length << std::endl;

}


String::String(const String& _other)
{
	int length = _other.iterations;

	data = new char[( length + 1 )];

	for (char i = 0; i < length; i++) {
		
		data[i] = _other[i];

	}
	data[length] = '\0';
}


String::~String()
{

	delete data;

}

//Functions


size_t String::len() const
{
	int length = 0;

	for (char i = 0; data[i] != '\0'; i++) {
		length++;
	}

	return length;
}

char& String::charAt(size_t _index)
{	
	char* ptr = data;

	if (_index < 0 || _index > strlen(data)) {
		return ptr['\0'];

	} else {

		for (int i = 0; i < _index; i++) {

			if (i == _index) {
			
				return ptr[_index];
			
			}
		}

	}
}

const char& String::charAt(size_t _index) const
{
	const char* ptr = data;

	if (_index < 0 || _index > strlen(data)) {
		return ptr['\0'];
	}
	else {
		for (int i = 0; i < _index; i++) {
			if (i == _index) {
				return ptr[_index];
			}
		}
	}
}

bool String::isEqual(const String& _other) const
{
	for (int i = 0; i < sizeof(_other); i++) {
		if (data[i] == _other[i]) {
			continue;
		} else {
			return 0;
		}
		return 1;
	}
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
