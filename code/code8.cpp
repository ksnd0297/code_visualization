// https://www.acmicpc.net/problem/11053
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,mx=0, b[1001]={0,}, chk[1001]={0,};
    cin>>n;
    for(int i=0;i<n;i++)   
        cin>>b[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]<b[j] && chk[i]+1>chk[j]){
                chk[j]=chk[i]+1;
            }
        }
        if(chk[i]>mx)mx=chk[i];
    }
    cout<<mx+1;
}