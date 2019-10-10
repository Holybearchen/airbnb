//4.27
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
	vector<vector<int>> dirs;
	void fix(vector<vector<int>> input){
		vector<vector<int>> dirs({{1,0},{0,1},{-1,0},{0,-1}});
		unordered_map<string,bool> island;
		unordered_map<string,string> pre;
		int V=0,L=0,NUM=0;
		for(int i=0;i<input.size();i++){
			int x=input[i][0];
			int y=input[i][1];
			string cur=to_string(x)+"-"+to_string(y);
			int landNei=0;
			int NumNei=0;
			island[cur]=true;
			pre[cur]=cur;
			for(auto d:dirs){
				string neibor=to_string(x+d[0])+"-"+to_string(y+d[1]);
				if(island[neibor]){
					++landNei;
					if(u_find(neibor,pre)!=cur){
						pre[u_find(neibor,pre)]=cur;
						NumNei++;
					}
				}
			}
			++V;
			L-=landNei;
			L+=(4-landNei);
			NUM-=(NumNei-1);
			cout<<NUM<<":"<<V<<":"<<L<<endl;
		}

	}
	string u_find(string s,unordered_map<string,string> &pre){
		if(pre[s]==s) return s;
		pre[s]=u_find(pre[s],pre);
		return pre[s];
	}
};
int main(){
	vector<vector<int>> input;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x;cin>>y;
		input.push_back({x,y});
	}
	Solution s;
	cout<<"_____________________________"<<endl;
	s.fix(input);
	return 0;
}