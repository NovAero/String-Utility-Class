#pragma once

class String
{
public:

	String();

	String(char ch);
	
	String(const char* str);
	
	String(String& copy);
	String(const String& copy);

	~String();

public:
	bool operator==(const String& other);
	bool operator!=(const String& other);

	bool operator>(const String& str);
	bool operator<(const String& str);

	bool operator>=(const String& str);
	bool operator<=(const String& str);

	String& operator+(const String& str);
	String& operator-(const String& str);

	String& operator=(const char* str);
	String& operator=(const String& str);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	String operator<<(String& trg);
	String operator>>(String& trg);

public:
	const char* getData() const;

	void setData(char toSet);
	void setData(const char* toSet);

	size_t len() const;
	
	char& charAt(size_t index);
	const char& charAt(size_t index) const;

	bool isEqual(const String& other) const;
	
	String& suffix(const String& str);
	String& prefix(const String& str);

	const char* cstr() const;

	String& toLower(char* input);
	String& toUper(char* input);

	size_t find(const String& str);
	size_t find(size_t _startindex, const String& str);

	String& replace(const String& _find, const String& _replace);

	String& input();
	String& print();
	String& print(char modifier);

private:

	//String variable contents
	char* data;

};