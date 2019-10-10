//8.50
#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
	void dfs(unordered_map<int,unordered_set<int>> &G,int index,int fa,int level,bool oddChange,bool evenChange,vector<int> &origin,vector<int> &target,vector<int>& res,int &cnt){
		if((level%2==0&&(origin[index]^evenChange)!=target[index])||(level%2==1&&(origin[index]^oddChange)!=target[index])){
			res[index]=1;
			cnt++;
			if(level%2==0) evenChange=!evenChange;
			else oddChange=!oddChange;
		}
		for(int next:G[index]){
			if(next!=fa) dfs(G,next,index,level+1,oddChange,evenChange,origin,target,res,cnt);
		}
	}
	vector<int> getChange(unordered_map<int,unordered_set<int>> G,vector<int> origin,vector<int> target){
		vector<int> res(origin.size()+1);
		int cnt=0;
		dfs(G,1,-1,0,false,false,origin,target,res,cnt);
		cout<<cnt<<endl;
		for(int i=1;i<res.size();i++){
			if(res[i]==1) cout<<i<<endl;
		}
		return res;
	}
};
int main(){
	int n;cin>>n;
	unordered_map<int,unordered_set<int>> G;
	vector<int> origin,target;
	for(int i=1;i<n;i++){
		int to,from;
		cin>>to;
		cin>>from;
		G[from].insert(to);
		G[to].insert(from);
	}
	origin.push_back(0);
	target.push_back(0);
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		origin.push_back(t);
	}
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		target.push_back(t);
	}
	Solution s;
	vector<int> res=s.getChange(G,origin,target);
	return 0;
}