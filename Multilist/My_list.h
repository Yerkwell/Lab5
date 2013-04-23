#include <iostream>
template <typename type>				//��������� ����� "�������" (�.�. � ���� ����� ��������� � ������ "������")
class element;							//�������� ����� ������
template <typename type>				//����� "������ ��������� ���������, �.�. ����� ��������� ������
class list								//��������� ������ �����
{
	element<type>* first;				//��������� �� ������ � ��������� �������� ������
	element<type>* last;
	int length;							//���������� ��������� � ������
public:
	list();
	~list();
	void erase();
	void push(type n);
	void pop();
	void del(type wh);
	void print();
	void print_class();
	type& operator[](int i);
	list<type>(const list<type>& b);
	list<type>& operator=(list<type>& b);
	int getLength();
	bool exist(type find);
};
template <typename type>				//�������� ���������� ������ "�������"
class element
{
	type data;
	element* next;
	element* prev;
public:
	element();
	friend class list<type>;
};


	template <typename type>
	list<type>::list()								//�����������. �������� ������ ��� ��������
	{
		first=last=0;
		length=0;
	}
	template <typename type>
	list<type>::list<type>(const list<type>& b):first(first),last(last),length(length){};	//����������� �����������
	template <typename type>
	list<type>::~list()
	{
		erase();						//��������� ������ ���������� ������������ ������, ��� ��� �����������
	}									//���� ��� ������ ����������
	template <typename type>
	void list<type>::erase()
	{
		while(length)
			pop();
	}
	template <typename type>
	void list<type>::push(type n)					//���������� �������� � ����� (� ������������ ����� ��������� �� �������)
	{									//��� ���� �� ����� �������� �� �������, � ������ ��� ������.
		element<type> *newel = new element<type>;		//��� ������� ������������ �� ���� �����
		newel->data=n;
		if (!length)
		{
			first=last=newel;							//���� ������ ����, ������ ��������� ������� � ������
		}
		else
		{
			last->next=newel;							//����� ��������� ��� ��������� 
			newel->prev=last;							//� ����������� ��������� ���������� �� ����
			last=newel;
		}
		length++;
	}
	template <typename type>
	void list<type>::pop()							//�������� ���������� �������� �� ������
	{
		if (length)
		{
			element<type> *tek=last;
			last=last->prev;
			delete tek;
			if (length==1)
				first=NULL;
			length--;
		}
	}
	template <typename type>
	void list<type>::del(type wh)					//�������� �� ������ ��������, ����������� ������ wh
	{
		element<type> *tek=first;
		for (int i=0; i<length; i++)
		{
			if ((*this)[i]==wh)
			{
				if (tek->next)
				tek->next->prev=tek->prev;
				else
					last=tek->prev;
				if (tek->prev)
				tek->prev->next=tek->next;
				else
					first=tek->next;
				delete tek;
				length--;
				break;
			}
			tek=tek->next;
		}
	}
	template <typename type>
	void list<type>::print()					//����� �� ����� ����� ������, ��� �������, ��� ������ ����� ���, 
	{								//����������� � cout
		if (length)
		{
		element<type> *tek = first;
		while(tek!=last)
		{
			cout<<tek->data<<endl;
			tek=tek->next;
		}
		cout<<last->data<<endl;
		}
	}
	template <typename type>
	void list<type>::print_class()				//����� �� ����� ����� ������, ��� �������, ��� ������ ������������ �����
	{								//���������� ������, �������� ����� print() ��� ������ ���� �� �����
		if (length)
		{
		element<type> *tek = first;
		while(tek!=last)
		{
			tek->data.print();
			tek=tek->next;
		}
		last->data.print();
		}
	}
	template <typename type>
	type& list<type>::operator[](int i)		//��������� � ����������� �������� ������ �� ��� ������ (������ �� ������)
	{
		element<type> *tek=first;
		for (int j=0; j<i; j++)
		{
			tek=tek->next;
		}
		return tek->data;
	}
	template <typename type>
	list<type>& list<type>::operator=(list<type>& b)						//�������� ������������
	{
		erase();
		for (int i=0; i<b.getLength(); i++)
			push(b[i]);
		return *this;
	}
	template <typename type>
	int list<type>::getLength()												//��������� ����� ������
	{
		return length;
	}
	template <typename type>
	bool list<type>::exist(type find)				//��������, ���� �� ������� � ������� find � ������. ��������,
	{									//���� ���������� �������� ��������� == ��� ������� ���� ������			
		for (int i=0; i<length; i++)	
		{
			if ((*this)[i]==find)
				return 1;
		}
		return 0;
	}
	template <typename type>				//�������� ���������� ������ "�������"
	element<type>::element():next(0),prev(0){};