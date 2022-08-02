#include <iostream>
using namespace std;

int partition(int A[], int p, int r) {
    
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i += 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return (i + 1);
}
int partitionRand(int A[], int p, int r) {
    
    srand (time(NULL));
    int i = p + rand() % (r - p);
    swap(A[r], A[i]);
    return partition(A, p, r);
}
void quickSortRand(int A[], int p, int r) {
    
    if (p < r) {
        int q = partitionRand(A, p, r);
        quickSortRand(A, p, q - 1);
        quickSortRand(A, q + 1, r);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSortRand(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }
    return 0;
}