#pragma once

class String
{
public: // Constructors // 

	String();

	String(char ch);
	
	String(const char* str);
	
	String(String& copy);
	String(const String& copy);

	~String();

public: // Overrides //

	bool operator==(const String& other);
	bool operator!=(const String& other);

	bool operator<(const String& str);

	bool operator>=(const String& str);
	bool operator<=(const String& str);

	String& operator+(const String& str);
	String& operator+=(const String& str);

	String& operator=(const char* str);
	String& operator=(const String& str);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

public: // Functions //

	const char* GetData() const;

	void SetData(char toSet);
	void SetData(const char* toSet);

	size_t len() const;
	
	char& CharAt(size_t index);
	const char& CharAt(size_t index) const;

	bool IsEqual(const String& other) const;
	
	String& Suffix(const String& str);
	String& Prefix(const String& str);

	const char* Cstr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& str);
	size_t Find(size_t _startindex, const String& str);

	String& Replace(const String& _find, const String& _replace);

	String& Input();
	String& Print() const;
	String& Print(char modifier) const;

private:

	//Clamp for capital letters in ASCII
	const int capBnds[2] = {65,90};

	//Clamp for lowercase letters in ASCII
	const int lwrBnds[2] = {97,122};

	//Case change +- offset
	const int asciiOffset = 32;

	//String variable contents
	char* data;

};