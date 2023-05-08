#include "MyString.h"

namespace MyString
{

	int String::ObjectsCount = 0;

	String::String() : size{ 80 }, MyString{ new char[size + 1] }
	{
		if (!MyString)
		{
			cout << endl << "Memory allocation error for object: " << this;
			exit(0);
		}
		this->MyString[size] = 0;
		_strset_s(this->MyString, size + 1, 32);
		ObjectsCount++;
	}

	String::String(const unsigned size) : size{ size }, MyString{ new char[size + 1] }
	{
		if (!MyString)
		{
			cout << endl << "Memory allocation error for object: " << this;
			exit(0);
		}
		this->MyString[size] = 0;
		_strset_s(this->MyString, size + 1, 32);
		ObjectsCount++;
	}

	String::String(const char* string) :size{ strlen(string) }, MyString{ new char[size + 1] }
	{
		if (!MyString)
		{
			cout << endl << "Memory allocation error for object: " << this;
			exit(0);
		}
		strcpy_s(this->MyString, size + 1, string);
		ObjectsCount++;
	}

	//конструктор копирования.
	String::String(const String& copyobj) : size{ strlen(copyobj.MyString) }, MyString{ new char[size + 1] }
	{
		if (!MyString)
		{
			cout << endl << "Memory allocation error for object: " << this;
			exit(0);
		}
		strcpy_s(this->MyString, size + 1, copyobj.MyString);
		ObjectsCount++;
	}

	// конструктор перемещения.
	String::String(String&& moveobj)
	{
		this->size = moveobj.size;
		this->MyString = moveobj.MyString;
		moveobj.MyString = nullptr;
		moveobj.size = 0;
		ObjectsCount++;
	}

	String::~String()
	{
		if (this->MyString != NULL)
		{
			delete[] MyString;
			this->MyString = nullptr;
		}

		ObjectsCount--;
	}

	String& String::operator=(String&& moveobj)
	{
		if (this != &moveobj)
		{
			if (this->MyString)
			{
				delete[] this->MyString;
			}
			this->size = moveobj.size;
			this->MyString = moveobj.MyString;
			moveobj.MyString = nullptr;
			moveobj.size = 0;
		}
		return *this;
	}

	String& String::operator=(const String& obj)
	{
		if (this != &obj)
		{
			if (this->MyString)
			{
				delete[] this->MyString;
			}
			this->size = obj.size;
			this->MyString = new char[this->size + 1];
			if (!this->MyString)
			{
				cout << endl << "Memory allocation error for object: " << this;
				exit(0);
			}
			strcpy_s(this->MyString, this->size + 1, obj.MyString);
		}
		return *this;
	}

	String String::operator+(const String& obj)
	{
		if (this->size + obj.size)
		{
			char* tempString = new char[this->size + obj.size + 1];
			strcpy_s(tempString, this->size + 1, this->MyString);
			strcat_s(tempString, this->size + obj.size + 1, obj.MyString);
			String tempObject(tempString);
			delete[] tempString;
			return tempObject;
		}

		else
		{
			return String(0U);
		}
	}

	String& String::operator++()
	{
		*this = *this + String("x");
		return *this;
	}

	String String::operator++(int)
	{
		String tempObject = *this;
		*this = *this + String("x"); // здесь вызывается оператор присваивания с перемещением.
		return tempObject;
	}



	void String::print()
	{
		cout << endl << this->MyString;
	}



	char* String::GetString(char*& str)
	{
		cout << endl << "Enter a string: ";
		char ch;
		int n = 0;
		if (str) free(str);
		str = nullptr;
		while ((ch = getchar()) != '\n')
		{
			str = (char*)realloc(str, n + 1);
			str[n] = ch;
			n++;
		}
		str = (char*)realloc(str, n + 1);
		str[n] = 0;
		return str;
	}
}