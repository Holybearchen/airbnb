//2.37-3.06
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
class Solution{
public:
	vector<int> getSolution(unordered_map<int,set<int>>g,vector<int> origin,vector<int> target){
		vector<int> res;
		dfs(1,1,false,false,g,res,origin,target);
		return res;
	}
	void dfs(int i,int level,bool oddChange,bool evenChange,unordered_map<int,set<int>>g,vector<int> &res,vector<int> &origin,vector<int> &target){
		//1.变化
		int num=origin[i-1];
		if((level%2==0&&evenChange)||(level%2==1&&oddChange)){
			num=(num+1)%2;
		}
		//2.比较
		if(num!=target[i-1]){
			cout<<i<<endl;
			if(level%2==0){
				num=(num+1)%2;
				evenChange=!evenChange;
			}
			else{
				num=(num+1)%2;
				oddChange=!oddChange;
			}
			res.push_back(i);
			origin[i-1]=num;
		}
		//3.下一步
		for(int next:g[i]){
			dfs(next,level+1,oddChange,evenChange,g,res,origin,target);
		}
	}
};

int main(){
	Solution s;

	int n;
	int m;
	cin>>n;
	cin>>m;
	unordered_map<int,set<int>> g;
	for(int i=0;i<n;i++){
		int to;
		int from;
		cin>>to;
		cin>>from;
		g[from].insert(to);
	}
	vector<int> origin;
	vector<int> target;
	for(int i=0;i<m;i++){
		int o;
		cin>>o;
		origin.push_back(o);
	}
	for(int i=0;i<m;i++){
		int o;
		cin>>o;
		target.push_back(o);
	}
	vector<int> res=s.getSolution(g,origin,target);
	for(int i:res){
		cout<<i<<":";
	}
	cout<<endl;
	return 0;
}