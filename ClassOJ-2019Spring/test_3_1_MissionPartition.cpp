#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
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
bool cmp(vector<int> a,vector<int> b){
    for(int i = 0; i < a.size();i++){
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
}

int main()
{
//    vector<int> t1={2,1,3,4};
//    vector<int> t2={2,1,4,3};
//    vector<vector<int>> ret;
//    ret.push_back(t2);
//    ret.push_back(t1);
//    sort(ret.begin(), ret.end(),cmp);
//    for(int i = 0; i < ret.size(); i++){
//        for(int j = 0 ; j < 4;j++)
//            cout<<ret[i][j]<<" ";
//        cout<<endl;
//    }

    int T;
    cin>>T;
    while(T--)
    {
        int num, minCost = MAX, cost=0;
        int x, y;
        cin>>num;
        int c[num+1][num+1],temp[num+1];
        char ch;
        while(cin>>x>>y){
            cin>>c[x][y];
            if((ch=getchar()) == '\n')
                break;
        }
        for(int i=1; i<=num; i++)           //����ɱ��ľ���ֵ
        {
            temp[i]=i;                  //����ȫ���и������飬Ĭ������
        }
        vector<vector<int>> ret;
        vector<int> tmp;
        do                              //����next_permutation����������������ȫ����
        {
            cost=0;
            tmp.clear();
            for(int i=1; i<= num; i++)
                cost += c[i][temp[i]];
            if(cost < minCost){
                ret.clear();
                minCost=cost;           //��¼��С����
                for(int j = 1; j <= num; j++)
                    tmp.push_back(temp[j]);
            }else if(cost == minCost){
                for(int j = 1; j <= num; j++)
                    tmp.push_back(temp[j]);
            }
            if(!tmp.empty())
                ret.push_back(tmp);
        }
        while(next_permutation(temp+1, temp+1+num));
        sort(ret.begin(),ret.end(),cmp);
        int len = ret.size();
        for(int i = 0; i < len - 1;i++){
            for(int j = 0; j < num -1; j++)
                cout<<ret[i][j]<<" ";
            cout<<ret[i][num-1]<<",";
        }
        for(int j = 0;j<num-1;j++)
            cout<<ret[len-1][j]<<" ";
        cout<<ret[len-1][num-1]<<endl;
    }
    return 0;
}
