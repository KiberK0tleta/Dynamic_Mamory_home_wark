#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int** Allocate(const int m, const int n);
void Clear(int** arr, const int m);

void FillRand(int arr[], const int n, int maxRand = 100, int minRand = 0);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
void insert_row(int**& arr, int& m, const int n, int index);

void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);

void push_col_back(int** arr, const int m, int& n);
void push_col_front(int** arr, const int m, int& n);
void insert_col(int** arr, const int m, int& n, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);






void main()
{
	setlocale(LC_ALL, "Russian");

	int m;	//Количство строк
	int n;	//Количество столбцов (элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr = Allocate(m, n);

	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в конец:\n";
	push_row_back(arr, m, n);
	FillRand(arr[m - 1], n, 0, 100);
	Print(arr, m, n);
	cout << "Добавляем строку в начало:\n";
	push_row_front(arr, m, n);
	arr[0][3] = 123;
	Print(arr, m, n);

	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);

	cout << "Добавление столбца в конец массива:\n";
	push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в начало массива:\n";
	push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "Удаление последней строки:\n";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление нулевой строки:\n";
	pop_row_front(arr, m, n);
	Print(arr, m, n);

	Clear(arr, m);
}

int** Allocate(const int m, const int n)
{
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	return arr;
}
void Clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n, int value, int index)
{
	if (index >= n)return;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new int[n] {};
	m++;
}

void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
}

void insert_row(int**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	int** buffer = new int* [m + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int[n] {};
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];//Удаляем последнюю строку из памяти
	delete[] arr;	//Удаляем массив указателей	
	arr = buffer;	//Подменяем на новый массив указателей
}
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}

void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
void push_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

void insert_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}
