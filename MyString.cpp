#include "MyString.h"
#include <iostream>
#include <string>

using namespace std;

MyString::MyString() :
	_size(0),
	_data(new char('\0'))
{
    //cout << "Вызвался конструктор по умолчанию " << this << endl;
}


MyString::~MyString()
{
	delete[] _data;
	//cout << "Вызвался деструктор " << this << endl;
}

MyString::MyString(const MyString &string)
{
    //cout << "Вызвался конструктор копирования String " << this << endl;
	_size = string._size;
	_data = new char[_size + 1];

	strcpy(_data, string._data);

}

MyString::MyString(const char* string)
{
    //cout << "Вызвался конструктор копирования Char " << this << endl;

	_size = strlen(string);
	_data = new char[_size + 1];

	strcpy(_data, string);
}

MyString& MyString::operator =(const MyString &string)
{
    //cout << "Вызвался оператор присваивания String" << endl;

	if (this == &string)
		return *this;

	MyString buf(string);
	_size = buf._size;
	swap(this->_data, buf._data);

	return *this;
}

 MyString& MyString::operator =(const char *string)
{
    //cout << "Вызвался оператор присваивания Char" << endl;

    MyString buf(string);
    _size = buf._size;
    swap (_data, buf._data);

    return *this;
}

unsigned MyString::size() const
{
	return _size;
}

MyString MyString::operator +(const MyString &string) const
{
    // cout << "Вызвался оператор + Mystring " << endl;

     char *temp = new char[strlen(string._data) + this->_size + 1];
     strcpy(temp, _data);
     strcat(temp, string._data);
     MyString tempString(temp);

     delete temp;
     return tempString;
}

MyString MyString::operator +(const char *string) const
{
     //cout << "Вызвался оператор + Char " << endl;
    char *temp = new char[strlen(string) + this->_size + 1];
     strcpy(temp, _data);
     strcat(temp, string);
     MyString tempString(temp);

     delete temp;
     return tempString;
}

MyString& MyString::operator +=(const MyString& string)
{
    //cout << "Вызвался оператор += MyString " << endl;

    this->_size += string._size;
    char *temp = new char[_size];
    strcpy(temp, this->_data);
    strcat(temp, string._data);
    swap(_data, temp);

    delete temp;

    return *this;
}

MyString& MyString::operator +=(const char *string)
{
    //cout << "Вызвался оператор += Char " << endl;
    this->_size += strlen(string);
    char *temp = new char[_size];
    strcpy(temp, this->_data);
    strcat(temp, string);
    swap(_data, temp);

    delete temp;

    return *this;
}

bool MyString::operator ==(const MyString& string) const
{
    //cout << "Вызвался оператор == MyString " << endl;
	if (this == &string)
		return true;
    if (strcmp(_data, string._data) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator ==(const char* string) const
{

    //cout << "Вызвался оператор == Char " << endl;
    if (strcmp(this->_data, string) == 0)
    {
        return true;
    } else {
        return false;
    }
}
MyString MyString::reverse() const
{
    //cout << "Вызвался метод Reverse " << endl;
    char *temp = new char[_size];
    strcpy(temp, _data);

    for (int i = 0, j =_size - 1; i <j; i++, j--)
        swap(temp[i], temp[j]);

    MyString TempString(temp);
    delete temp;
    return TempString;

}

bool MyString :: isEmpty() const
{
    if(_size == 0)
    {
        return true;
    } else {
        return false;
    }
}

/*MyString :: MyString(int length, const char *string)
{
    _size = length;
    _data = new char[_size];
    strcpy(_data, string);
}*/

MyString MyString::number(int n)
{
    //cout << "Вызвался метод Number " << endl;

    string str = to_string(n);
    char *p = new char[str.length() + 1];
    strcpy (p, str.c_str());
    MyString temp(p);
    return temp;
}


