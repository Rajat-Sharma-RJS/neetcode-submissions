class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int hash[26] = {0};
        for(int i=0; i<s.length(); i++) {
            int x = (int)(s[i]) - (int)('a');
            hash[x]++;
        }
        for(int i=0; i<t.length(); i++) {
            int x = (int)(t[i]) - (int)('a');
            if(hash[x] == 0) return false;
            hash[x]--;
        }
        return true;
    }
};
