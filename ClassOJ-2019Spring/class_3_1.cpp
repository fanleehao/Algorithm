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

//数字重组整除问题，找到最大的那个
//https://practice.geeksforgeeks.org/viewSol.php?subId=10753062&pid=1517&user=code123p
int cmp1(int a,int b)
{
    return b < a;
}

int main(){
    int N;
    scanf("%d", &N);
    string key;
    while(N--){
        cin>>key;
        int len = key.length();
        sort(key.begin(), key.end(), greater<char>());
        //cout<<"key:"<<key<<endl;

        LL temp = 0;
        for(int i = 0; i < len; i++){
            temp = temp * 10 + (key[i] - '0');
        }
        if(temp % 17 == 0){
            cout<<temp<<endl;
            continue;
        }
        int flag = 0;
        while ( prev_permutation(key.begin() ,key.end()) )
        {
            temp = 0;
            for(int i = 0; i < len; i++){
                temp = temp * 10 + (key[i] - '0');
            }
            //cout<<"temp: "<<temp<<endl;
            if(temp % 17 == 0){
                printf("%d\n", temp);
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("Not Possible\n");
        }
    }
    return 0;
}

//解法1
//int main(){
//	int  N;
//	scanf("%d", &N);
//	while(N--){
//	    string str;
//	    cin>>str;
//	    sort(str.begin(),str.end(),greater<char>());
//	    if(stoi(str) % 17==0){
//	        cout<<stoi(str)<<endl;
//	        continue;
//	    }
//	    int flag=1;
//	    while(prev_permutation(str.begin(),str.end())){
//	        if(stoi(str)%17==0){
//	            cout<<stoi(str)<<endl;
//	            flag=0;
//	            break;
//	        }
//	    }
//	    if(flag)
//	    cout<<"Not Possible"<<endl;
//	}
//	return 0;
//}








