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
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int p[N][2];
        int res = 0;
        for(int i = 0; i < N; i++){
            scanf("%d%d",&p[i][0], &p[i][1]);
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                int Md = abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]);
                int Ed = (p[i][0]-p[j][0])*(p[i][0]-p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                //cout<<"md:"<<Md<<endl;
                //cout<<"ed:"<<Ed<<endl;
                if(Md * Md == Ed){
                    res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}


















