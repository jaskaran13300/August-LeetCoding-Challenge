class Solution {
public:
    int titleToNumber(string s) {
        long long  result=0;
        for(char c:s){
            result=result*26;
            result=result+c-'A'+1;
        }
        return result;
    }
};
