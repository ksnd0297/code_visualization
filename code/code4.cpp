// https://www.acmicpc.net/problem/5525
#include <stdio.h>

int main(){
        int N, M;
        scanf("%d %d", &N, &M);

        char string[1000000];
        scanf("%s", string);

        int check = 0;
        int sum = 0;
        int count = 1;
        for(int i = 0; i < M-1; i++){
                if(string[i] == 'I')
                        check = 1;
                if(check == 1){
                        if(string[i] == 'I' && string[i+1] == 'O')
                                count++;
                        else if(string[i] == 'O' && string[i+1] == 'I')
                                count++;
                        else{
                                if(count - 2*N-1 >= 0)
                                        sum += 1 + (count - 2*N - 1) / 2;
                                count = 1;
                                check = 0;
                        }
                }
        }
        if(count - 2*N-1 >= 0)
                sum += 1 + (count - 2*N - 1) / 2;

        printf("%d\n", sum);


        return 0;
}
