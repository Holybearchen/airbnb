//9.17
#include<iostream>
using namespace std;
#include<vector>

class solution{
public:
	bool cheackBoard(vector<vector<int>> board){
		int m=board.size();
		if(m<1){return false;}
		int n=board[0].size();
		if(n<1){return false;}
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
		//判断最后一步
		cout<<num1<<":"<<num2<<endl;
		if(num2==num1){
			lastStep=2;
		}else if(num1==num2+1){
			lastStep=1;
		}else{
			return false;
		}
		//判断交集
		vector<string> cross;
		bool hasWinner=false;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==lastStep){
					if(checkU(board,i,j)){
						vector<string> tmp=getU(board,i,j);
						if(!hasWinner){
							hasWinner=true;
							cross=tmp;
						}else{
							//求交集
							vector<string> ivec(5);
							sort(tmp.begin(),tmp.end());
							sort(cross.begin(),cross.end());
							auto it=set_intersection(tmp.begin(),tmp.end(),cross.begin(),cross.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							for(auto t:cross){
								cout<<t<<endl;
							}
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkRU(board,i,j)){
						vector<string> tmp=getRU(board,i,j);
						if(!hasWinner){
							hasWinner=true;
							cross=tmp;
						}else{
							//求交集
							vector<string> ivec(5);
							sort(tmp.begin(),tmp.end());
							sort(cross.begin(),cross.end());
							auto it=set_intersection(tmp.begin(),tmp.end(),cross.begin(),cross.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							for(auto t:cross){
								cout<<t<<endl;
							}
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkR(board,i,j)){
						vector<string> tmp=getR(board,i,j);
						if(!hasWinner){
							hasWinner=true;
							cross=tmp;
						}else{
							//求交集
							vector<string> ivec(5);
							sort(tmp.begin(),tmp.end());
							sort(cross.begin(),cross.end());
							auto it=set_intersection(tmp.begin(),tmp.end(),cross.begin(),cross.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							for(auto t:cross){
								cout<<t<<endl;
							}
							if(cross.empty()){
								return false;
							}
						}
					}
					if(checkRD(board,i,j)){
						vector<string> tmp=getRD(board,i,j);
						if(!hasWinner){
							hasWinner=true;
							cross=tmp;
						}else{
							//求交集
							vector<string> ivec(5);
							sort(tmp.begin(),tmp.end());
							sort(cross.begin(),cross.end());
							auto it=set_intersection(tmp.begin(),tmp.end(),cross.begin(),cross.end(),ivec.begin());
							ivec.resize(it-ivec.begin());
							cross=ivec;
							for(auto t:cross){
								cout<<t<<endl;
							}
							if(cross.empty()){
								return false;
							}
						}
					}
				}
				else if(board[i][j]==0){
					continue;
				}else{
					if(checkU(board,i,j)||checkRU(board,i,j)||checkRD(board,i,j)||checkR(board,i,j)){
						return false;
					}

				}
			}
		}
		return true;
	}
	bool checkU(vector<vector<int>> board,int x,int y){
		if(x<4){
			return false;
		}
		int num=board[x][y];
		for(int i=0;i<5;i++){
			if(board[x-i][y]!=num){
				return false;
			}
		}
		return true;
	}
	bool checkRU(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		if(x<4||y>n-5){
			return false;
		}
		int num=board[x][y];
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
		if(y>n-5){
			return false;
		}
		int num=board[x][y];
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
		if(x>m-5||y>n-5){
			return false;
		}
		int num=board[x][y];
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
	vector<string> getRU(vector<vector<int>> board,int x,int y){
		vector<string> res;
		for(int i=0;i<5;i++){
			string s=to_string(x-i)+"-"+to_string(y+i);
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
	vector<vector<int>> board({
		{0,0,0,1,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,2,0,0},
		{1,0,1,0,1,0,0,2,0,0},
		{0,1,1,1,0,0,0,0,2,0},
		{0,0,1,0,0,0,0,2,0,0},
		{0,1,1,1,0,0,0,2,0,0},
		{1,0,0,0,1,2,0,2,2,2},
		{0,0,1,0,0,2,0,0,0,2},
		{0,0,1,0,0,2,0,0,0,2},
		{0,0,1,0,0,2,0,0,2,2}
	});
	solution s;
	cout<<s.cheackBoard(board);
	return 0;
}












