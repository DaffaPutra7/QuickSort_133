#include <iostream>
using namespace std;


int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n; 

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}


void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)										//Langkah Algoritma No 1
		return;

	//Partition the list into two parts;
	//one containing elements less that or equal to pivot
	//Outer containing elements greather than pivot

	pivot = arr[low];									//langkah Algoritma No 2

	i = low + 1;										//Langkah Algoritma No 3
	j = high;											//Langkah Algoritma No 4



	while (i <= j)										//Langkah Algoritma No 10
	{

		while ((arr[i] <= pivot) && (i <= high))		//Langkah Algoritma No 5
		{
			i++;										//Langkah Algoritma No 6
			cmp_count++;
		}
		cmp_count++;

		while ((arr[j] > pivot) && (j >= low))			//Langkah Algoritma No 7
		{
			j--;										//Langkah Algoritma No 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j)										//Langkah Algoritma No 9
		{

			swap(i, j);
			mov_count++;
		}
	}

	if (low < j)										//Langkah Algoritma No 11
	{

		swap(low, j);
		mov_count++;
	}

	q_short(low, j - 1);								//Langkah Algoritma No 12


	q_short(j + 1, high);								//Langkah Algoritma No 13



}

void display() {
	cout << "\n----------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n----------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}
