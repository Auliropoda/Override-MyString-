#include "MyString.h"
#include <iostream>
#include <string>

using namespace std;

MyString::MyString() :
	_size(0),
	_data(new char('\0'))
{
    //cout << "�������� ����������� �� ��������� " << this << endl;
}


MyString::~MyString()
{
	delete[] _data;
	//cout << "�������� ���������� " << this << endl;
}

MyString::MyString(const MyString &string)
{
    //cout << "�������� ����������� ����������� String " << this << endl;
	_size = string._size;
	_data = new char[_size + 1];

	strcpy(_data, string._data);

}

MyString::MyString(const char* string)
{
    //cout << "�������� ����������� ����������� Char " << this << endl;

	_size = strlen(string);
	_data = new char[_size + 1];

	strcpy(_data, string);
}

MyString& MyString::operator =(const MyString &string)
{
    //cout << "�������� �������� ������������ String" << endl;

	if (this == &string)
		return *this;

	MyString buf(string);
	_size = buf._size;
	swap(this->_data, buf._data);

	return *this;
}

 MyString& MyString::operator =(const char *string)
{
    //cout << "�������� �������� ������������ Char" << endl;

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
    // cout << "�������� �������� + Mystring " << endl;

     char *temp = new char[strlen(string._data) + this->_size + 1];
     strcpy(temp, _data);
     strcat(temp, string._data);
     MyString tempString(temp);

     delete temp;
     return tempString;
}

MyString MyString::operator +(const char *string) const
{
     //cout << "�������� �������� + Char " << endl;
    char *temp = new char[strlen(string) + this->_size + 1];
     strcpy(temp, _data);
     strcat(temp, string);
     MyString tempString(temp);

     delete temp;
     return tempString;
}

MyString& MyString::operator +=(const MyString& string)
{
    //cout << "�������� �������� += MyString " << endl;

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
    //cout << "�������� �������� += Char " << endl;
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
    //cout << "�������� �������� == MyString " << endl;
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

    //cout << "�������� �������� == Char " << endl;
    if (strcmp(this->_data, string) == 0)
    {
        return true;
    } else {
        return false;
    }
}
MyString MyString::reverse() const
{
    //cout << "�������� ����� Reverse " << endl;
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
    //cout << "�������� ����� Number " << endl;

    string str = to_string(n);
    char *p = new char[str.length() + 1];
    strcpy (p, str.c_str());
    MyString temp(p);
    return temp;
}


