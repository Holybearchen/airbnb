#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
public:
	int id;
	int distance;
	vector<int> path;
	Node(int i,int d,vector<int> p){
		id=i;
		distance=d;
		path=p;
	}
};
bool operator<(Node a,Node b){
	return a.distance>b.distance;
}
class solution{
public:
	int getKthPath(vector<vector<int>> board,int start,int target,int K){
		int m=board.size();
		int n=board[0].size();
		int count=0;
		priority_queue<Node> q;
		vector<int> sp({start});
		q.push(Node(start,0,sp));
		while(!q.empty()){
			auto curNode=q.top();
			int curId=curNode.id;
			int curDis=curNode.distance;
			auto curPath=curNode.path;
			q.pop();
			if(curId==target){
				count++;
				if(count==K){
					cout<<endl;
					return curDis;
				}
			}
			for(int i=0;i<n;i++){
				if(board[curId][i]>0){
					int newId=i;
					int newDis=curDis+board[curId][i];
					vector<int> newPath=curPath;
					newPath.push_back(newId);
					q.push(Node(newId,newDis,newPath));
				}
			}
		}
		cout<<"no this path"<<endl;
		return 0;
	}
};

int main(){
	vector<vector<int>> board({
		{0,3,0,2,0,0},
		{0,0,0,0,0,0},
		{0,0,0,2,2,1},
		{0,1,2,0,3,0},
		{0,0,0,0,0,2},
		{0,0,0,0,0,0}
	});
	solution s;
	for(int i=1;i<=5;i++){
		cout<<s.getKthPath(board,0,5,i)<<endl;
	}
	return 0;
}