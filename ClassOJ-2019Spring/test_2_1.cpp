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
#include<set>
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 1010
using namespace std;
int index[MAX][MAX];      //�켣
char s1[MAX];
char s2[MAX];
set<string> res_sets;

//�����������    https://www.cnblogs.com/hapjin/p/5572483.html
//�ο���https://blog.csdn.net/tham_/article/details/48718587
//��̬�滮
//c[i,j]��ʾ��(x1,x2....xi) �� (y1,y2...yj) ������������еĳ��ȡ�
string ReverseStr(string res){
    int len = res.length();
    string str;
    for(int i = len - 1; i >= 0; i--)
        str.push_back(res[i]);
    return str;
}


void printLCS(int i, int j, string res){
    if(i == 0 || j == 0){
        //cout<<ReverseStr(res)<<endl;
        res_sets.insert(ReverseStr(res));
        return;
    }

    if(index[i][j]==0){
        res.push_back(s1[i-1]);
        printLCS(i - 1, j - 1, res);
    }
    else if(index[i][j]==1)
        printLCS(i - 1, j, res);      //����
    else if(index[i][j]==2)
        printLCS(i, j - 1, res);      //����
    else if(index[i][j]==3){
        printLCS(i, j - 1, res);      //����϶�����
        printLCS(i - 1, j, res);
        return;
    }
}

void LCS(){
    int x = strlen(s1);
    int y = strlen(s2);
    //cout<<x<<" "<<y<<endl;
    int dp[x + 1][y + 1];

    for(int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= y; i++)
        dp[0][i] = 0;
    //���
    //debug;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            //cout<<s1[i-1]<<" "<<s2[j-1]<<endl;
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                index[i][j] = 0;      //����
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                index[i][j] = 1;      //������
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                dp[i][j] = dp[i][j-1];
                index[i][j] = 2;        //������
            }
            else{
                dp[i][j] = dp[i][j-1]; //����Ͼ���
                index[i][j] = 3;
            }
        }
    }
    //��ӡ
    //debug;
    string res;
    printLCS(x, y, res);
}

int main(){

    cin>>s1;
    cin>>s2;
    LCS();
    set<string>::iterator ite = res_sets.begin();
    for(; ite != res_sets.end(); ite++){
        cout<<*ite<<endl;
    }
    return 0;
}
