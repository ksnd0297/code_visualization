#include<iostream>
// https://www.acmicpc.net/problem/18870
#include<algorithm>

using namespace std;

struct press{
    int value;
    int nowValue;
    int nextValue;
};
bool cmp1(press a, press b){
    return a.value < b.value;
}

bool cmp2(press a, press b){
    return a.nowValue < b.nowValue;
}
press p[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt =0;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> p[i].value;
        p[i].nowValue = i;
    }
    sort(p,p+n,cmp1);

    for(int i=0;i<n;){
        p[i].nextValue = cnt;
        int j= i+1;
        while(p[i].value == p[j].value){
            p[j].nextValue = cnt;
            j++;
        }
        i=j;
        cnt++;
    }

    sort(p,p+n,cmp2);

    for(int i=0;i<n;i++){
        cout << p[i].nextValue << " ";
    }
}