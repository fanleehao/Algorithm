#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<stack>
#include<map>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
//归并排序
//非递归
//将数组 a[low,mid] 与 a(mid,high] 合并（归并）
void Merge(int * a, int low, int mid, int high, int * temp)
{
    int i,j,k;
    i = low;
    j = mid + 1;//避免重复比较a[mid]
    k = 0;
    while (i <= mid && j <= high)//数组a[low,mid]与数组(mid,high]均没有全部归入数组temp中去
    {
        if(a[i] <= a[j])        //如果a[i]小于等于a[j]
            temp[k++] = a[i++]; //则将a[i]的值赋给temp[k]，之后i,k各加一，表示后移一位
        else
            temp[k++] = a[j++]; //否则，将a[j]的值赋给temp[k]，j,k各加一
    }
    while(i <= mid)             //表示数组a(mid,high]已经全部归入temp数组中去了，而数组a[low,mid]还有剩余
        temp[k++] = a[i++];     //将数组a[low,mid]剩下的值，逐一归入数组temp
    while(j <= high)           //表示数组a[low,mid]已经全部归入到temp数组中去了，而数组(mid,high]还有剩余
        temp[k++] = a[j++];     //将数组a(mid,high]剩下的值，逐一归入数组temp

    for (i = 0; i < k; i++)     //将归并后的数组的值逐一赋给数组a[low,high]
        a[low+i] = temp[i];     //注意，应从a[low+i]开始赋值
}

//二路归并（递归实现）
void MergeSort(int * a, int low, int high, int * temp)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        MergeSort(a,low,mid,temp);      //左边有序
        MergeSort(a,mid+1,high,temp);   //右边有序
        Merge(a,low,mid,high,temp);     //再将两个有序序列合并
    }
}

int main(){


    int n,num;
    while(scanf("%d", &n)!=EOF){
        int a[n], p[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        MergeSort(a,0,n-1,p);

        for(int i = 0; i < n - 1; i++){
            printf("%d ", p[i]);
        }
        printf("%d\n", p[n - 1]);
    }

    return 0;
}
