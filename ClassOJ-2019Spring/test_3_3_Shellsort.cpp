#include<bits/stdc++.h>
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
//shell排序

void ShellSort(vector<int> &num, vector<int> increment){
    int tmp;
    int index;
    for(int k = 0; k < increment.size();k++){
        index = increment[k];
        int i,j;
        for(i = index; i< num.size();i++){
            if(num[i] < num[i-index]){
                tmp = num[i];
                for(j = i - index; j>=0 && num[j] > tmp; j = j - index){
                    num[j+index] = num[j];  //把大的放到后面
                }
                num[j+index] = tmp;
            }
        }
    }
    for(int i = 0; i < num.size()-1;i++){
        cout<<num[i]<<" ";
    }
    cout<<num[num.size()-1]<<"\n";
}
int main()
{
    int T;
    cin>>T;

    while(T--){
        vector<int> num;
        vector<int> increment;
        int a;char c;
        while(cin>>a){
            num.push_back(a);
            if((c=getchar())=='\n')
                break;
        }
        //cout<<num.size()<<endl;
        while(cin>>a){
            increment.push_back(a);
            if((c=getchar())=='\n')
                break;
        }
        //cout<<increment.size();
        ShellSort(num, increment);
    }
    return 0;
}
