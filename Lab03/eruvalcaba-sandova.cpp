#include <iostream>
#include <limits.h>
using namespace std;

int maxCrossingSubarray(int A[], int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum)
            right_sum = sum;
    }
    return (right_sum + left_sum);
}
int maxSubarray(int A[], int low, int high) {
    if (high == low)
        return (A[low]);
    else {
        int mid = (low + high) / 2;
        int left_sum = maxSubarray(A, low, mid);
        int right_sum = maxSubarray(A, mid + 1, high);
        int cross_sum = maxCrossingSubarray(A, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum)
            return (left_sum);
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return (right_sum);
        else
            return (cross_sum);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSubarray(arr, 0, n - 1);

    return 0;
}