//10.25-10.38
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<string> getTri(int N){
		if(N==1){
			return {" /\\ " ,
					"/__\\"};
		}
		vector<string> last=getTri(N-1);
		int m=last.size();
		int n=last[0].size();
		vector<string> res(2*m,string(2*n,' '));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				char c=last[i][j];
				res[i][j+n/2]=c;
				res[i+m][j]=c;
				res[i+m][j+n]=c;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<string> res=s.getTri(6);
	for(string s:res){
		cout<<s<<endl;
	}
	return 0;
}