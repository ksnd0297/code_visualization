// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int len;
    int count = 0;
    string arr;

    cin >> n;
    cin >> len;
    cin >> arr;

    for (int i = 0; i < len; i++) {
        if (arr[i] == 'I') {
            int check = 0;
            int j = i;

            while (arr[j + 1] == 'O' && arr[j + 2] == 'I') {
                check++;
                if (check == n) {
                    count++;
                    break;
                }
                j += 2;
            }
       }
    }

    cout << count;
}