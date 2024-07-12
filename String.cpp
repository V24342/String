#include<iostream>
#include<cstring>
#include"String.h"
using namespace std;

String::String(const char* s) {
	if (s == nullptr) {
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else {
		len = strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
	}
}

String::String(const String& s) {
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::~String() {
	delete[] str;
}

String String::operator+(const String& s) const {
	String temp;
	temp.len = len + s.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, str);
	strcat(temp.str, s.str);
	return temp;
}

String& String::operator=(const String& s) {
	if (this != &s) {
		delete[] str;
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	return *this;
}

String& String::operator+=(const String& s) {
	char* tempStr = new char[len + s.len + 1];
	strcpy(tempStr, str);
	strcat(tempStr, s.str);
	delete[] str;
	str = tempStr;
	len += s.len;
	return *this;
}

bool String::operator==(const String& s) const {
	if (len != s.len) {
		return false;
	}
	else {
		return strcmp(str, s.str) ? false : true;
	}
}

char& String::operator[](int n) {
	if (n >= len) {
		return str[len - 1];
	}
	else {
		return str[n];
	}
}

const char& String::operator[](int n) const {
	if (n >= len) {
		return str[len - 1];
	}
	else {
		return str[n];
	}
}

int String::length() const {
	return len;
}