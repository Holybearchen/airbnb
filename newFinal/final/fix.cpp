//4.07
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution{
public:
	void getSolution(vector<vector<int>> lands){
		map<pair<int,int>,bool> island;
		map<pair<int,int>,pair<int,int>> pre;
		vector<vector<int>> dirs({{1,0},{-1,0},{0,1},{0,-1}});
		int L=0;
		int V=0;
		int N=0;
		for(auto p:lands){
			int x=p[0];
			int y=p[1];
			V++;//面积+1
			L+=4;
			island[{x,y}]=true;
			int neiLandNum=0;
			int num=0;
			pre[make_pair(x,y)]={x,y};
			for(auto dir:dirs){
				if(island[make_pair(x+dir[0],y+dir[1])]){
					L-=2;
					pair<int,int> leader=u_find({x+dir[0],y+dir[1]},pre);
					if(leader!=make_pair(x,y)){
						cout<<x+dir[0]<<":"<<y+dir[1]<<"->"<<leader.first<<":"<<leader.second<<endl;
						neiLandNum++;
						pre[leader]=make_pair(x,y);
						num++;
					}
				}
			}
			N-=neiLandNum;
			N++;
			cout<<num<<endl;
			cout<<"len:"<<L<<endl;
			cout<<"V:"<<V<<endl;
			cout<<"Number:"<<N<<endl;
			cout<<"_________________________________________________________"<<endl;
		}
	}
	pair<int,int> u_find(pair<int,int> xy,map<pair<int,int>,pair<int,int>> &pre){
		if(pre[xy]==xy){
			return xy;
		}
		pre[xy]=u_find(pre[xy],pre);
		return pre[xy];
	}
};

int main(){
	int n;
	cin>>n;
	vector<vector<int>> lands;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x;
		cin>>y;
		lands.push_back({x,y});
	}
	Solution s;
	s.getSolution(lands);
}