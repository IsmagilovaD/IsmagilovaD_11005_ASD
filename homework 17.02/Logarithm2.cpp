#include <iostream>
using namespace std;

void logarithm2() 
{
	int a;
	cout << "Enter a: ";
	cin >> a;
	int l = 2;
	int k = 0;
	while (a > l) {
		k++;
		l = l * 2;
	}

	cout << k;
}

int main()
{
	
	logarithm2();
}