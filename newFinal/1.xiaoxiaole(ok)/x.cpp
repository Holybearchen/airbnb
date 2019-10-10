#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class solution{
public:
	string origin;
	int minLen;//最小长度
	int minStep;//最短步数
	unordered_map<string,bool> vis;
	solution(string s){
		origin=s;
		minLen=s.size();
		minStep=0;
	}
	int getsolution(){
		int step=0;
		origin=delString(origin);
		dfs(origin,step);
		cout<<"minLen:"<<minLen<<endl;
		cout<<"minStep:"<<minStep<<endl;
		return minLen;
	}
	bool canBeDel(string s){
		int l=s.size();
		if(l<3) return false;
		for(int i=0;i<l-2;i++){
			if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
				return true;
			}
		}
		return false;
	}
	string delString(string s){
		if(!canBeDel(s))
			return s;
		int l=s.size();
		for(int i=0;i<l-2;i++){
			if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
				char c=s[i];
				int j=i+2;
				while(s[j]==c){
					j++;//j到达第一个不连续相等的地方
				}
				if(j>=l){

					return delString(s.substr(0,i));
				}
				return delString(s.substr(0,i)+s.substr(j));
			}
		}
		return s;
	}
	void dfs(string s,int step){
		cout<<s<<endl;
		//更新答案
		if(s.size()<minLen){
			origin=s;
			minLen=s.size();
			minStep=step;
			
		}
		if((s.size()>=minLen&&step>minStep)||s.size()<3||vis[s]){//剪
			return;
		}
		//下一步
		vis[s]=true;
		vector<string> next;
		for(int i=0;i<s.size()-1;i++){
			swap(s[i],s[i+1]);
			if(canBeDel(s)){
				next.push_back(delString(s));
			}
			swap(s[i],s[i+1]);
		}
		for(string nextStr:next){
			dfs(nextStr,step+1);
		}
		
	}

};

int main(){
	solution s("aabbabacaabbcbb");
	//cout<<"aabbabacaabbcbb"<<endl;
	cout<<s.getsolution();
	return 0;
}