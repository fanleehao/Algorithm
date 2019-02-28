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

void DFS(int st, int vis[], int &ret){

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
       bool vis[n];
       cout<<vis[n-1]<<endl;
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
       for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout<<Arr[i][j]<<" ";
            cout<<endl;
       }
       int ret = 0;
       DFS(st,vis,ret);
    }
    return 0;
}
