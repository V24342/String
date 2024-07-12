#ifndef STRING
#define STRING
#pragma warning(disable:4996)
#include<iostream>
using namespace std;

class String {
public:
	String(const char* s = nullptr);
	String(const String& s);
	~String();
	String operator+(const String& s) const;
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s) const;
	char& operator[](int n);
	const char& operator[](int n) const;
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	int length() const;
private:
	char* str;
	int len;
};

#endif