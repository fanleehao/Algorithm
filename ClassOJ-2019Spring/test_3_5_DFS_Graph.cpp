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
bool vis[128];
int node[128];
int maxx = 0;
void DFS(int i, vector<int> &tmp, int n){
    vis[i] = true;
    for(int j = 0; j < n;j++){
        if(Arr[i][j]==1 && vis[j] == false){
            tmp.push_back(j);
            DFS(j, tmp, n);
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int n, st;
       int maxx = 0;
       char c;
       cin>>n>>c;
       st = c-97;
       for(int i = 0; i < n;i++){
            cin>>c;
            node[i] = c-97;
       }
       for(int i = node[0]; i < n; i++){
            cin>>c;
            for(int j = node[0]; j< n;j++){
                cin>>Arr[node[c-97]][node[j]];
            }
            vis[i] = false;
       }

//       for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++)
//                cout<<Arr[i][j]<<" ";
//            cout<<endl;
//       }
        vector<int> tmp;
        tmp.push_back(st);
        DFS(st, tmp, n);
//        for(int i = 0; i < n;i++){
//            tmp.clear();
//            if(!vis[i]){
//                tmp.push_back(i);
//                DFS(i,tmp, n);
//            }
//        }
        cout<<(int)tmp.size()<<endl;
    }
    return 0;
}
