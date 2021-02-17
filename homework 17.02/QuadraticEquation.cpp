#include <iostream>
using namespace std;

void fubctionQuadratic()
{
	double a;
	double b;
	double c;
	double D;
	double x;
	cout << "Enter value a: ";
	cin >> a;
	cout << "Enter value b: ";
	cin >> b;
	cout << "Enter value c: ";
	cin >> c;

	D = b * b - 4 * a * c;
	if (D >= 0)
	{
		x = (-b + sqrt(D)) / (2 * a);
		cout << "x1 = " << x << endl;
		x = (-b - sqrt(D)) / (2 * a);
		cout << "x2 = " << x << endl;
	}
	else {
		cout << "No real square roots.";
	}

}

int main()
{
	fubctionQuadratic();
	
	return 0;
}