#include <iostream>
#include <string>
using namespace std;

void insertionSort(int arr[], int length) {
    int i, j, k, key;

    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int key = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = key;
        }

        for (k = 0; k < i + 1; k++) {
            cout << arr[k] << ";";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    insertionSort(array, n);

    return 0;
}