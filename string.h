#pragma once

class String
{
public:

	String();
	String(char _char);
	String(const char* _str);
	String(String& _copy);
	String(const String& _copy);

	~String();

public:

	const char* getData() const;

	void setData(char toSet);
	void setData(const char* toSet);

	
	size_t len() const;
	
	char& charAt(size_t _index);
	const char& charAt(size_t _index) const;

	bool isEqual(const String& _other) const;
	
	String& suffix(const String& _str);
	String& prefix(const String& _str);

	const char* cstr() const;

	String& toLower(char* input);
	String& toUper(char* input);

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

	//String variable contents
	char* data;

};