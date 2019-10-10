//3.47
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	void findB(vector<vector<int>> board,int x,int y){
		findUp(board, x, y);
		findDown(board, x, y);
		findLeft(board, x, y);
		findRight(board, x, y);
	}
	void findUp(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		int b1=0;//外边界
		int b2=x;//内边界
		while(b1<b2){
			int mid=(b1+b2)/2;
			bool mHasnum=false;
			for(int i=0;i<n;i++){
				if(board[mid][i]==num)
					mHasnum=true;
			}
			if(!mHasnum){//向内
				b1=mid+1;
			}
			else{
				if(mid==0){
					cout<<"0"<<endl;
					return;
				}
				bool isBorder=true;
				for(int i=0;i<n;i++){
					if(board[mid-1][i]==num)
						isBorder=false;
				}
				if(!isBorder){
					//向外
					b2=mid-1;
				}
				else{
					cout<<"up:"<<mid<<endl;
					return;
				}
			}
		}
		cout<<"up:"<<b1<<endl;
	}
	void findDown(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		int b1=m-1;//外边界
		int b2=x;//内边界
		while(b2<b1){
			int mid=(b1+b2)/2;
			bool mHasnum=false;
			for(int i=0;i<n;i++){
				if(board[mid][i]==num)
					mHasnum=true;
			}
			if(!mHasnum){//向内
				b1=mid+1;
			}
			else{
				if(mid==n-1){
					cout<<"down:"<<n-1<<endl;
					return;
				}
				bool isBorder=true;
				for(int i=0;i<n;i++){
					if(board[mid+1][i]==num)//向外一行
						isBorder=false;
				}
				if(!isBorder){
					//向外
					b2=mid+1;
				}
				else{
					cout<<"down:"<<mid<<endl;
					return;
				}
			}
		}
		cout<<"down:"<<b1<<endl;
	}
	void findLeft(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		int b1=0;//外边界
		int b2=y;//内边界
		while(b1<b2){
			int mid=(b1+b2)/2;
			bool mHasnum=false;
			for(int i=0;i<m;i++){
				if(board[i][mid]==num)
					mHasnum=true;
			}
			if(!mHasnum){//向内
				b1=mid+1;
			}
			else{
				if(mid==0){
					cout<<"Left:"<<"0"<<endl;
					return;
				}
				bool isBorder=true;
				for(int i=0;i<m;i++){
					if(board[i][mid-1]==num)
						isBorder=false;
				}
				if(!isBorder){
					//向外
					b2=mid-1;
				}
				else{
					cout<<"Left:"<<mid<<endl;
					return;
				}
			}
		}
		cout<<"Left:"<<b1<<endl;
	}
	void findRight(vector<vector<int>> board,int x,int y){
		int m=board.size();
		int n=board[0].size();
		int num=board[x][y];
		int b1=n-1;//外边界
		int b2=y;//内边界
		while(b1>b2){
			int mid=(b1+b2)/2;
			bool mHasnum=false;
			for(int i=0;i<m;i++){
				if(board[i][mid]==num)
					mHasnum=true;
			}
			if(!mHasnum){//向内
				b1=mid-1;
			}
			else{
				if(mid==n-1){
					cout<<"Right:"<<n-1<<endl;
					return;
				}
				bool isBorder=true;
				for(int i=0;i<m;i++){
					if(board[i][mid+1]==num)
						isBorder=false;
				}
				if(!isBorder){
					//向外
					b2=mid+1;
				}
				else{
					cout<<"Right:"<<mid<<endl;
					return;
				}
			}
		}
		cout<<"Right:"<<b1<<endl;
	}
};
int main(){
	Solution s;
	vector<vector<int>> board({
		{2,2,1,2,2,2,2,2,2},
		{2,2,1,2,2,2,2,2,2},
		{2,2,1,2,2,2,2,2,2},
		{1,1,1,1,1,2,2,2,2},
		{2,2,2,2,1,2,2,2,2},
		{2,2,2,2,1,2,2,2,2},
		{2,2,2,2,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,1}
	});
	s.findB(board,7,8);
	return 0;
}