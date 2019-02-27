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
//序列成环问题
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        scanf("%d", &N);
        map<int,pair<int,int> > mp;
        map<int,int> visit;
        string str;
        for(int i = 0; i < N; i++)
        {
            cin>>str;
            if(str[0]==str[str.length()-1])
                visit[str[0]-'a']++;
            else
            {
                mp[str[0]-'a'].first++;
                mp[str[str.length()-1]-'a'].second++;
            }
        }
        int flag=1;
        for(int it = 0; it < 26; it++)
        {
            if(visit[it]!=0)
            {
                if(visit[it]!=mp[it].first || visit[it]!=mp[it].second)
                {
                    if(visit[it]==N)
                        continue;
                    flag=0;
                    break;
                }
            }
            else
            {
                if(mp[it].first!=mp[it].second)
                {
                    flag=0;
                    break;
                }
            }
        }
        cout<<flag<<endl;
    }

    return 0;
}
