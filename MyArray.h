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
		Array(const Array& copy); // конструктор копирования
		Array(Array&& moveObject);// конструктор перемещения
		Array& operator=(const Array& Object);// оператор присваивания
		Array& operator=(Array&& moveObject);// оператор перемещения
		Array operator+(const int& number);// оператор + прибавляет число к каждому элементу массива (для демонстрации работы конструктора перемещения)
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

