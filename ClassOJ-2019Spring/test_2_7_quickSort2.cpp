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
int Partition(vector<int> &arr, int left, int right)
{
	int key = arr[left];		// 将一个数作为基准值
	int i = left, j = right;

	while(i < j)
	{
		// 从最右边找第一个小于基准值的数字
		while(i < j && arr[j] >= key)
            j--;
		arr[i] = arr[j];	// 放在基准值左边

		// 从最左边找第一个大于基准值的数字
		while(i < j && arr[i] <= key)
            i++;
		arr[j] = arr[i];	// 放在基准值的右边
	}
	arr[i] = key;		    // 确定基准值的位置
	return i;				// 返回基准值的位置
}

void quickSort2(vector<int> &arr, int n)
{
	if (n <= 1)
        return;
	stack<int> SStack;

	// 将最大的区间压入栈
	SStack.push(0);
	SStack.push(n-1);

	int left, right, mid;
	while(!SStack.empty())
	{   // 注意按相反的顺序取出两边大小

		right = SStack.top();
		SStack.pop();
		left = SStack.top();
		SStack.pop();

		// 计算基准值的位置进行新子区间划分
		mid = Partition(arr, left, right);

		// 将左边新区间入栈
		if (mid-1 > left)
		{
			SStack.push(left);
			SStack.push(mid-1);
		}

		//将右边新区间入栈
		if (mid+1 < right)
		{
			SStack.push(mid+1);
			SStack.push(right);
		}
	}
}
int main(){
    int n, num;
    while(scanf("%d", &n)!=EOF){
        vector<int> vec;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            vec.push_back(num);
        }
        //printf("---%d----\n", vec.size());
        quickSort2(vec, n);
        for(int i = 0; i < vec.size() - 1; i++)
            printf("%d ", vec[i]);
        printf("%d\n", vec[vec.size() - 1]);
    }
    return 0;

}
