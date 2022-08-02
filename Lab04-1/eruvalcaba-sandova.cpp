#include <iostream>
using namespace std;

void maxHeapify(int A[], int heapSize, int i) {
    int largest;
    int l = (i * 2);
    int r = (i * 2) + 1;

    if (l <= heapSize && A[l] > A[i])
        largest = l;
    else
        largest = i;
    
    if (r <= heapSize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, heapSize, largest);
    }
}
void buildMaxHeap(int A[], int heapSize, int n) {
    for (int i = n / 2; i > 0; i--) {
        maxHeapify(A, heapSize, i);
    }
}
void heapSort(int A[], int n) {
    int heapSize = n;
    buildMaxHeap(A, heapSize, n);
    for (int i = heapSize; i > 1; i--) {
        swap(A[1], A[i]);
        heapSize -= 1;
        maxHeapify(A, heapSize, 1);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ";";
    }
    return 0;
}