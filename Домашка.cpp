#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


#define delimiter "\n -----------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	char* str;
	int size;
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	//			constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy_s(this->str, size, str);
		cout << "Constructor:\t\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//			operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
		//MoveMethods
	}
	const char& operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}


	//			methods

	void print()const
	{
		cout << "str:\t" << str << endl;
		cout << "size:\t" << size << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	strcpy(result.get_str(), left.get_str());
	strcat(result.get_str(), right.get_str());
	return result;
}



ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define ConstructorsCheck
//#define AssignmentCheck


int main()
{
	setlocale(LC_ALL, "");
	system("color 0A");

#ifdef ConstructorsCheck
	String str;
	str.print();

	String str2(5);
	str2.print();

	cout << typeid("Hello").name() << endl;
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = str3;
	cout << "str4: - " << str4 << endl;

	String str5;
	str5 = str4;
	cout << "str5: - " << str5 << endl;
#endif // ConstructorsCheck

#ifdef AssignmentCheck
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;

	char a = '5';
	a = a;
	cout << a << endl;
#endif // AssignmentCheck

	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;
	String str3 = str1 + " " + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
}