//7.11
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:
	bool check(vector<int> nums){
		vector<int> ns({1,2,3,4,5,6,7,8,9});
		queue<vector<int>> q;
		q.push(nums);
		while(!q.empty()){
			auto tmp=q.front();
			for(int i:tmp){
				cout<<i<<":";
			}
			cout<<endl;
			q.pop();
			if(tmp.size()==2&&tmp[0]==tmp[1])
				return true;
			for(int i:ns){
				if(count(tmp.begin(),tmp.end(),i)>=3){
					vector<int> next=tmp;
					myDel(next,i);
					myDel(next,i);
					myDel(next,i);
					q.push(next);
				}
				if(count(tmp.begin(),tmp.end(),i)>=1&&count(tmp.begin(),tmp.end(),i+1)>=1&&count(tmp.begin(),tmp.end(),i+2)>=1){
					vector<int> next=tmp;
					myDel(next,i);
					myDel(next,i+1);
					myDel(next,i+2);
					q.push(next);
				}
			}
		}
		return false;
	}
	void myDel(vector<int> &v,int i){
		auto it=v.begin();
		while(it!=v.end()){
			if(*it==i){
				v.erase(it);
				return;
			}
			it++;
		}
	}
};
int main(){
	Solution s;
	cout<<s.check({1,1,1,2,2,2,3,3,3,4,4,5,5,5})<<endl;
}