// https://www.acmicpc.net/problem/2108
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  
  int num1 = *(int *)a; 
  int num2 = *(int *)b;

  if (num1 < num2) 
    return -1; 

  if (num1 > num2) 
    return 1;

  return 0; 
}

int main(void) {
  int n, i, iSum = 0, iAvg, iMid, iMost, index, max = 0, cnt = 0, iRange;
  int number[500001] = {};
  int hash[8001] = { 0 };
  
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &number[i]);
    iSum += number[i];
  }

  qsort(number, n, sizeof(int), compare); //퀵소트 내장함수 사용

  iAvg = floor((double)iSum / n + 0.5);

  printf("%d\n", iAvg);
  printf("%d\n", number[n/2]);

  for(i=0 ; i<n ; i++){
    index = number[i] + 4000;
    hash[index] += 1;

    if(hash[index] > max){
      max = hash[index];
    }
  }

  index = 0;
  
  for(i=0 ; i < 8001 ; i++){
    if(hash[i] == 0){
      continue;
    }

    if(hash[i] == max){
      if(cnt == 0){
        index = i;
        cnt++;
      }
      else if(cnt == 1){
        index = i;
        break;
      }
    }
  }
  printf("%d\n", index - 4000);
  printf("%d\n", number[n-1] - number[0]);
}