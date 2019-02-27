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
#include<bits/stdc++.h>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
double ans(int i,double a[],int n)
{
	double low,high,mid,r=0;
    low=a[i];
    high=a[i+1];
    while(low<high)
    {
		mid=low+(high-low)/2;
		r=0;
		for(int j=0;j<n;j++)
		{
			if(j<=i)
			{
				r=r+1/(mid-a[j]);
			}
			else
			r=r+1/(mid-a[j]);
		}
		if(r<=0.000000000001&&r>=0)return mid;
		else if(r>0.000000000001)
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
 }
    return 0;
}
//磁铁中力为0的点
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        double arr[N];
        for(int i = 0; i < N; i++){
            scanf("%lf", &arr[i]);
        }
        for(int i = 0; i < N - 2; i++){
            printf("%.2f ", ans(i, arr, N));
        }
         printf("%.2f\n", ans(N - 2, arr, N));
    }

    return 0;
}
