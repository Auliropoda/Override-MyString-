#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString str1;
    MyString str2("Hello");
    MyString str3("World");
        cout << "str1 = " << str1 <<endl
             << "str1 is empty? " << str1.isEmpty() <<endl
             << "str2 = " << str2 <<endl
             << "str3 = " << str3 <<endl;

    str1 = str2 + str3;
        cout << "str1= str2 + str3 = " << str1 <<endl
             << "str3 is empty? " << str3.isEmpty() <<endl
             << "Size str1 =  " << str1.size() <<endl;

    str3 +=str2;
    cout << "Str2 += str3 = " << str3 <<endl <<endl;

    MyString str4("GOROD");
        cout << "str4 = " << str4 <<endl
             << "Reverse str4 = " << str4.reverse() << endl <<endl;

    MyString str5("RTY");
    char str[] = "MIREA";
    MyString str6(str);
        cout << "str5 = " << str5 <<endl
             << "char str[] = " << str <<endl
             << "str6(str) = "<< str6 <<endl
             << "str5+str6 = " << str5 + str6 <<endl;

    str6 += str5;
        cout <<"str6 += str5 = " << str6 <<endl << endl;

    int a = 1234;
    cout << "int a = " << a << endl;

    MyString str10;
    str10 = MyString :: number(a);
    cout << "str10.number(a) = " << str10 << endl;
    cout << "Enter the string " <<endl;
    cin >> str10;
    cout << "str 10 = " <<str10;

   MyString str11("PRIVETTTTT");
    char stroka[] = "proverka";
    str11=stroka;
    cout << str11;
    //cout << "Hello"_MS.size() << endl;
    return 0;
}
