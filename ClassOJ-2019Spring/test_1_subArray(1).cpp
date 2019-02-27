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
#include<iomanip>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff输入的每一行是用空格隔开的0或1
#define MAX 101000
using namespace std;

int getSum(vector<int> vec, int len, int num){
    int res = 0;
    deque<int> qmax;
    deque<int> qmin;

    int i = 0;
    int j = 0;
    while(i < len){
        while(j < len){
            //遍历处理，如果当前值较大，则放进队尾
//            cout<<"*****:"<<vec[j]<<endl;
            while(!qmax.empty() &&  vec[j] >= vec[qmax.back()]){
                qmax.pop_back();
            }
            qmax.push_back(j);    //队列中多个值,且从大到小，如果值一致，则是最后出现的下标
            //子数组的最小值
            while (!qmin.empty() && vec[j] <= vec[qmin.back()])
			{
				qmin.pop_back();
			}
			qmin.push_back(j);
            if(vec[qmax.front()] - vec[qmin.front()] > num){
                break;  //不满足条件了
            }
            j++;

        }
        //cout<<"i--j:"<<i<<":"<<j<<endl;
        res += j - i;   //以i为起点的子数组的个数
        //判断队列中的元素
        if(qmax.front() == i)
            qmax.pop_front();
        if(qmin.front() == i)
            qmin.pop_front();
        i++;
    }

    return res;
}

int main(){
    string line;
    stringstream ss;
    getline(cin, line);

    ss<<line;
    vector<int> vec;
    int i =0;
    while(ss>>i){vec.push_back(i);}     //通过stringtream和vector
    int vec_size = vec.size();


    int n;
    scanf("%d", &n);
    //连续子集的个数
    int res;
    res = vec_size * (vec_size + 1) / 2;
    res = res - getSum(vec, vec_size, n);
    printf("%d\n", res);
    deque<int> q;
//    q.push_back(10);
//    q.push_back(20);
//    q.push_back(30);
//    cout<<q.front()<<endl;
    //cout<<!q.empty()<<endl;
}
