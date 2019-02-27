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
//���̸�������
int Pan[1024][1024];
int T=1;
//�����̵���㣨Prow,Pcol��
//��СΪSize=2^n;
//�������(x,y)
void chessPan(int Prow, int Pcol, int x, int y, int Size)
{
    if(Size==1) //�ݹ����
        return;
    int t = T++;    //ÿһ���������������ǡ�L��
    int s = Size / 2;    //�����м���С��к�(��ȵ�)
    //������ⷽ���Ƿ������Ͻ���������
    if ( x<Prow+s && y<Pcol+s )              //��
        chessPan( Prow, Pcol, x, y, s);
    else         //���ڣ��������������½ǵķ�����Ϊ���ⷽ��
    {
        Pan[Prow+s-1][Pcol+s-1]=t;
        chessPan( Prow, Pcol, Prow+s-1, Pcol+s-1, s );
    }
    //������ⷽ���Ƿ������Ͻ���������
    if ( x<Prow+s && y>=Pcol+s )               //��
        chessPan(Prow, Pcol+s, x, y, s );
    else          //���ڣ��������������½ǵķ�����Ϊ���ⷽ��
    {
        Pan[Prow+s-1][Pcol+s]=t;
        chessPan( Prow, Pcol+s, Prow+s-1, Pcol+s, s );
    }
    //������ⷽ���Ƿ������½���������
    if ( x>=Prow+s && y<Pcol+s )              //��
        chessPan( Prow+s, Pcol, x, y, s );
    else            //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��
    {
        Pan[Prow+s][Pcol+s-1]=t;
        chessPan( Prow+s, Pcol, Prow+s, Pcol+s-1, s );
    }
    //������ⷽ���Ƿ������½���������
    if ( x>=Prow+s && y>=Pcol+s )                //��
        chessPan( Prow+s, Pcol+s, x, y, s );
    else         //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��
    {
        Pan[Prow+s][Pcol+s]=t;
        chessPan( Prow+s, Pcol+s, Prow+s, Pcol+s, s );
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        int x,y;
        cin>>n>>x>>y;
        int fx, fy;
        cin>>fx>>fy;
        int Size = pow(2,n);
        chessPan(0,0,x,y,Size);
        int res[2][2];
        int k = 2;
        if(fx-1>=0 && fy-1>=0 && Pan[fx-1][fy-1]==Pan[fx][fy]){
            cout<<fx-1<<" "<<fy-1<<",";
            k--;
        }
        if(fx-1>=0 && Pan[fx-1][fy]==Pan[fx][fy]){
            cout<<fx-1<<" "<<fy;
            k--;
            if(k>0)
                cout<<",";
        }
        if(fx-1>=0 && fy+1<Size && Pan[fx-1][fy+1]==Pan[fx][fy]){
            cout<<fx-1<<" "<<fy+1;
            k--;
            if(k>0)
                cout<<",";
        }
        if(fy-1>=0 && Pan[fx][fy-1]==Pan[fx][fy]){
            cout<<fx<<" "<<fy-1;
            k--;
            if(k>0)
                cout<<",";
        }

        if(fy+1<Size && Pan[fx][fy+1]==Pan[fx][fy]){
            cout<<fx<<" "<<fy+1;
            k--;
            if(k>0)
                cout<<",";
        }

        if(fx+1<Size && fy-1>=0 && Pan[fx+1][fy-1]==Pan[fx][fy]){
            cout<<fx+1<<" "<<fy-1;
            k--;
            if(k>0)
                cout<<",";
        }

        if(fx+1<Size && Pan[fx+1][fy]==Pan[fx][fy]){
            cout<<fx+1<<" "<<fy;
            k--;
            if(k>0)
                cout<<",";
        }
        if(fx+1<Size && fy+1<Size && Pan[fx+1][fy+1]==Pan[fx][fy]){
            cout<<fx+1<<" "<<fy+1;
            k--;
            if(k>0)
                cout<<",";
        }
        cout<<endl;
    }
    return 0;
}
