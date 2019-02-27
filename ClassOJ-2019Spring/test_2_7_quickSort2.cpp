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
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
int Partition(vector<int> &arr, int left, int right)
{
	int key = arr[left];		// ��һ������Ϊ��׼ֵ
	int i = left, j = right;

	while(i < j)
	{
		// �����ұ��ҵ�һ��С�ڻ�׼ֵ������
		while(i < j && arr[j] >= key)
            j--;
		arr[i] = arr[j];	// ���ڻ�׼ֵ���

		// ��������ҵ�һ�����ڻ�׼ֵ������
		while(i < j && arr[i] <= key)
            i++;
		arr[j] = arr[i];	// ���ڻ�׼ֵ���ұ�
	}
	arr[i] = key;		    // ȷ����׼ֵ��λ��
	return i;				// ���ػ�׼ֵ��λ��
}

void quickSort2(vector<int> &arr, int n)
{
	if (n <= 1)
        return;
	stack<int> SStack;

	// ����������ѹ��ջ
	SStack.push(0);
	SStack.push(n-1);

	int left, right, mid;
	while(!SStack.empty())
	{   // ע�ⰴ�෴��˳��ȡ�����ߴ�С

		right = SStack.top();
		SStack.pop();
		left = SStack.top();
		SStack.pop();

		// �����׼ֵ��λ�ý����������仮��
		mid = Partition(arr, left, right);

		// �������������ջ
		if (mid-1 > left)
		{
			SStack.push(left);
			SStack.push(mid-1);
		}

		//���ұ���������ջ
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
