#include"ForwardList.h"

///////////////////////////////////////////////////////////////////
////////////				Element					///////////////

template<typename T>Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>Element<T>::~Element()
{
	count--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}

////////////				Element					///////////////
///////////////////////////////////////////////////////////////////

///------------------------------------------------------------///

///////////////////////////////////////////////////////////////////
////////////			  ConstIterator				///////////////

template<typename T>ConstIterator<T>::ConstIterator(Element<T>* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template<typename T>ConstIterator<T>::~ConstIterator()
{
	cout << "ItDestructor:\t" << this << endl;
}

template<typename T>ConstIterator<T>& ConstIterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}

template<typename T>bool ConstIterator<T>::operator==(const ConstIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool ConstIterator<T>::operator!=(const ConstIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>const T& ConstIterator<T>::operator*()const
{
	return Temp->Data;
}

////////////			  ConstIterator				///////////////
///////////////////////////////////////////////////////////////////

///------------------------------------------------------------///

///////////////////////////////////////////////////////////////////
////////////				Iterator				///////////////

template<typename T>Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template<typename T>Iterator<T>::~Iterator()
{
	cout << "ItDestructor:\t" << this << endl;
}

template<typename T>Iterator<T>& Iterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}

template<typename T>bool Iterator<T>::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool Iterator<T>::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>T& Iterator<T>::operator*()
{
	return Temp->Data;
}

////////////				 Iterator				///////////////
///////////////////////////////////////////////////////////////////

///-------------------------------------------------------------///

///////////////////////////////////////////////////////////////////
////////////				ForwardList				///////////////
template<typename T>Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template<typename T>Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}
template<typename T>ConstIterator<T> ForwardList<T>::begin()const
{
	return Head;
}
template<typename T>ConstIterator<T> ForwardList<T>::end()const
{
	return nullptr;
}

template<typename T>ForwardList<T>::ForwardList()
{
	Head = nullptr;	//Åñëè ñïèñîê ïóñò, òî åãî ãîëîâà óêàçûâàåò íà 0
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>ForwardList<T>::ForwardList(initializer_list<T> il) :ForwardList()
{
	//begin() - âîçâðàùàåò èòåðàòîð íà íà÷àëî êîíòåéíåðà
	//end()	  - âîçâðàùàåò èòåðàòîð íà êîíåö êîíòåéíåðà
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>ForwardList<T>::ForwardList(const ForwardList<T>& other) :ForwardList()
{
	*this = other;
}
template<typename T>ForwardList<T>::ForwardList(ForwardList<T>&& other) : ForwardList()
{
	*this = std::move(other);
}
template<typename T>ForwardList<T>::~ForwardList()
{
	while (Head)pop_front();
	cout << "LDEstructor:\t" << this << endl;
}

//				Operators:
template<typename T>ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_front(Temp->Data);
	reverse();
	return *this;
}
template<typename T>ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
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
template<typename T>void ForwardList<T>::push_front(T Data)
{
	/*
	//1) Ñîçäàåì íîâûé ýëåìåíò:
	Element* New = new Element(Data);
	//2) Íîâûé ýëåìåíò äîëæåí óêàçûâàòü íà íà÷àëî ñïèñêà:
	New->pNext = Head;
	//3) Ïåðåâîäèì Ãîëîâó ñïèñêà íà íîâûé ýëåìåíò:
	Head = New;
	*/

	Head = new Element<T>(Data, Head);

	size++;
}
template<typename T>void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)return push_front(Data);
	//1) Ñîçäàåì íîâûé ýëåìåíò:
	//Element* New = new Element(Data);
	//2) Äîäõîäèì äî êîíöà ñïèñêà:
	Element<T>* Temp = Head;
	while (Temp->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	//Ïî çàâåðøåíèè ýòîãî öèêëà Temp óêàçûâàåò íà ïîñëåäíèé ýëåìåíò ñïèñêà

	//3) Âñòàâëÿåì íîâûé ýëåìåíò â êîíåö ñïèñêà:
	Temp->pNext = new Element<T>(Data);
	size++;
}
template<typename T>void ForwardList<T>::insert(T Data, int Index)
{
	if (Index == 0)return push_front(Data);
	if (Index > size)return;
	//1) Ñîçäàåì íîâûé ýëåìåíò:
	Element<T>* New = new Element<T>(Data);

	//2) Äîõîäèì äî íóæíîãî ýëåìåíòà:
	Element<T>* Temp = Head;
	for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;

	//3) Ïîìåñòèòü ýëåìåíò â ñïèñîê íà íóæíóþ ïîçèöèþ:
	New->pNext = Temp->pNext;
	Temp->pNext = New;
	size++;
}

