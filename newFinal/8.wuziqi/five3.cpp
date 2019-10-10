//7.03
#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
	bool checkBoard(vector<vector<int>> board){
		int m=board.size();
		int n=board[0].size();
		int num1=0;
		int num2=0;
		int lastStep=0;
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
	cout<<num1<<":"<<num2<<endl;

		if(num1==num2){
			lastStep=2;
		
		}
		else if(num1==num2+1){
			lastStep=1;
		}
		else{
			return false;
		}
		vector<string> cross;
		bool win=false;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				
				int num=board[i][j];
				if(num==lastStep){
					if(checkU(board,i,j)){
						vector<string> tmp=getU(board,i,j);
						if(!win){
							cross=tmp;
							win=true;
						}else{
							vector<string> ivec(5);
							sort(cross.begin(),cross.end());
							sort(tmp.begin(),tmp.end());
							auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkUR(board,i,j)){
						vector<string> tmp=getUR(board,i,j);
						if(!win){
							cross=tmp;
							win=true;
						}else{
							vector<string> ivec(5);
							sort(cross.begin(),cross.end());
							sort(tmp.begin(),tmp.end());
							auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkR(board,i,j)){
						vector<string> tmp=getR(board,i,j);
						if(!win){
							cross=tmp;
							win=true;
						}else{
							vector<string> ivec(5);
							sort(cross.begin(),cross.end());
							sort(tmp.begin(),tmp.end());
							auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkRD(board,i,j)){
						vector<string> tmp=getRD(board,i,j);
						if(!win){
							cross=tmp;
							win=true;
						}else{
							vector<string> ivec(5);
							sort(cross.begin(),cross.end());
							sort(tmp.begin(),tmp.end());
							auto it=set_intersection(cross.begin(),cross.end(),tmp.begin(),tmp.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							if(cross.empty()){
								return false;
							}
						}
					}
				}else if(num==0){
					continue;
				}else{
					if(checkU(board,i,j)||checkUR(board,i,j)||checkR(board,i,j)||checkRD(board,i,j)){
						return false;
					}
				}
				
			}
		}
		return true;
	}
	bool checkU(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		if(x<4){
			return false;
		}
		for(int i=0;i<5;i++){
			if(board[x-i][y]!=num){
				return false;
			}
		}
		return true;
	}
	bool checkUR(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		if(x<4||y>n-5){
			return false;
		}
		for(int i=0;i<5;i++){
			if(board[x-i][y+i]!=num){
				return false;
			}
		}
		return true;
	}
	bool checkR(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		if(y>n-5){
			return false;
		}
		for(int i=0;i<5;i++){
			if(board[x][y+i]!=num){
				return false;
			}
		}
		return true;
	}
	bool checkRD(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		if(x>m-5||y>n-5){
			return false;
		}
		for(int i=0;i<5;i++){
			if(board[x+i][y+i]!=num){
				return false;
			}
		}
		return true;
	}
	vector<string> getU(vector<vector<int>> board,int x,int y){
		vector<string> res;
		for(int i=0;i<5;i++){
			string s=to_string(x-i)+"-"+to_string(y);
			res.push_back(s);
		}
		return res;
	}
	vector<string> getUR(vector<vector<int>> board,int x,int y){
		vector<string> res;
		for(int i=0;i<5;i++){
			string s=to_string(x-i)+"-"+to_string(y+y);
			res.push_back(s);
		}
		return res;
	}
	vector<string> getR(vector<vector<int>> board,int x,int y){
		vector<string> res;
		for(int i=0;i<5;i++){
			string s=to_string(x)+"-"+to_string(y+i);
			res.push_back(s);
		}
		return res;
	}
	vector<string> getRD(vector<vector<int>> board,int x,int y){
		vector<string> res;
		for(int i=0;i<5;i++){
			string s=to_string(x+i)+"-"+to_string(y+i);
			res.push_back(s);
		}
		return res;
	}
};

int main(){
	solution s;
	vector<vector<int>> board({
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,1,0,0},
		{0,0,0,0,1,1,2,2,0,0,0},
		{1,1,1,1,1,0,2,2,0,0,0},
		{0,0,0,1,1,0,2,2,0,0,0},
		{0,0,1,0,1,0,2,2,0,0,0},
		{0,0,0,0,1,0,0,0,2,0,0},
		{0,0,0,0,0,0,0,0,0,0,0},
	});
	cout<<s.checkBoard(board)<<endl;
	return 0;
}