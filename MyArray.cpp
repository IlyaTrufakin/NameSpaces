#include "MyArray.h"
#include<iostream>


namespace MyArray
{
	size_t Array::ObjectsCount = 0;

	Array::Array() : size{ 0 }, pNumArray{ nullptr }
	{
		ObjectsCount++;
	}

	Array::Array(unsigned size) : size{ size }, pNumArray{ new int[size] }
	{
		ObjectsCount++;
	}

	//конструктор копирования
	Array::Array(const Array& copy) : size{ copy.size }, pNumArray{ new int[size] }
	{
		for (size_t i = 0; i < this->size; i++)
		{
			this->pNumArray[i] = copy.pNumArray[i];
		}
		ObjectsCount++;
	}

	//конструктор перемещения
	Array::Array(Array&& moveObject) : size{ moveObject.size }, pNumArray{ moveObject.pNumArray }
	{
		moveObject.pNumArray = nullptr;
		moveObject.size = 0;
		ObjectsCount++;
	}


	// оператор переноса
	Array& Array::operator=(Array&& moveObject)
	{
		if (this != &moveObject)
		{
			if (this->pNumArray)
			{
				delete[] this->pNumArray;
			}
			this->size = moveObject.size;
			this->pNumArray = moveObject.pNumArray;
			moveObject.pNumArray = nullptr;
			moveObject.size = 0;

		}
		return *this;
	}


	// оператор присваивания/копирования
	Array& Array::operator=(const Array& Object)
	{
		if (this != &Object)
		{
			if (this->pNumArray != nullptr)
			{
				delete[] this->pNumArray;
			}
			this->size = Object.size;
			this->pNumArray = new int[this->size];
			for (unsigned i = 0; i < this->size; i++)
			{
				this->pNumArray[i] = Object.pNumArray[i];
			}
		}

		return *this;
	}



	Array Array::operator+(const int& number)
	{
		Array temporary;
		if (this->size)
		{
			temporary.size = this->size;
			temporary.pNumArray = new int[temporary.size];
			for (unsigned i = 0; i < temporary.size; i++)
			{
				temporary.pNumArray[i] = this->pNumArray[i] + number;
			}
		}
		return temporary;
	}




	void Array::Print()
	{
		cout << endl << endl << "Print array elements, for object: " << this << " (Size is: " << this->size << ")" << endl;

		if (this->pNumArray)
		{

			for (unsigned i = 0; i < this->size; i++)
			{
				cout << this->pNumArray[i] << "\t";
			}
			cout << endl;
			for (unsigned i = 0; i < this->size; i++)
			{
				cout << "--------";
			}
			cout << endl;
		}
		else
		{
			cout << "Print-function: array has no elements" << endl;
		}
		cout << "Number of objects: " << Array::GetObjectsCount() << endl;
	}

	void Array::FillRandom(int min, int max)
	{
		for (unsigned i = 0; i < this->size; i++)
		{
			this->pNumArray[i] = max - (rand() % (max - min + 1));
		}
	}

	unsigned Array::GetSize()
	{
		return size;
	}

	int Array::max()
	{
		if (this->size)
		{
			int temp_max = this->pNumArray[0];
			for (size_t i = 0; i < this->size; i++)
			{
				if (this->pNumArray[i] > temp_max)
				{
					temp_max = this->pNumArray[i];
				}
			}
			return temp_max;
		}
		cout << endl << "Max-function: array has no elements, size is: " << this->size;
		return 0;
	}

	int Array::min()
	{
		if (this->size)
		{
			int temp_min = this->pNumArray[0];
			for (size_t i = 0; i < this->size; i++)
			{
				if (this->pNumArray[i] < temp_min)
				{
					temp_min = this->pNumArray[i];
				}
			}
			return temp_min;
		}
		cout << endl << "Min-function: array has no elements, size is: " << this->size;
		return 0;
	}

	Array& Array::AscendSort()	// сортировка вставками
	{
		if (this->size)
		{
			for (unsigned i = 1; i < this->size; i++)
			{
				int t = this->pNumArray[i];
				int k = i;
				while (k - 1 >= 0 && this->pNumArray[k - 1] > t)
				{
					this->pNumArray[k] = this->pNumArray[k - 1];
					k--;
				}
				this->pNumArray[k] = t;
			}
			cout << endl << "Ascending sort an object: " << this << "  - executed.";
		}
		else
		{
			cout << endl << "Sort-function: array has no elements, size is: " << this->size;
		}
		return *this;
	}

	Array& Array::DescendSort()
	{
		if (this->size)
		{
			for (unsigned i = 1; i < this->size; i++)
			{
				int t = this->pNumArray[i];
				int k = i;
				while (k - 1 >= 0 && this->pNumArray[k - 1] < t)
				{
					this->pNumArray[k] = this->pNumArray[k - 1];
					k--;
				}
				this->pNumArray[k] = t;
			}
			cout << endl << "Descending sort an object: " << this << "  - executed.";
		}
		else
		{
			cout << endl << "Sort-function: array has no elements, size is: " << this->size;
		}
		return *this;
	}



	void Array::SetSize(unsigned newSize, int fillValue)
	{
		if (newSize)
		{
			int* temp = new int[newSize];
			for (size_t i = 0; i < newSize; i++)
			{
				if (i < this->size)
				{
					temp[i] = this->pNumArray[i];
				}
				else
				{
					temp[i] = fillValue;
				}
			}
			if (this->pNumArray)
			{
				delete[] this->pNumArray;
			}
			this->pNumArray = temp;
			temp = nullptr;
			this->size = newSize;
		}
		else
		{
			if (this->pNumArray)
			{
				delete[] this->pNumArray;
				pNumArray = nullptr;
				this->size = 0;
				cout << endl << "Array deleted by Setsize-func";
			}
			else
			{
				cout << endl << "Setsize-func: array has no elements, size is: " << this->size;
			}
		}
	}





	Array::~Array()
	{
		if (this->pNumArray)
		{
			delete[] this->pNumArray;
		}

		ObjectsCount--;
	}



}