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
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
int Arr[128][128]={0};

void BFS(int st,int n){
    bool *vis = new bool[n];
    for(int i = 0; i < n; i++)
        vis[i] = false;
    int cou = 0;
    queue<int> q;
    while(cou<n){
        if(vis[st]==false){
            char c = st + 97;
            cout<<c<<" ";
            cou++;
        }
        vis[st] = true;
        q.push(st);
        for(int i = 0; i <n;i++){
            if(Arr[st][i]!=0 && Arr[st][i] != INT_MAX && vis[i] == false){
                q.push(i);
            }
        }
        q.pop();
        st = q.front();
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int n, st;
       char c;
       cin>>n>>c;
       st = c-97;
       int node[n];
       for(int i = 0; i < n;i++){
            cin>>c;
            node[i] = c-97;
       }

       for(int i = 0; i < n; i++){
            cin>>c;
            for(int j = 0; j< n;j++){
                cin>>Arr[node[i]][node[j]];
            }
            Arr[i][i] = INT_MAX;
       }
       int ret = 0;
       BFS(st, n);

    }
    return 0;
}
