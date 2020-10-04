#include <bits/stdc++.h>
using namespace std;

bool isPossible(int **arr, int n, int row, int col) {
    for(int i = row - 1; i >= 0; i--) {
        if(arr[i][col]) {
            return false;
        }
    }
    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(arr[i][j]) {
            return false;
        }
    }
    
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(arr[i][j]) {
            return false;
        }
    }
    
    return true;
}

void helper(int **arr, int n, int row) {
    if(n == row) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    for(int j = 0; j < n; j++) {
        if(isPossible(arr, n, row, j)) {
            arr[row][j] = 1;
            helper(arr, n, row + 1);
            arr[row][j] = 0;
        }
    }
    return;
}


void placeNQueens(int n){
	int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    helper(arr, n, 0);
}

int main() {
    placeNQueens(8);
}
