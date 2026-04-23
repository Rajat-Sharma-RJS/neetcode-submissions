class Solution {
public:
    bool iscap(char x) {
        int v = (int)(x);
        if(v >= (int)('A') && v <= (int)('Z')) return true;
        return false;
    }
    bool isdigit(char x) {
        int v = (int)(x);
        if(v >= (int)('0') && v <= (int)('9')) return true;
        return false;
    }
    bool islow(char x) {
        int v = (int)(x);
        if(v >= (int)('a') && v <= (int)('z')) return true;
        return false;
    }
    bool isalphanum(char x) {
        if(iscap(x) || islow(x) || isdigit(x)) return true;
        return false;
    }
    bool isequal(char x, char y) {
        if(isdigit(x) && isdigit(y)) return (x == y);
        if(iscap(x) && iscap(y)) return (x == y);
        if(islow(x) && islow(y)) return (x == y);
        if(iscap(x) && islow(y)) return ((x - 'A') == (y - 'a'));
        if(iscap(y) && islow(x)) return ((y - 'A') == (x - 'a'));
        return false;
    }
    bool isPalindrome(string s) {
        string str;
        for(int i=0; i<s.length(); i++) {
            if(isalphanum(s[i])) str.push_back(s[i]);
        }
        cout << str << " \n";
        int n = str.length();
        for(int i=0; i<n/2; i++) {
            if(!isequal(str[i],str[n-i-1])) return false;
        }
        return true;
    }
};
