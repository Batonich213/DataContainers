#include<iostream>
using namespace std;


class BinaryTree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "Econstrucotr:\t" << this << endl;
		}
		~Element()
			{
				cout << "Edetrucotr:\t" << this << endl;
			}
		friend class BinaryTree;
	}*Root; //—разу же объ€вл€ем Root
public:
	Element* getRoot()const
	{
		return Root;
	}
	BinaryTree()
	{
		Root == nullptr;
		cout << "Tconstructor: \t" << this << endl;
	}
	~BinaryTree()
	{
		cout << "TDectructor: \t" << this << endl;
	}


	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	int minValue(Element* Root)
	{
		if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);
	}
};




void main()
{
	setlocale(LC_ALL, "");
	BinaryTree tree;
	int n;
	cout << "Enter tree size: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "Min value in tree: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Max value in tree: " << tree.maxValue(tree.getRoot()) << endl;
}