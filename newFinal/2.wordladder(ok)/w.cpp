#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
//8.10
//不用vis，遍历完从st中消除就行
class Solution{
public:
	int getMinPath(string start,string target,vector<string> dict){
		queue<string> q({start});
		unordered_set<string> st(dict.begin(),dict.end());
		int step=1;
		while(!q.empty()){
			for(int i=q.size();i>0;i--){
				string tmp=q.front();
				q.pop();
				if(tmp==target){return step;}
				for(int j=0;j<tmp.size();j++){
					for(int k=0;k<26;k++){
						string newWord=tmp;
						newWord[j]='a'+k;
						if(newWord!=tmp&&st.find(newWord)!=st.end()){
							st.erase(newWord);
							q.push(newWord);
						}
					}
				}
			}
			++step;
		}
		return 0;
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> todel;
        vector<string> p{beginWord};
        queue<vector<string>> q({p});
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!q.empty()) {
        	for(string d:todel) dict.erase(d);
        	todel.clear();
        	for(int l=q.size();l>0;l--){
	            vector<string> tmp=q.front();
	            q.pop();
	            string last=tmp.back();
	            if(last==endWord&&tmp.size()<=minLevel){
	                res.push_back(tmp);
	                minLevel=tmp.size();
	            }
	            if(tmp.size()>minLevel) break;
	            for(int i=0;i<last.size();i++){
	                for(char ch='a';ch<='z';ch++){
	                    string newLast=last;
	                    newLast[i]=ch;
	                    if(dict.find(newLast)!=dict.end()){
	                        vector<string> newVec=tmp;
	                        newVec.push_back(newLast);
	                        q.push(newVec);
	                        if(newLast!=endWord)
	                            todel.insert(newLast);
	                    }
	                }
	                    
	            }
	        }
            
        }
        return res;
    }
};

int main(){
	Solution s;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList({"hot","dot","dog","lot","log","cog"});
	cout<<s.getMinPath(beginWord,endWord,wordList)<<endl;
}