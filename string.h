#pragma once

class String
{
public:

	String();
	String(const char* _str);

	String(const String& _other);

	~String();

public:
	size_t len() const;
	char& charAt(size_t _index);
	const char& charAt(size_t _index) const;

	bool isEqual(const String& _other) const;
	
	String& suf(const String& _str);
	String& pre(const String& _str);

	const char* cstr() const;

	String& toLow(char* input);
	String& toUp(char* input);

	size_t find(const String& _str);
	size_t find(size_t _startindex, const String& _str);

	String& replace(const String& _find, const String& _replace);

	String& input();
	String& print();

public:
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	String& operator=(const String& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

private:

	//Dynamic const length for Copy functions
	const int iterations = 0;
	int* iterPtr = const_cast<int*>(&iterations);


	//String variable contents
	char* data;

};