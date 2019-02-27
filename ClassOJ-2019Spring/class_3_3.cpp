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
#include<stack>
#include<map>
#include<cstdlib>
#include<bits/stdc++.h>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
//最长降序子序列
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        string s,res="";
        cin>>s;
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'A']=1;
        }
        for(int j=1;j<26;j++)
        {
            for(int i=25;i>=0;i--)
            {
                if(arr[i]!=0)
                {
                    string ss="";
                    ss+=(char)('A'+i);
                    for(int k=i-j;k>=0;k=k-j)
                    {
                        if(arr[k]!=0)
                        {
                          ss+=(char)('A'+k);
                        }
                        else break;
                    }
                    if(ss.length()>res.length())
                    res=ss;
                }
            }

        }
        cout<<res<<"\n";
    }
	return 0;
}
