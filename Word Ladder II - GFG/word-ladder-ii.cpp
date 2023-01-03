//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    vector<vector<string>> findSequences(string beg, string end, vector<string>& w) {
        unordered_set<string> list(w.begin(), w.end());
        if(list.find(end) == list.end()) return {};
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beg});
        int wordSize = beg.size();
        list.erase(beg);
        bool flag = true;
        while(q.size() and flag){
            int sz = q.size();
            unordered_set<string> temp;
            while(sz--){
                auto top = q.front();
                q.pop();
                auto curr = top.back();
                for(int i = 0; i < wordSize; i++){
                    auto currWord = curr;
                    for(char a = 'a'; a <= 'z'; a++){
                        currWord[i] = a;
                        if(currWord == end){
                            top.push_back(end);
                            ans.push_back(top);
                            flag = false;
                        }
                        if(list.find(currWord) != list.end()){
                            top.push_back(currWord);
                            q.push(top);
                            // cout<<top.size()<<" ";
                            temp.insert(currWord);
                            top.pop_back();
                        }
                    }
                }
            }
            for(auto & a : temp)list.erase(a);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends