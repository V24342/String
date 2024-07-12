#include<iostream>
#include"String.h"
using namespace std;

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {
	char temp[1000];
	is >> temp;
	delete[] s.str;
	s.len = strlen(temp);
	s.str = new char[s.len + 1];
	strcpy(s.str, temp);
	return is;
}

int main() {
	String s1("JLU");
	String s2;
	s2 = s1;
	String s3(s1);
	String s4("NB");
	String s5 = s1 + s4;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s1的长度为: " << s1.length() << endl;
	cout << "s1[2] = " << s1[2] << endl;
	String s6 = s1 += (s4);
	cout << "s6: " << s6 << endl;
	return 0;
}