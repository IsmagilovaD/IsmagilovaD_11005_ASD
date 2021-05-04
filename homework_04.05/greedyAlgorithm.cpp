#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//№1---------------------------------------
int *coinCounter(int x) {
    int *a = new int[3];
    for (int i = 0; i < 3; i++) {
        a[i] = 0;
    }
    while (x >= 10) {
        x = x - 10;
        a[2] = a[2] + 1;
    }
    while (x >= 5) {
        x = x - 5;
        a[1] = a[1] + 1;
    }
    while (x > 0) {
        x = x - 1;
        a[0] = a[0] + 1;
    }
    return a;
}

//№2---------------------------------------

bool compareByValue(int *a, int *b) {
    return a[1] > b[1];
}

int floor(int x, int *a) {
    if (a[x] == 1) {
        a[x] = 0;
        return x;
    } else
        while (a[x] != 1 & x >= 0) {
            --x;
        }
    if (x >= 0) {
        a[x] = 0;
        return x;
    }
    return -1;
}

int *deadlineCounter(vector<int *> a) {
    sort(a.begin(), a.end(), compareByValue);
    int *ans = new int[5];
    int *forFloor = new int[5]{1, 1, 1, 1, 1};

    for (int i = 0; i < 5; i++) {
        int *p = a[i];
        ans[floor(p[2] - 1, forFloor)] = p[0];
    }

    return ans;
}


int main() {
    int *a = coinCounter(26);
    cout << "first task : ";
    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int *> v1;
    int *t1 = new int[3]{1, 4, 5};
    int *t2 = new int[3]{2, 10, 5};
    int *t3 = new int[3]{3, 12, 1};
    int *t4 = new int[3]{4, 8, 4};
    int *t5 = new int[3]{5, 1, 5};
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);
    v1.push_back(t4);
    v1.push_back(t5);

    int *ans = deadlineCounter(v1);
    cout << "second task : ";
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
