//5.19
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	bool check(vector<vector<int>> board){
		int m=board.size();
		int n=board[0].size();
		int num1=0;
		int num2=0;
		int winner=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==1){
					num1++;
				}
				if(board[i][j]==2){
					num2++;
				}
			}
		}
		if(num1==num2){
			winner=2;
		}else if(num1==num2+1){
			winner=1;
		}else{
			return false;
		}
		vector<int> cross;
		bool hasWinner=false;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				int num=board[i][j];
				if(num==winner){
					if(checkU(board,i,j)){
						vector<int> tmp=getU(board,i,j);
						if(!hasWinner){
							cross=tmp;
							hasWinner=true;
						}
						else{
							vector<int> v(5);
							sort(cross.begin(),cross.end());
							sort(tmp.begin(),tmp.end());
							auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),v.begin());
							v.resize(it-v.begin());
							if(v.empty()){
								return false;
							}
						}
					}
				}else if(num==0){

				}else{
					if(checkU(board,i,j))
						return false;
				}
			}
		}
		return true;
	}
	bool checkU(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		if(x<4){
			return false;
		}
		int num=board[x][y];
		for(int i=0;i<5;i++){
			if(board[x-i][y]!=num)
				return false;
		}
		return true;

	}
	vector<int> getU(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		vector<int> res;
		for(int i=0;i<5;i++){
			res.push_back(x-i*n+y);
		}
		return res;
	}
};

int main(){
	return 0;
}