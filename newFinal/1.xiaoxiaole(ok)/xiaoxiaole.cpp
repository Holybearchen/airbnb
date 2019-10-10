//2.20
//bfs
#include<iostream>
#include<queue>
using namespace std;


class Solution{
public:
	int getSolution(string s){
		queue<string> q;
		q.push(s);
		int step=0;
		int minLen=s.size();
		int res=0;
		while(!q.empty()){
			for(int i=q.size();i>0;i--){
				string tmp=q.front();
				if(tmp.size()<minLen){
					minLen=tmp.size();
					res=step;
				}
				q.pop();
				if(tmp.size()>3){
					for(int i=0;i<tmp.size()-1;i++){
						swap(tmp[i],tmp[i+1]);
						if(canDel(tmp)){
							q.push(myDel(tmp));
						}
						swap(tmp[i],tmp[i+1]);
					}
				}
			}
			step++;
		}
		return res;
	}
	bool canDel(string s){
		if(s.size()<3){
			return false;
		}
		for(int i=0;i<s.size()-2;i++){
			if(s[i]==s[i+1]&&s[i]==s[i+2]){
				return true;
			}
		}
		return false;
	}
	string myDel(string s){
		string str1="";
		string str2="";
		for(int i=0;i<s.size()-2;i++){
			if(s[i]==s[i+1]&&s[i]==s[i+2]){
				int end=i+2;
				while(end<s.size()&&s[end]==s[i]){
					end++;
				}
				if(i==0)
					str1="";
				else
					str1=s.substr(0,i);
				if(end==s.size())
					str2="";
				else 
					str2=s.substr(end);
				break;
			}
		}
		if(canDel(str1+str2)){
			return myDel(str1+str2);
		}
		return str1+str2;
	}
};
int main(){
	Solution s;
	cout<<s.getSolution("aababbcb")<<endl;
	return 0;
}