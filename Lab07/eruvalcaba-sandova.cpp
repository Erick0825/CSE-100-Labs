#include <iostream>
#include <limits.h>
using namespace std;

void printCutRod(int r[], int s[], int n) {
    cout<<r[n]<<endl;
    
    while (n > 0) {
        cout<<s[n - 1]<<" ";
        n -= s[n - 1];
}
    cout<<-1<<endl;
}
void cutRod(int p[], int n) {
    int r[n + 1];
    int s[n];
    r[0] = 0;

    for (int i = 1; i <= n; i++) {
        int q = INT_MIN;
        
        for (int j = 0; j < i; j++) {
        
            if (q < (p[j] + r[i - j - 1])) {
                q = (p[j] + r[i - j - 1]);
                s[i - 1] = j + 1;
            }
        }
        r[i] = q;
}
    printCutRod(r, s, n);
}
int main(int argc, char ** argv) {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
}
    cutRod(arr, n);

    return 0;
}