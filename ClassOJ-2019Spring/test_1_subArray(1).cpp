#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<queue>
#include<deque>
#include<iomanip>
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff�����ÿһ�����ÿո������0��1
#define MAX 101000
using namespace std;

int getSum(vector<int> vec, int len, int num){
    int res = 0;
    deque<int> qmax;
    deque<int> qmin;

    int i = 0;
    int j = 0;
    while(i < len){
        while(j < len){
            //�������������ǰֵ�ϴ���Ž���β
//            cout<<"*****:"<<vec[j]<<endl;
            while(!qmax.empty() &&  vec[j] >= vec[qmax.back()]){
                qmax.pop_back();
            }
            qmax.push_back(j);    //�����ж��ֵ,�ҴӴ�С�����ֵһ�£����������ֵ��±�
            //���������Сֵ
            while (!qmin.empty() && vec[j] <= vec[qmin.back()])
			{
				qmin.pop_back();
			}
			qmin.push_back(j);
            if(vec[qmax.front()] - vec[qmin.front()] > num){
                break;  //������������
            }
            j++;

        }
        //cout<<"i--j:"<<i<<":"<<j<<endl;
        res += j - i;   //��iΪ����������ĸ���
        //�ж϶����е�Ԫ��
        if(qmax.front() == i)
            qmax.pop_front();
        if(qmin.front() == i)
            qmin.pop_front();
        i++;
    }

    return res;
}

int main(){
    string line;
    stringstream ss;
    getline(cin, line);

    ss<<line;
    vector<int> vec;
    int i =0;
    while(ss>>i){vec.push_back(i);}     //ͨ��stringtream��vector
    int vec_size = vec.size();


    int n;
    scanf("%d", &n);
    //�����Ӽ��ĸ���
    int res;
    res = vec_size * (vec_size + 1) / 2;
    res = res - getSum(vec, vec_size, n);
    printf("%d\n", res);
    deque<int> q;
//    q.push_back(10);
//    q.push_back(20);
//    q.push_back(30);
//    cout<<q.front()<<endl;
    //cout<<!q.empty()<<endl;
}
