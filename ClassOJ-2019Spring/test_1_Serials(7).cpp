#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff输入的每一行是用空格隔开的0或1
#define MAX 101000
using namespace std;

int DoubleEndLIS(vector<int> data)//当然也可以使用O(nlogn)的算法
{
	int length = data.size(),i,j,res = length;
	if(length == 0)return 0;
	vector<int> B(length,1),C(length,1);
	int *posB = new int[length];
	int *posC = new int[length];
	for(i = 0;i < length;++i)//从左向右
	{
		for(j = 0;j < i;++j)
		{
			if(data[j] < data[i] && B[j]+1 > B[i]){
                B[i] = B[j]+1;
                posB[i] = j;
			}

		}
	}
	for(i = length-1;i >= 0;--i)//从右向左
	{
		for(j = length-1;j > i;--j)
		{
			if(data[j] < data[i] && C[j]+1 > C[i]){
                C[i] = C[j]+1;
                posC[i] = j;
			}
		}
	}
	int flag = 0;
	for(i = 0;i < length;++i)
	{
		if(length - B[i] - C[i] + 1 < res){
            res = length - B[i] - C[i] + 1;
            flag = i;
		}
	}
    vector<int> aaa;
    int temp1 = B[flag];
    int temp2 = C[flag] - 1;
    int index = flag;
    while(temp1--){
        aaa.push_back(data[index]);
        //cout<<data[index]<<" ";
        index = posB[index];
    }
    for(int s = aaa.size() - 1; s >= 0; s--){
        cout<<aaa[s]<<" ";
    }
    index = flag;
    while(temp2--){
        index = posC[index];
        cout<<data[index]<<" ";
        aaa.push_back(data[index]);
    }
	return res;
}
int main()
{
    string line;
    stringstream ss;
    getline(cin, line);

    ss<<line;
    vector<int> vec;
    int k =0;
    while(ss>>k)
    {
        vec.push_back(k);   //通过stringtream和vector
    }
    int vec_size = vec.size();
    //cout<<"(Using  STL)Remove "<<DoubleEndLIS(vec)<<"  elements\n";
    DoubleEndLIS(vec);
    return 0;


}
