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

struct point{           //点结构
    double x,y;
};
double Distance(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){          //按y升排序辅助函数
    return a.y<b.y;
}
bool cmp2(point a,point b){          //按x升排序辅助函数
    return a.x<b.x;
}
double MIN = MAX;
double closestPoint(vector<point> s,int low, int high, vector<vector<point>> &res){
    double d1,d2,d3,d;
    int mid,i,j,index;
    double x1,y1,x2,y2;         //记录点对的位置
    point P[high-low+1],temp1[2],temp2[2],temp3[2];         //辅助空间

    point rec[2];
    vector<point> couple;
    if(high<=low)
        return MAX;
    if(high-low==1){             //两个点的情况
        rec[0].x=s[low].x;rec[0].y=s[low].y;
        rec[1].x=s[high].x;rec[1].y=s[high].y;
        couple.push_back(rec[0]);
        couple.push_back(rec[1]);
        if(Distance(rec[0], rec[1])<MIN){
            MIN = Distance(rec[0], rec[1]);
            res.clear();
            res.push_back(couple);
        }
        else if(Distance(rec[0], rec[1]) == MIN){
            res.push_back(couple);
        }
        couple.clear();
        return MIN;
    }

    mid=(low+high)/2;       //其他情况递归
    d1=closestPoint(s,low,mid,res);
    d2=closestPoint(s,mid+1,high,res);
    if(d1<d2){
        d=d1;
        rec[0]=temp1[0];
        rec[1]=temp1[1];
    }
    else {
        d=d2;
        rec[0]=temp2[0];
        rec[1]=temp2[1];
    }
    index=0;
    for(i=mid;(i>=low)&&((s[mid].x-s[i].x)<d);i--)      //点集合p1
        P[index++]=s[i];
    for(i=mid+1;(i<=high)&&((s[i].x-s[mid].x)<d);i++)      //点集合p2
        P[index++]=s[i];
    sort(P,P+index,cmp);                    //升序排列
    for(i=0;i<index;i++){
        for(j=j+1;j<index;i++){
            if((P[j].y-P[i].y)>=d)
                break;
            else {
                d3=Distance(P[i],P[j]);
                if(d3<d){
                    rec[0].x=P[i].x;rec[0].y=P[i].y;
                    rec[1].x=P[j].x;rec[1].y=P[j].y;
                    d=d3;
                }
            }
        }
    }
    return d;
}
int main(){

    int T;
    cin>>T;
    vector<point> S;
    while(T--){
       S.clear();
       point tmp;
       char c;
       int x,y;
       while(cin>>tmp.x>>tmp.y){
            S.push_back(tmp);
            if((c=getchar())=='\n')
                break;
       }
       sort(S.begin(),S.end(),cmp2);
       vector<vector<point>> res;
       closestPoint(S, 0, S.size()-1, res);
       cout<<"最小距离为：\n"<<minDist<<"\n";
       for(auto pp: res){
            cout<<pp.x<<" "<<pp.y<<",";
       }
    }
    return 0;
}
