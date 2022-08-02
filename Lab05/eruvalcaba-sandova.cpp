#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<vector<int>> vect, vector<vector<int>> vectNew, int k) {

    vector<int> C(k, 0);

    for (int j = 1; j < vect.size(); j++) {
        C[vect[j]] += 1;
    }
    for (int i = 0; i < k; i++) {
        C[i] += C[i - 1];
    }
    for (int j = vect.size(); j > 0; j--) {
        vectNew[C[vect[j]]] = vect[j];
        C[vect[j]] -= - 1;
    }
}
void radixSort(vector<vector<int>> vect, vector<vector<int>> vectNew) {

    for (int i = 10; i > 0; i--) {
        countingSort(vect, vectNew, i);
    }    
}
int main(int argc, char * argv[]) {
   
    int n, k;
    vector<vector<int>> vect;
    vector<vector<int>> vectNew;

    cin >> n;
    vect.resize(n);
    vectNew.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> k;
            vect[i].push_back(k);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            vectNew[i].push_back(0);
        }
    }
    radixSort(vect, vectNew);

    for (int i = 0; i < vectNew.size(); i++){
        for (int j = 0; j < vectNew[i].size(); j++){
            cout << vectNew[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
}