#include<iostream>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ���������� ��������
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
	friend class ConstIterator;
	friend class Iterator;
};

int Element::count = 0;	//����������� ���������� ����� ������������������� ������ �� ��������� ������

class ConstIterator
{
	Element* Temp;
public:
	ConstIterator(Element* Temp) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~ConstIterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}

	ConstIterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const ConstIterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const ConstIterator& other)const
	{
		return this->Temp != other.Temp;
	}
	const int& operator*()const
	{
		return Temp->Data;
	}
};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}

	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};


class ForwardList
{
	Element* Head;
	unsigned int size;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ConstIterator begin()const
	{
		return Head;
	}
	ConstIterator end()const
	{
		return nullptr;
	}

	ForwardList()
	{
		Head = nullptr;	//���� ������ ����, �� ��� ������ ��������� �� 0
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(initializer_list<int> il) :ForwardList()
	{
		//begin() - ���������� �������� �� ������ ����������
		//end()	  - ���������� �������� �� ����� ����������
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		*this = other;
	}
	ForwardList(ForwardList&& other) :ForwardList()
	{
		*this = std::move(other);
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDEstructor:\t" << this << endl;
	}

	//				Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_front(Temp->Data);
		reverse();
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		other.size = 0;
		return *this;
	}

	//				Adding elements:
	void push_front(int Data)
	{
		/*
		//1) ������� ����� �������:
		Element* New = new Element(Data);
		//2) ����� ������� ������ ��������� �� ������ ������:
		New->pNext = Head;
		//3) ��������� ������ ������ �� ����� �������:
		Head = New;
		*/

		Head = new Element(Data, Head);

		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//1) ������� ����� �������:
		//Element* New = new Element(Data);
		//2) �������� �� ����� ������:
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		//�� ���������� ����� ����� Temp ��������� �� ��������� ������� ������

		//3) ��������� ����� ������� � ����� ������:
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		if (Index > size)return;
		//1) ������� ����� �������:
		Element* New = new Element(Data);

		//2) ������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;

		//3) ��������� ������� � ������ �� ������ �������:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//				Removing elements:
	void pop_front()
	{
		//1) ���������� ����� ���������� ��������:
		Element* Erased = Head;
		//2) ��������� ������ �� ��������� �������, 
		//	 � ����� �������, ��������� ��������� ������� �� ������:
		Head = Head->pNext;
		//3) ������� ������� �� ������:
		delete Erased;
		size--;
	}
	void pop_back()
	{
		//1) ������� �� �������������� �������� ������:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		//2) ������� ��������� ������� �� ������:
		delete Temp->pNext;
		//3) �������� ����� ��������� ��������:
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		if (Index > size)return;
		//1) ������� �� �������� ����� ���������:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
		//2) ���������� ����� ���������� ��������:
		Element* Erased = Temp->pNext;
		//3)  ��������� ��������� ������� �� ������:
		Temp->pNext = Temp->pNext->pNext;
		//4) ������� ������� �� ������:
		delete Erased;
		size--;
	}

	//				Methods:
	void reverse()
	{
		ForwardList buffer;
		while (Head)
		{
			buffer.push_front(Head->Data);
			pop_front();
		}
		this->Head = buffer.Head;
		buffer.Head = nullptr;
	}
	void print()const
	{
		/*
		Element* Temp = Head;	//Temp - ��� ��������.
		//�������� - ��� ���������, ��� ������ ��������
		//����� �������� ������ � ��������� ��������� ������.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//��������� �� ����� �������
		}
		*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "���������� ��������� ������: " << size << endl;
		cout << "����� ���������� ���������:  " << Element::count << endl;
	}
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	return cat;
}

void print(int arr[])
{
	/*cout << typeid(arr).name() << endl;
	cout << sizeof(arr) << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;*/
}
void print(const ForwardList& list)
{
	for (const int& i : list)
	{
		//i *= 10;
		cout << i << tab;
	}
	cout << endl;
}

//#define BASE_CHECK
//#define OPERATOR_PLUS
//#define RANGE_BASED_FOR_ARRAY
//#define RANGE_BASED_FOR_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	cout << delimiter << endl;
	//list.push_back(123);
	//list.pop_front();
	//list.pop_back();
	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(value, index);
	list.print();

	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();

	/*ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();*/
#endif // BASE_CHECK

#ifdef OPERATOR_PLUS
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1 = list1;
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	//ForwardList list3 = list1 + list2;	//CopyConstructor
	cout << delimiter << endl;
	ForwardList list3;
	list3 = list1 + list2;
	cout << delimiter << endl;
	list3.print();
#endif // OPERATOR_PLUS

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	cout << typeid(arr).name() << endl;
	cout << sizeof(arr) << endl;
	//Range-based for:
	//https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	print(arr);
#endif // RANGE_BASE_FOR_ARRAY

#ifdef RANGE_BASED_FOR_LIST
	ForwardList list = { 3, 5, 8, 13, 21 };
	/*for (int i : list)
	{
		//i *= 10;
		cout << i << tab;
	}*/
	cout << endl;
	print(list);
	list.print();
#endif // RANGE_BASED_FOR_LIST

	int n;
	cout << "������� ������ ������: "; cin >> n;
	clock_t start = clock();
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	clock_t end = clock();
	double delta = double(end - start) / CLOCKS_PER_SEC;
	cout << "������ �������� �� " << delta << " ������." << endl;
	//list.print();
	start = clock();
	ForwardList list2 = list;
	end = clock();
	delta = double(end - start) / CLOCKS_PER_SEC;
	cout << "������ ���������� �� " << delta << " ������." << endl;
	//list2.print();
}