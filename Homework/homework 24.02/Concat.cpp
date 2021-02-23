#include <iostream>
using namespace std;

int main()
{
	int* a = new int[3]{ 1, 2, 3 };
	int* b = new int[4]{ 4, 5, 6, 7 };
	int* c = new int[7];
	for (int i = 0; i < 7; i++)
	{
		if (i < 3) {
			c[i] = a[i];
		}
		else
		{
			c[i] = b[i - 3];
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << c[i] << endl;
	}

	delete[] a;
	delete[] b;
	return 0;
}