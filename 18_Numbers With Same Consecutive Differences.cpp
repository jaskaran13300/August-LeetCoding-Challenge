class Solution {
public:
    vector<int>ans;
    void dfs(int n,int k,int num){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int last_digit=num%10;
        if(last_digit+k<=9){
            dfs(n-1,k,num*10+last_digit+k);
        }
        if(last_digit-k>=0 && k!=0){
            dfs(n-1,k,num*10+last_digit-k);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            ans.push_back(0);
        }
        for(int i=1;i<=9;i++){
            dfs(N-1,K,i);
        }
        return ans;
    }
};
