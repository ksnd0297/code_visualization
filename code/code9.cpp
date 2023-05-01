// https://www.acmicpc.net/problem/11052
#include <iostream>
#include <algorithm>

using namespace std;

int PN[2000];
int dp[2000];

int main()
{
    int N;

    cin >> N;
    PN[0] = 0;
    for(int i=1;i<=N;i++)
        cin >> PN[i]; 
    
    dp[0] = 0;
    dp[1] = PN[1];
    dp[2] = max((2*PN[1]),PN[2]);

    for(int i=3;i<=N;i++)
    {
        dp[i] = PN[i];
        for(int j=1;j<((i/2)+1);j++)
            dp[i] = max(dp[i],(dp[j]+dp[i-j]));
    }
    cout << dp[N];
}