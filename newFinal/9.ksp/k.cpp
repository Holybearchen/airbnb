//8.58
//求从点A到点B的第k短距离
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	struct mycmp{
		bool operator()(pair<int,int> a,pair<int,int> b){
			return a.second>b.second;
		};
	};
	int ksp(int A,int B,vector<vector<int>> dis,int K){
		priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> q;
		q.push(make_pair(A,0));
		int cnt=0;
		while(!q.empty()){
			auto t=q.top();
			if(t.first==B){
				cnt++;
				if(cnt==K){
					return t.second;
				}
			}
			for(int i=0;i<dis.size();i++){
				if(dis[t.first][i]!=0){
					q.push(make_pair(i,t.second+dis[t.first][i]));
				}
			}
		}
		return -1;
	}
};
int main(){
	return 0;
}
// 0 3 0 2 0 0
// 0 0 0 0 0 0
// 0 0 0 2 2 1
// 0 1 2 0 3 0
// 0 0 0 0 0 2
// 0 0 0 0 0 0