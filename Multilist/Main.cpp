#include <iostream>
#include <conio.h>
#include <string>
#include "My_list.h"		//���������� ����� ����� "������"
using namespace std;
class note					//����� "������"
{
	string student;			//��� ��������
	string course;			//�����, �� ������� �������
	friend class multilist;
public:
	note():student(""),course(""){};	//����������� ��-��������� (��������� � ���������� ������)
	note(string student, string course):student(student), course(course){};
	void print()						//����� ������
	{
		cout<<"Student: "<<student<<"\nCourse: "<<course<<endl;
	}
	void print_name()					//����� ������ ����� ��������
	{
		cout<<"Student: "<<student<<endl;
	}
	void print_course()					//����� ������ �������� ������
	{
		cout<<"Course: "<<course<<endl;
	}
	bool operator==(note b)				//�������� ��������� ���� �������
	{
		return (student==b.student&&course==b.course);
	}
};
class multilist							//����� ������������. ���������� ��� ������ ������ "�������"
{										//������������ �������-�����
	list<string> students;			//������ ���������
	list<string> courses;			//������ ������
	list<note> notes;				//������ �������
public:
	void push(string name, string course)	//���������� ������
	{
		if (!students.exist(name))			//���� ������� ��� ����������, ��������� ��� � ������
		{
			students.push(name);
		}
		if (!courses.exist(course))			//���� ����� ��� ����������, ��������� �� � ������
		{
			courses.push(course);
		}
		if (!notes.exist(note(name,course)))	//���� ����� ������ ��� ���, ��������� �
			notes.push(note(name,course));
	}
	void search_by_name(string name)			//����� � ����� ���������� � ���, �� ����� ����� ������� 
	{											//������ �������
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
	void search_by_course(string course)		//����� � ����� ���������� � ���, ��� �������
	{											//�� ������ �����
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
	void print_by_students()					//����� ����� ������������ ������������ ���������
	{
		for (int i=0; i<students.getLength(); i++)
		{
			cout<<"Student: "<<students[i]<<endl;
			for (int j=0; j<notes.getLength(); j++)
				if (notes[j].student==students[i])
					notes[j].print_course();
		}
	}
	void print_by_courses()						//����� ����� ������������ ������������ ������
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
	m.search_by_name("s1");
	m.search_by_course("c3");
	getch();
}