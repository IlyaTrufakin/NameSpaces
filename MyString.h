#pragma once
#include<iostream>
namespace MyString
{
	using namespace std;
	class String
	{
		size_t size;
		char* MyString;
		static int ObjectsCount;

	public:
		String(); // конструктор по умолчанию - создание строки 80 симв + 1 для терминатора.
		String(const unsigned size);// конструктор - создание строки SIZE симв + 1 для терминатора.
		String(const char* string);// конструктор - создание строки длиной строки в *string + 1 для терминатора, и копирование ее.
		String(const String& copyobj); // конструктор копирования.
		String(String&& moveobj); // конструктор перемещения.
		~String();
		String& operator=(String&& obj);  // перегрузка оператора перемещения
		String& operator=(const String& obj);  // перегрузка оператора присваивания
		String operator+(const String& obj);  // перегрузка оператора конкатенации
		String& operator++();  // перегрузка оператора префиксная
		String operator++(int);  // перегрузка оператора постфиксная
		void print();// метод печати строки в консоль.
		static char* GetString(char*& str);// метод ввода строки с консоли.
		static int GetObjectsCount() { return ObjectsCount; }
	};
}


