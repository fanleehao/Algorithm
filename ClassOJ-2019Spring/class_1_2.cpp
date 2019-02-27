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
//统计交换次数
int findIndex(int *arr, int N, int num){
    for(int i = 0; i < N; i++){
        if(num == arr[i])
            return i;
    }
    return -1;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int arr[N], sort_arr[N], res = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
            sort_arr[i] = arr[i];
        }

        sort(sort_arr, sort_arr + N);
        for(int i = 0; i < N; i++){
            //在未排序的数组中找位置
            int index = findIndex(arr, N, sort_arr[i]);
            if(index == i)
                continue;
            else{
                swap(arr[i], arr[index]);
                res++;
            }
        }
        printf("%d\n",res);

    }
}
