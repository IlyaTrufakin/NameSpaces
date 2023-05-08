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
		String(); // ����������� �� ��������� - �������� ������ 80 ���� + 1 ��� �����������.
		String(const unsigned size);// ����������� - �������� ������ SIZE ���� + 1 ��� �����������.
		String(const char* string);// ����������� - �������� ������ ������ ������ � *string + 1 ��� �����������, � ����������� ��.
		String(const String& copyobj); // ����������� �����������.
		String(String&& moveobj); // ����������� �����������.
		~String();
		String& operator=(String&& obj);  // ���������� ��������� �����������
		String& operator=(const String& obj);  // ���������� ��������� ������������
		String operator+(const String& obj);  // ���������� ��������� ������������
		String& operator++();  // ���������� ��������� ����������
		String operator++(int);  // ���������� ��������� �����������
		void print();// ����� ������ ������ � �������.
		static char* GetString(char*& str);// ����� ����� ������ � �������.
		static int GetObjectsCount() { return ObjectsCount; }
	};
}


