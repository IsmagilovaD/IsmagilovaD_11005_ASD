#include <iostream>
using namespace std;

void bubbleSort(int* a,int size)
{
	for (int i = size - 1; i > -1; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				int x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}
}

int main() {
	int a[7] = { 5,3,6,7,1,4,2 };
	bubbleSort(a, 7);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << endl;
	}

	return 0;
}