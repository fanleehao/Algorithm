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
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

//���㵹�õĸ���
void printArr(int *arr, int n)
{
    for(int i = 0 ; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//�����˶��ֲ��ң�����������������򣨻��߸��º���Ҫ��������----����Ҳ��n(logn + n)?

//2.ʹ�ù鲢����---���Σ���mergeʱÿ���ұ�С����ߵľ�+1

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
