#pragma once
#include<iostream>

namespace MyArray
{
using namespace std;
	class Array
	{
		unsigned size;
		int* pNumArray;
		static size_t ObjectsCount;

	public:
		Array();
		explicit Array(unsigned size);
		Array(const Array& copy); // ����������� �����������
		Array(Array&& moveObject);// ����������� �����������
		Array& operator=(const Array& Object);// �������� ������������
		Array& operator=(Array&& moveObject);// �������� �����������
		Array operator+(const int& number);// �������� + ���������� ����� � ������� �������� ������� (��� ������������ ������ ������������ �����������)
		void Print();
		void FillRandom(int min = -10, int max = 10);
		unsigned GetSize();
		int max();
		int min();
		Array& AscendSort();
		Array& DescendSort();
		void SetSize(unsigned newSize, int fillValue = 0);
		static size_t GetObjectsCount() { return ObjectsCount; }
		~Array();
	};

}

