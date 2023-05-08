#include <iostream>
#include"MyArray.h"
#include"MyString.h"

//В рамках попередніх самостійних і домашніх завдань ви створили набір класів для роботи з різними примітивними 
//математичними операціями(дріб, точка в двови 	мірному просторі, точка в тривимірному просторі і т.д.).
//Додайте вже створені класи в простори імен.Продумайте правильну структуру створених просторів.
//Використовуючи механізм просторів напишіть код з тестування отриманої програми.

int main()
{
	MyArray::Array Arr1;
	Arr1 = MyArray::Array(6); 
	Arr1.FillRandom(-30, 30);
	Arr1.Print();

	MyString::String str1;
	str1 = "test string class";
	str1.print();

	using namespace MyArray;
	Array Arr2(8);
	Arr2.FillRandom(-30, 30);
	Arr2.Print();

}

