#include <iostream>
using namespace std;

int sum(int* a, int size)
{
	int k = 0;
	for (int i = 0; i < size; i++) {
		k = k + a[i];
	}
	return k;
}

int main()
{
	int a[4] = { 1,2,3,6 };
	int k = sum(a, 4);
	cout << k;

	return 0;
}