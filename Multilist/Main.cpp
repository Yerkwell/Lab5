#include <iostream>
#include <conio.h>
#include <string>
#include "My_list.h"		//Написанный ранее класс "список"
using namespace std;
class note					//Класс "запись"
{
	string student;			//Имя студента
	string course;			//Курсы, на которые записан
	friend class multilist;
public:
	note():student(""),course(""){};	//Конструктор по-умолчанию (необходим в реализации списка)
	note(string student, string course):student(student), course(course){};
	void print()						//Вывод записи
	{
		cout<<"Student: "<<student<<"\nCourse: "<<course<<endl;
	}
	void print_name()					//Вывод только имени студента
	{
		cout<<"Student: "<<student<<endl;
	}
	void print_course()					//Вывод только названия курсов
	{
		cout<<"Course: "<<course<<endl;
	}
	bool operator==(note b)				//Оператор сравнения двух записей
	{
		return (student==b.student&&course==b.course);
	}
};
class multilist							//Класс мультисписок. Реализован при помощи списка "записей"
{										//соответствий студент-курсы
	list<string> students;			//Список студентов
	list<string> courses;			//Список курсов
	list<note> notes;				//Список записей
public:
	void push(string name, string course)	//Добавление записи
	{
		if (!students.exist(name))			//Если студент ещё неизвестен, добавляем его в список
		{
			students.push(name);
		}
		if (!courses.exist(course))			//Если курсы ещё неизвестны, добавляем их в список
		{
			courses.push(course);
		}
		if (!notes.exist(note(name,course)))	//Если такой записи ещё нет, добавляем её
			notes.push(note(name,course));
	}
	void search_by_name(string name)			//Поиск и вывод информации о том, на какие курсы записан 
	{											//данный студент
		if (students.exist(name))
		{
			cout<<"Student: "<<name<<endl;
			for (int i=0; i<notes.getLength(); i++)
			{
				if (notes[i].student==name)
					notes[i].print_course();
			}
		}
		else 
			cout<<"Student "<<name<<" ne obnaruzhen\n";
	}
	void search_by_course(string course)		//Поиск и вывод информации о том, кто записан
	{											//На данные курсы
		if (courses.exist(course))
		{
			cout<<"Course: "<<course<<endl;
			for (int i=0; i<notes.getLength(); i++)
			{
				if (notes[i].course==course)
					notes[i].print_name();
			}
		}
		else 
			cout<<"Kurs "<<course<<" ne obnaruzhen\n";
	}
	void print_by_students()					//Вывод всего мультисписка относительно студентов
	{
		for (int i=0; i<students.getLength(); i++)
		{
			cout<<"Student: "<<students[i]<<endl;
			for (int j=0; j<notes.getLength(); j++)
				if (notes[j].student==students[i])
					notes[j].print_course();
		}
	}
	void print_by_courses()						//Вывод всего мультисписка относительно курсов
	{	
		for (int i=0; i<courses.getLength(); i++)
		{
			cout<<"Course: "<<courses[i]<<endl;
			for (int j=0; j<notes.getLength(); j++)
				if (notes[j].course==courses[i])
					notes[j].print_name();
		}
	}
};
void main()
{
	multilist m;
	m.push("s1","c3");
	m.push("s2","c1");
	m.push("s2","c2");
	m.push("s3","c3");
	m.push("s4","c1");
	m.push("s5","c2");
	m.push("s5","c3");
	m.push("s6","c1");
	m.push("s6","c3");
	int act=0;
	while(act!=5)
	{
		cout<<"Chto sdelat'?\n1 - Kursy studenta; 2 - Studenty kursa; 3 - Spisok po studentam; 4 - Spisok po kursam; 5 - Vyhod\n";
		cin>>act;
		switch(act)
		{
		case 1:
			{
				string a;
				cout<<"Imya studenta: ";
				cin>>a;
				m.search_by_name(a);
				break;
			}
		case 2:
			{
				string a;
				cout<<"Kurs: ";
				cin>>a;
				m.search_by_course(a);
				break;
			}
		case 3:
			{
				m.print_by_students();
				break;
			}
		case 4:
			{
				m.print_by_courses();
				break;
			}
		}
	}
}