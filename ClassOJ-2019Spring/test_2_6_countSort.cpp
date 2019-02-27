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

void CountSort(vector<int> &arr, int maxVal) {
	int len = arr.size();
	if (len < 1)
		return;
	vector<int> coun(maxVal+1, 0);    //方便对齐下标
	vector<int> tmp(arr);
	for(int i = 0; i < len; i++)
		coun[arr[i]]++;
	for (int i = 1; i <= maxVal; ++i)
		coun[i] += coun[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		arr[coun[tmp[i]] - 1] = tmp[i];   //表示排序后的结果，这个位置的数应该是多少
		coun[tmp[i]]--;				//注意这里要减1，出现相同的数
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
