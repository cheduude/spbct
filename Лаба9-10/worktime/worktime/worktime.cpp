#include "pch.h"
#include <iostream>
#include <locale.h>

using namespace std;

class Time
{
public:
	
	void setTime(int, int, int);
	void printTime1();;
	void printTime2();;
private:
	int hour;
	int minute;
	int second;
};

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printTime1();
{
	cout << (hour < 1 ? "0" : "") << hour << ":" << (minute < 1 ? "0" : "") << minute <<
		":" << (second < 1 ? "0" : "") << second;
}

void Time::printTime2();
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 1 ? "0"
		: "") << minute << ":" << (second < 1 ? "0" : "") << second << (hour < 12 ? "AM" : " PM");
}



int main()
{
	setlocale(LC_ALL, "rus");
	Time t;
	cout << "Начальное значение времени 1 равно ";
	t.printTime1();
	cout << endl << "Начальное значение времени 2 равно ";
	t.printTime2();
	t.setTime(13, 27, 6);
	cout << endl << endl << "Время 1 после setTime равно ";
	t.printTime1();
	cout << endl << "Время 2 после setTime равно ";
	t.printTime2();
	t.setTime(99, 99, 99);//попытка установить неправильные значения
	cout << endl << endl << "После попытки неправильной установки: " << endl <<
		"Время 1: ";
	t.printTime1();
	cout << endl << "Время 2: ";
	t.printTime2();
	cout << endl;
	return 0;

}