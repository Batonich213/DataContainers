#include "DataContainers.cpp"
#define tab "\t"
#define delimiter "\n--------------------------------\n"



//#define POINTERS_AND_ARRAYS
//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#endif // POINTERS_AND_ARRAYS

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Ââåäèòå ðàçìåð ìàññèâà: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	Print(arr = push_front(arr, n, value), n);

	int index;
	cout << "Ââåäèòå äîáàâëÿåìîå çíà÷åíèå: "; cin >> value;
	cout << "Ââåäèòå èíäåêñ äîáàâëÿåìîãî çíà÷åíèÿ: "; cin >> index;
	Print(arr = insert(arr, n, value, index), n);

	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Ââåäèòå êîëè÷åñòâî ñòðîê: "; cin >> rows;
	cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ: "; cin >> cols;
	//1) Ñîçäàåì ìàññèâ óêàçàòåëåé
	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 200);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

	int n;
	cout << "Ââåäèòå ðàçìåð ìàññèâà: "; cin >> n;
	int* arr = new int[n] {};

	cout << "Ìàcñèâ ñîçäàí, äëÿ äîáàâëåíèÿ ýëåìåíòà íàæìèòå ëþáóþ êëàâèøó..." << endl;
	system("PAUSE");
	arr = push_back(arr, n, 0);
	cout << "Ýëåìåíò äîáàâëåí" << endl;

	delete[] arr;
}
