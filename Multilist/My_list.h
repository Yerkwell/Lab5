#include <iostream>
template <typename type>				//Объявляем класс "элемент" (т.к. к нему будет обращение в классе "список")
class element;							//Описание будет дальше
template <typename type>				//Класс "список объявляем шаблонным, т.к. будем создавать списки
class list								//элементов разных типов
{
	element<type>* first;				//Указатели на первый и последний элементы списка
	element<type>* last;
	int length;							//Количество элементов в списке
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
template <typename type>				//Описание шаблонного класса "элемент"
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
	list<type>::list()								//Конструктор. Обнуляем список при создании
	{
		first=last=0;
		length=0;
	}
	template <typename type>
	list<type>::list<type>(const list<type>& b):first(first),last(last),length(length){};	//Конструктор копирования
	template <typename type>
	list<type>::~list()
	{
		erase();						//Поскольку список использует динамическую память, при его уничтожении
	}									//надо эту память освободить
	template <typename type>
	void list<type>::erase()
	{
		while(length)
			pop();
	}
	template <typename type>
	void list<type>::push(type n)					//Добавление элемента в конец (в произвольное место добавлять не придётся)
	{									//При этом на входе получаем не элемент, а только его данные.
		element<type> *newel = new element<type>;		//Сам элемент генерируется на этом этапе
		newel->data=n;
		if (!length)
		{
			first=last=newel;							//Если список пуст, просто вставляем элемент в начало
		}
		else
		{
			last->next=newel;							//Иначе объявляем его последним 
			newel->prev=last;							//и передвигаем указатель последнего на него
			last=newel;
		}
		length++;
	}
	template <typename type>
	void list<type>::pop()							//Удаление последнего элемента из списка
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
	void list<type>::del(type wh)					//Удаление из списка элемента, содержащего данные wh
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
	void list<type>::print()					//Вывод на экран всего списка, при условии, что данные имеют тип, 
	{								//совместимый с cout
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
	void list<type>::print_class()				//Вывод на экран всего списка, при условии, что данные представляют собой
	{								//экземпляры класса, имеющего метод print() для вывода себя на экран
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
	type& list<type>::operator[](int i)		//Обращение к конкретному элементу списка по его номеру (причём по ссылке)
	{
		element<type> *tek=first;
		for (int j=0; j<i; j++)
		{
			tek=tek->next;
		}
		return tek->data;
	}
	template <typename type>
	list<type>& list<type>::operator=(list<type>& b)						//Оператор присваивания
	{
		erase();
		for (int i=0; i<b.getLength(); i++)
			push(b[i]);
		return *this;
	}
	template <typename type>
	int list<type>::getLength()												//Получение длины списка
	{
		return length;
	}
	template <typename type>
	bool list<type>::exist(type find)				//Проверка, есть ли элемент с данными find в списке. Работает,
	{									//если определена операция сравнения == для данного типа данных			
		for (int i=0; i<length; i++)	
		{
			if ((*this)[i]==find)
				return 1;
		}
		return 0;
	}
	template <typename type>				//Описание шаблонного класса "элемент"
	element<type>::element():next(0),prev(0){};