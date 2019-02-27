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
#include<stack>
#include<iomanip>
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff�����ÿһ�����ÿո������0��1
#define MAX 101000
using namespace std;
vector<vector<int> > vec;

int getMaxRect(vector<int> h){
    stack<int> s;
    int i = 1, maxHeight = h[0];
    //����ջ
    s.push(0);    //����һ��Ԫ��ѹ��ջ
    while(i < h.size() || (i == h.size() && !s.empty())){
        //������Ԫ�ض������꣬�����һ����ջ��Ϊ��ʱ-------������һ��ֵ����С�ģ��ͼ�����ջ����
        if(i != h.size() && (s.empty() || h[i] >= h[s.top()])){
            s.push(i);
            i++;
        }
        else{
            int top = h[s.top()];  //���������ջ
            s.pop();
            int curr = !s.empty() ? top * (i - s.top() - 1): top * i;
            maxHeight = max(curr, maxHeight);
        }
    }
    return maxHeight;
}

int main(){

    vector<int> temp;
    string line;
    int k = 0;
    while(getline(cin, line)){
        stringstream ss;
        ss<<line;
        int i =0;
        while(ss >> i){
            temp.push_back(i);
        }
        vec.push_back(temp);
        temp.clear();
        k++;
    }
    int rows = vec.size();
    int cols = vec[0].size();
//    cout<<"------"<<k<<endl;
//    cout<<vec.size()<<endl;
//
//    for(int i = 0 ; i < vec.size(); i++){
//        for(int j = 0; j < vec[i].size(); j++)
//            cout<<vec[i][j]<<" ";
//        cout<<endl;
//    }
    int res = 0;
    for(int i = 1; i <rows; i++){
        for(int j = 0; j < cols; j++){
            //������ÿ��Ϊ�׵�ֱ��ͼ����
            if(vec[i][j] == 0)
                continue;
            else
                vec[i][j] += vec[i - 1][j];
        }
        res = max(res, getMaxRect(vec[i]));

    }
    printf("%d\n",res);
    return 0;

}
