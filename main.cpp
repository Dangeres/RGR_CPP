#include <iostream>
#include <string>

using namespace std;

template <class Item>
void shiftDown(Item array[], int root, int bottom){
	int maxChild = 0;
	bool done = 0;

	while ((root * 2 <= bottom) && (!done)){
		if (root * 2 == bottom)
			maxChild = root * 2;
		else 
			if (array[root * 2] > array[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
			if (array[root] < array[maxChild]){
				swap(array[root], array[maxChild]);
			}
			else
				done = 1;
	}
}

template <class Item>
void heapSort(Item array[], int array_size){
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		shiftDown(array, i, array_size);

	for (int i = array_size - 1; i >= 1; i--){
		swap(array[0], array[i]);
		shiftDown(array, 0, i - 1);
	}
}

template<class Item>
void insertSort(Item a[], int size) {
	for (int i = 0; i < size; i++) {
		Item x = a[i];

		int j = i - 1;
		for (; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}
}

template <class Item>
void print(Item array[], int size) {
	for (int a = 0; a < size; a++) {
		cout << array[a] << endl;
	}
}

int main() {
	char a[3] = { 'a', 'c', 'b' };

	insertSort(a, size(a));

	for (int ai = 0; ai < 3; ai++) {
		cout << a[ai] << endl;
	}

	system("pause");
	return 0;
}
