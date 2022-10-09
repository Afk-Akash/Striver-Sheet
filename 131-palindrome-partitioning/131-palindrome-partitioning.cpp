class Solution {
public:
    bool isPalindrome(string &str, int i, int j){
        while(i < j ) if(str[i++] != str[j--])return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        fun(0, s, ans, temp);
        return ans;
    }
    
    void fun(int ind, string &s, vector<vector<string>> &ans, vector<string>&temp){
        if(ind == s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                fun(i+1, s, ans, temp);
                temp.pop_back();
            }
        }
        
    }
};