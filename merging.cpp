#include <iostream>
using namespace std;

void Merge(int A[], int l, int r, int mid){
    int m = mid - l + 1;
    int n = r - mid;
    int L[m], R[n];
    
    for(int i = 0; i < m; i++){
        L[i] = A[l + i];
    }
    for(int j = 0; j < n; j++){
        R[j] = A[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = l;
    while(i < m && j < n){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    } 
    while(i < m){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n){
        A[k] = R[j];
        j++;
        k++;
    }
}
int main() {
    int A[] = {1, 2, 5, 7};
    int B[] = {3, 4, 7};
    int C[7];

    int m = 4, n = 3;

    Merge(A, 0, m + n - 1, m - 1  );  

    for (int i = 0; i < m + n; i++) {
        cout << C[i] << " ";
    }

    return 0;
}