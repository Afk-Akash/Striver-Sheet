class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> a(26),b(26);
        for(auto & ak : word1) a[ak - 'a']++;
        for(auto & ak : word2)b[ak - 'a']++;
        unordered_multiset<int>s1,s2;
        
        for(int i = 0; i <= 25; i++){
            // cout<<a[i]<<" "<<b[i]<<endl;
            if(a[i] && b[i]){
                s1.insert(a[i]);
                s2.insert(b[i]);
            }
            else if(a[i] or b[i]) return false;
        }
        return s1 == s2;
    }
};