#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int value); // Добавляет значение в конец массива
int* push_front(int arr[], int& n, int value);// Добавляет значение в начало массива
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int value);
int* erase(int arr[], int& n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);

	arr = push_back(arr, n, 1024);
	Print(arr, n);

	arr = push_front(arr, n, 2048);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = insert(arr, n, 4096);
	Print(arr, n);

	arr = erase(arr, n);
	Print (arr, n);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - Оператор индексирования (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Освобождаем память, занимаемую исходным массивом:
	delete[] arr;

	// 4) Говорим, что buffer - это наш массив:
	arr = buffer;

	//5) Только после всего этого в массив arr можно добавить элемент в конец:
	arr[n] = value;

	//6) После добавления элемента в конец массива, количество его эелементов увеличивается на 1:
	n++;

	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) Освобождаем память, занимаемую исходным массивом:
	delete[] arr;

	// 4) Говорим, что buffer - это наш массив:
	arr = buffer;

	//5) Только после всего этого в массив arr можно добавить элемент в конец:
	arr[0] = value;

	//6) После добавления элемента в конец массива, количество его эелементов увеличивается на 1:
	n++;

	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}

int* insert(int arr[], int& n, int value)
{
	int index;
	cout << "Введите индекс: "; cin >> index;
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else if (i > index)
		{
			buffer[i] = arr[i - 1];
		}
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n)
{
	int index;
	cout << "Введите индекс: "; cin >> index;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else if (i >= index)
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	arr = buffer;
	return arr;
}