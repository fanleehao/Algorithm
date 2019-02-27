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
//题名：书本分发
//https://www.geeksforgeeks.org/allocate-minimum-number-pages/
//https://blog.csdn.net/xuruoxin/article/details/9182179


bool isPossible(int nums[], int n, int m, int curr_min)
{
	int studentsRequired = 1;
	int curr_sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > curr_min)
			return false;

		if (curr_sum + nums[i] > curr_min)
		{
			studentsRequired++;
			curr_sum = nums[i];

			if (studentsRequired > m)
				return false;
		}

		else
			curr_sum += nums[i];
	}
	return true;
}

int findPages(int nums[], int n, int m)
{
	long long sum = 0;
	//不匹配
	if (n < m) return -1;
	// 总数
	for (int i = 0; i < n; i++)
		sum += nums[i];
	int start = 0, en = sum;
	int result = INF;
	while (start <= en)
	{
		int mid = (start + en) / 2;
		if (isPossible(nums, n, m, mid))
		{
			result = min(result, mid);
			en = mid - 1;
		}
		else
			start = mid + 1;
	}
	return result;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        int nums[60];
        for(int i = 0; i < N; i++){
            scanf("%d", &nums[i]);
        }
        int M;
        scanf("%d", &M);
        cout<<findPages(nums, N, M)<<endl;
    }
    return 0;
}
