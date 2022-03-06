#include<iostream>
using namespace std;

int a[5][5] = {{1,4,7,11,15},
                {2,5,8,12,19},
                {3,6,9,16,22},
                {10,13,14,17,24},
                {18,21,23,26,30}};

bool find(int x) {
    int i = 0, j = 4;
    while (i < 5 && j >= 0) {
        if (a[i][j] == x)
            return true;
        else if (a[i][j] < x)
            i++;
        else 
            j--;
    }
    return false;
}

int main() {
    int x = 0;
    while (x != -1) {
        cin >> x;
        if (find(x))
            cout << "True." << endl;
        else 
            cout << "False." << endl;
    }
    return 0;
}