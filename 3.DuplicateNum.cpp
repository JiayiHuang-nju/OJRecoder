#include<iostream>
using namespace std;

void swap(int a[], int x, int y) {
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
    return;
}

int duplicate(int a[], int length) {
    for (int i = 0; i < length; i++) {
        while (a[i] != i) {
            if (a[i] == a[a[i]]) 
                return a[i];
            else
                swap(a, i, a[i]);
        }
    }
    return -1;
}

int main() {
    int n = 0;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    cout << "Output:" << duplicate(a, n) << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}