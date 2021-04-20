#include <iostream>

using namespace std;

//№1---------------------------------------------------------
int binarySearchOfStart(int *a, int x, int left, int right) {
    if (x < a[left] || x > a[right]) return -1;
    while (left <= right) {
        int centre = (left + right) / 2;
        if (a[centre] < x) {
            left = centre + 1;
        } else if (a[centre] > x) {
            right = centre - 1;
        } else if (a[centre] == x) {
            if (a[left] == x) { return left; }
            else right = centre;
        }
    }
    return -1;
}

int binarySearchOfEnd(int *a, int x, int left, int right) {
    if (x < a[left] || x > a[right]) return -1;
    while (left <= right) {
        int centre = (left + right) / 2;
        if (a[centre] < x) {
            left = centre + 1;
        } else if (a[centre] > x) {
            right = centre - 1;
        } else if (a[centre] == x) {
            if (a[right] == x) { return right; }
            else {
                left = centre;
                right = right - 1;
            }
        }
    }
    return -1;
}

//№2---------------------------------------------------------
bool binarySearch(int *a, int x, int left, int right) {
    while (left <= right) {
        int center = (left + right) / 2;
        if (a[center] < x) {
            left = center + 1;
        } else if (a[center] > x) {
            right = center - 1;
        } else if (a[center] == x) {
            return true;
        }
    }
    return false;
}

bool binarySearchInMatrix(int a[][3], int x, int n, int m) {
    if (x < a[0][0] || x > a[n - 1][m - 1]) return false;
    for (int i = 0; i < m; i++) {
        if (x <= a[i][n - 1]) {
            return binarySearch(a[i], x, 0, n - 1);
        }
    }
    return false;
}

//№3---------------------------------------------------------

int binarySquareRootSearch(int x) {
    int left = 0;
    int right = x / 2;
    while (right - left > 1) {
        int centre = (right + left) / 2;
        int y = centre * centre;
        if (y < x) {
            left = centre;
        } else if (y > x) {
            right = centre;
        } else return centre;
    }
    return right;
}

//№4---------------------------------------------------------

int binarySearchForMedianOfMatrix(int a[][4], int n, int m) {
    int min = -1;
    int max = -1;
    int minV = INT_MAX;
    int maxV = INT_MIN;
    for (int i = 0; i < m; i++) {
        if (a[i][0] < minV) {
            min = i;
            minV = a[i][0];
        }
        if (a[i][m - 1] > maxV) {
            max = i;
            maxV = a[i][m - 1];
        }
    }

    int left = a[min][0];
    int right = a[max][m - 1];

    while (right - left > 1) {
        int centre = (right + left) / 2;
        int less = 0;
        int more = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < centre) less++;
                else if (a[i][j] > centre) more++;
            }
        }
        if (((less + more) % 2 > 0) && (abs(less - more) < 2)) {
            return centre;
        }
        if (more > less) left = centre;
        else if (less > more) right = centre;
        else if (more == less) return centre;
    }
}

int main() {
    int *a = new int[28]{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 5, 5, 5, 5, 6, 9, 9, 9, 9, 9, 9};
    cout << "Position of first '2' is " << binarySearchOfStart(a, 2, 0, 27) << endl;
    cout << "Position of last '5' is " << binarySearchOfEnd(a, 5, 0, 27) << endl;
    int b[3][3] = {{1,  3,  4},
                   {6,  8,  10},
                   {45, 67, 68}};

    int c[4][4] = {{4, 6, 8, 9},
                   {1, 4, 5, 6},
                   {2, 4, 7, 10},
                   {3, 6, 8, 12}};
    cout << "Is there a number 10 in the matrix? " << binarySearchInMatrix(b, 10, 3, 3) << endl;
    cout << "Square root of 167 is " << binarySquareRootSearch(167) << endl;
    cout << "The median of the matrix is " << binarySearchForMedianOfMatrix(c, 4, 4);

    return 0;
}
