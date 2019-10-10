//3.10-4.04
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<vector<int>> getSolution(int m,int n){
		vector<vector<int>> res(m,vector<int>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				res[i][j]=matAt(i,j,m,n);
				//break;
			}
			//break;
		}
		for(auto line:res){
			for(int i:line){
				cout<<i<<":";
			}
			cout<<endl;
		}
		return res;
	}
	int matAt(int x,int y,int m,int n){
		int l1=max(0,x+y+1-n);
		int l2=min(x+y+1,n);
		int l3=max(0,x+y+1-m+1);
		int minus;
		if((x+y)%2==0){
			//剪掉下面
			minus=min(m-1-x,y);
		}else{
			//剪掉上面
			minus=min(n-y-1,x);
		}
		if(x==3&&y==2){
			cout<<l1<<":"<<l2<<":"<<l3<<":"<<minus<<endl;
		}
		return l1*n+(l2-l3+1)*(l2+l3)/2-minus;
	}
};
int main(){
	Solution s;
	s.getSolution(4,5);
	s.getSolution(1,1);
	s.getSolution(2,2);
	s.getSolution(4,1);
	s.getSolution(1,5);
	s.getSolution(7,2);
	s.getSolution(2,5);
	s.getSolution(3,2);
	return 0;
}

