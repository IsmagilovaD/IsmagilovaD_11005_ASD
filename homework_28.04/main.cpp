#include <iostream>
using namespace std;

//№2---------------------------------------
int numberOfPaths(int n){
    int p1 = 0;
    int p2 = 1;
    int ans = 0;
    for (int i = 0; i < n; i++){
      ans = p1 + p2;
      p1 = p2;
      p2 = ans;
    }
    return ans;
}

//№3---------------------------------------
int matrix[10][10];

int numberOfPathsMatrix(int n, int m){
    for (int i = 0; i < m; i ++){
        matrix[n-1][i] = 1;
    }
    for (int i = 0; i < n; i++){
        matrix[i][0] = 1;
    }
    for (int i = n-2; i >= 0; i--){
        for (int j = 1; j < m; j++){
            matrix[i][j] = matrix[i+1][j] + matrix[i][j-1];
        }
    }
    return matrix[0][m-1];
}

int main() {
    cout << numberOfPaths(5) << endl;
    cout << numberOfPathsMatrix(5,6);
    return 0;
}
