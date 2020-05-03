#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::swap;

class MyString {
public:
	MyString();										// конструктор по умолчанию
	MyString(const MyString &string);				// конструктор копирования
	MyString(const char *string);					// конструктор копирования
	~MyString();									// деструктор

	MyString& operator =(const MyString &string);	// оператор присваивания копированием
	MyString& operator =(const char *string);		// оператор присваивания копированием

	MyString operator +(const MyString &string) const; // сложение
	MyString operator +(const char *string) const;	   // сложение

	MyString& operator +=(const MyString& string);	// сложение и присваивание
	MyString& operator +=(const char *string);		// сложение и присваивание

	bool operator ==(const MyString& string) const;	// равенство строк
	bool operator ==(const char* string) const;		// равенство строк

	MyString reverse() const; // разворот строки
	unsigned size() const;	  // размер
	bool isEmpty() const; // проверка, пустая ли строка

	// В идеале для каждого объекта должно возвращаться уникальное число, но можно и
	// просто сумму символов вернуть. Однажды посчитанное значение, должно кэшироваться в
	// соответствующее поле класса, таким образом при следующих вызовах будет возвращаться
	// значение этого поля, если содержимое строки не было изменено с момента прошлого
	// вызова
	int hash() const;

	// Преобразует число в строку: auto str = MyString::number(1234); str = "1234";
	static MyString number(int n);

	friend std::ostream& operator <<(std::ostream& stream, const MyString &string)
	{
		stream << string._data;
		return stream;
	}

	friend std::istream& operator >>(std::istream& stream, const MyString &string)
	{
	    stream >> string._data;
		return stream;
	}

	//Добавил для себя
	//MyString(int length, const char* string);

private:
	char *_data;
	unsigned int _size;
	int _hash;
};


