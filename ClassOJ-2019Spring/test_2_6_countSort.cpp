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

void CountSort(vector<int> &arr, int maxVal) {
	int len = arr.size();
	if (len < 1)
		return;
	vector<int> coun(maxVal+1, 0);    //��������±�
	vector<int> tmp(arr);
	for(int i = 0; i < len; i++)
		coun[arr[i]]++;
	for (int i = 1; i <= maxVal; ++i)
		coun[i] += coun[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		arr[coun[tmp[i]] - 1] = tmp[i];   //��ʾ�����Ľ�������λ�õ���Ӧ���Ƕ���
		coun[tmp[i]]--;				//ע������Ҫ��1��������ͬ����
	}
	for(int i = 0; i < arr.size() - 1; i++){
        printf("%d ", arr[i]);
	}
	printf("%d\n", arr[arr.size() - 1] );
}
int main(){
    int n, num, maxVal;
    while(scanf("%d", &n)!=EOF){
        vector<int> vec;
        maxVal = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            vec.push_back(num);
            maxVal = maxVal > num ? maxVal:num;
        }
        CountSort(vec, maxVal);

    }

}
