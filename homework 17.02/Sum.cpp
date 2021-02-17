#include <iostream>;
using namespace std;

void sum() 
{
	int k = 0;
	int n, l;
	cout << "Enter quantity of numbers: ";
	cin >> n;
	cout << "Enter numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> l;
		k = k + l;
	}

	cout << k;
}
int main() 
{
	sum();
	return 0;
}