#include <iostream>
using namespace std;

int power(int x, unsigned p) 
{
	int l = x;
	for (p ; p > 1 ; p--)
	{
		x = x * l;
	}
	return x;
}

int main()
{
	int x;
	unsigned p;
	cout << "Enter number: ";
	cin >> x;
	cout << "Enter power: ";
	cin >> p;
	x = power(x, p);
	cout <<"x is " << x;
	return 0;
}