class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int l=0;
        int flag=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if((itr->second)%2!=0){
                l+=itr->second-1;
                flag=1;
            }
            else{
                l+=itr->second;
            }
        }
        return l+flag;
    }
};
