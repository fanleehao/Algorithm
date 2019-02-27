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

//计算倒置的个数
void printArr(int *arr, int n)
{
    for(int i = 0 ; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//利用了二分查找，但是这个又用了排序（或者更新后需要插入排序）----好像也是n(logn + n)?

//2.使用归并排序---分治，在merge时每次右边小于左边的就+1

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int M, res = 0;
        scanf("%d", &M);
        int arr[M], heap[M];
        for(int i = 0; i < M; i++)
        {
            scanf("%d", &arr[i]);
        }
        heap[0]=arr[0];
        for(int i = 1; i < M; i++){
            int index = upper_bound(heap, heap + i, arr[i]) - heap;
            res += (i - index);
            heap[i] = arr[i];
            sort(heap, heap + i + 1);
        }
        printf("%d\n", res);
    }

}