//				Removing elements:
template<typename T>void ForwardList<T>::pop_front()
{
	//1) Çàïîìèíàåì àäðåñ óäàëÿåìîãî ýëåìåíòà:
	Element<T>* Erased = Head;
	//2) Ïåðåâîäèì Ãîëîâó íà ñëåäóþùèé ýëåìåíò, 
	//	 è òàêèì îáðàçîì, èñêëþ÷àåì óäàëÿåìûé ýëåìåíò èç ñïèñêà:
	Head = Head->pNext;
	//3) Óäàëÿåì ýëåìåíò èç ïàìÿòè:
	delete Erased;
	size--;
}
template<typename T>void ForwardList<T>::pop_back()
{
	//1) Äîõîäèì äî ïðåäïîñëåäíåãî ýëåìåíòà ñïèñêà:
	Element<T>* Temp = Head;
	while (Temp->pNext->pNext)
	{
		Temp = Temp->pNext;
	}
	//2) Óäàëÿåì ïîñëåäíèé ýëåìåíò èç ïàìÿòè:
	delete Temp->pNext;
	//3) Çàíóëÿåì àäðåñ ïîñëåíåãî ýëåìåíòà:
	Temp->pNext = nullptr;
	size--;
}
template<typename T>void ForwardList<T>::erase(int Index)
{
	if (Index == 0)return pop_front();
	if (Index > size)return;
	//1) Äîõîäèì äî ýëåìåíòà ïåðåä óäàëÿåìûì:
	Element<T>* Temp = Head;
	for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
	//2) Çàïîìèíàåì àäðåñ óäàëÿåìîãî ýëåìåíòà:
	Element<T>* Erased = Temp->pNext;
	//3)  Èñêëþ÷àåì óäàëÿåìûé ýëåìåíò èç ñïèñêà:
	Temp->pNext = Temp->pNext->pNext;
	//4) Óäàëÿåì ýëåìåíò èç ïàìÿòè:
	delete Erased;
	size--;
}

//				Methods:
template<typename T>void ForwardList<T>::reverse()
{
	ForwardList<T> buffer;
	while (Head)
	{
		buffer.push_front(Head->Data);
		pop_front();
	}
	this->Head = buffer.Head;
	buffer.Head = nullptr;
}
template<typename T>void ForwardList<T>::print()const
{
	/*
	Element* Temp = Head;	//Temp - ýòî èòåðàòîð.
	//Èòåðàòîð - ýòî óêàçàòåëü, ïðè ïîìîùè êîòîðîãî
	//ìîæíî ïîëó÷èòü äîñòóï ê ýëåìåíòàì ñòðóêòóðû äàííûõ.
	while (Temp)
	{
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		Temp = Temp->pNext;	//Ïåðåõîäèì íà íîâûé ýëåìåíò
	}
	*/
	for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Êîëè÷åñòâî ýëåìåíòîâ ñïèñêà: " << size << endl;
	cout << "Îáùåå êîëè÷åñòâî ýëåìåíòîâ:  " << Element<T>::count << endl;
}
template<typename T>
ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left;
	for (Element<T>* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

template<typename T>void print(T arr[])
{
	/*cout << typeid(arr).name() << endl;
	cout << sizeof(arr) << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;*/
}
template<typename T>void print(const ForwardList<T>& list)
{
	for (const T& i : list)
	{
		//i *= 10;
		cout << i << tab;
	}
	cout << endl;
}