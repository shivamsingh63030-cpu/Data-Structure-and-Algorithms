#include <iostream>
using namespace std;

void mergeSort(int A[], int B[], int C[], int m, int n) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];   
            j++;
        }
        k++;
    }

    while (i < m) {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j < n) {
        C[k] = B[j];
        j++;
        k++;              
    }
}

int main() {
    int A[] = {1, 2, 5, 7};
    int B[] = {3, 4, 7};
    int C[7];

    int m = 4, n = 3;

    mergeSort(A, B, C, m, n);  

    for (int i = 0; i < m + n; i++) {
        cout << C[i] << " ";
    }

    return 0;
}