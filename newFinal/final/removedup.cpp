//10.43-11.15
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
public:
	string removeDup(string s){
		string res="";
		unordered_map<char,int> m;
		unordered_map<char,bool> exi;
		for(char c:s){
			m[c]++;
		}
		for(int i=0;i<s.size();i++){
			if(exi[s[i]]){
				m[s[i]]--;
				continue;
			}
			m[s[i]]--;
			while(!res.empty()&&m[res.back()]>0&&s[i]<res.back()){
				exi[res.back()]=false;

				res.pop_back();
			}
			res.push_back(s[i]);
			exi[s[i]]=true;
		}
		return res;
	}
};

int main(){
	Solution s;
	string str="sdafass";
	string res=s.removeDup(str);
	cout<<res<<endl;
}