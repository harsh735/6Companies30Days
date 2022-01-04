class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        int gcd = findGCD(str1.size(),str2.size());
        return str1.substr(0,gcd);
    }
    
    int findGCD(int a, int b) {
        if(b == 0) return a;
        return findGCD(b,a%b);
    }
};