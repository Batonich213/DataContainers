#include<iostream>
using namespace std;

#define tab "\t"

class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EContructor\t " << this << endl;
		}
		~Element()
		{
			cout << "Edestructor\t " << this << endl;
		}
		friend class List;
	}*Head, *Tail;


	size_t size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LDonstructor:\t " << this << endl;
	}
	
	~List()
	{
		cout << "LDertructor: \t" << this << endl;
	}
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
			
		}
		cout << "Quantity element list: " << size << endl;
	}
	void reverse_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			return push_front(Data);
			Element* New = new Element(Data);
			New->pPrev = Tail;
			Tail->pNext = New;
			Tail = New;
			size++;
		}
		
	}
	//                      Removing elements:
	void pop_front()
	{
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
};


void main()
{
	int n;
	cout << "Enter quantity list: "; 
	cin >> n;
	List list;
	//for (int i = 0; i < n; i++)
	//{
	//	list.push_front(rand() % 100);
	//}
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	//list.reverse_print();
}