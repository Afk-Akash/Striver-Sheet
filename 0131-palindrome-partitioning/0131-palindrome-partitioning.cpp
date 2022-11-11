class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        string str;
        fun(0, s, ds, ans);
        return ans;
    }
    
    void fun(int ind, string & s,vector<string> & ds, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(ds);
            return ;
        }
        
        for(int i = ind; i < s.size(); i++){
            if(!is(s,ind, i)) continue;
            string temp = s.substr(ind, i - ind + 1);
            ds.push_back(temp);
            fun(i + 1, s, ds, ans);
            ds.pop_back();
            
        }
    }
    
    bool is(string & s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return true;
    }
};