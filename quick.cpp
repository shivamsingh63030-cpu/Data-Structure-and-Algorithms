#include <iostream>
using namespace std;

int Quick_sort(int A[], int l, int r) {
    if (l < r) {
        int pivot = A[r];
        int i = l - 1;
        

        for (int j = l; j < r-1; j++) {
            if (pivot >= A[j]) {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[r]);
        int p= i + 1;

        Quick_sort(A, l, p - 1);
        Quick_sort(A, p + 1, r);
    }
    return 0;
}

int main() {
   int a[]= {7,3,6,2,9,1};
   int n=sizeof(a)/sizeof(a[0]);
   Quick_sort(a,0,n-1);
   for(int i=0; i<n; i++){
    cout << a[i];
   }

 return 0;
}