// https://www.acmicpc.net/problem/1107
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#define endl "\n"

using namespace std;

int n, a, chanel;
string chanel_str;
int len;
int num[10];
vector<int> buttons;
void Input() {
    cin >>chanel>> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        num[a] = -1;
    }
    for (int i = 0; i < 10; i++) {
        if (num[i] == 0) buttons.push_back(i);
    }

}

int dfs(string s) {
    if (s.size() == len) {
        cout << s << endl;
        return abs(stoi(s) - chanel);
    }

    int rt = INT_MAX;
    char c;
    for (int i = 0; i < buttons.size(); i++) {
        c = buttons[i] + '0';
        rt = min(rt, dfs(s + c));
    }
    return rt;
}

void Solve() {
    chanel_str = to_string(chanel);
    len = chanel_str.size();
    int ans = abs(chanel - 100); //+, -로만 가는 경우를 기본값
    if(buttons.size()!=0) ans = min(len + dfs(""), ans);
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();

    return 0;
}


