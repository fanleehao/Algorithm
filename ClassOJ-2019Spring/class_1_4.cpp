#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<map>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

void printArr(int *arr, int n){
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d", &T);
    int M,N;
    scanf("%d%d", &M, &N);
    int arr1[M], arr2[N], arr2_sort[N];
    for(int i = 0; i < M; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &arr2[i]);
    }
    memset(arr2_sort, 0, N*sizeof(int));
    memcpy(arr2_sort, arr2, N * sizeof(int));
    sort(arr2_sort, arr2_sort + N + 1);
    //printArr(arr2_sort, N);

    int temp[M], rest[M], k = 0;
    memset(temp, 0, M*sizeof(int));
    for(int i = 0; i < M; i++){
        //二分查找要求有序且区间左闭右开
        if(binary_search(arr2_sort, arr2_sort + N + 1, arr1[i])){
            //printf("----%d\n",arr1[i]);
            temp[arr1[i]]++;
        }
        else rest[k++] = arr1[i];
    }
    sort(rest, rest + k);
    for(int i = 0; i < N; i++){
        if(temp[arr2[i]] != 0){
            for(int j = 0; j < temp[arr2[i]]; j++){
                printf("%d ", arr2[i]);
            }
            //printf("----%d", temp[arr2[i]]);
        }
    }

    for(int i = 0; i < k; i++){
        printf("%d ", rest[i]);
    }
}
