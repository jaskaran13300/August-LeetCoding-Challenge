class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstbuy=INT_MIN;
        int firstsell=0;
        int secondbuy=INT_MIN;
        int secondsell=0;
        for(int i=0;i<prices.size();i++)
        {
            firstbuy=max(firstbuy,-prices[i]);//loss
            firstsell=max(firstsell,firstbuy+prices[i]);//gain 
            secondbuy=max(secondbuy,firstsell-prices[i]);//loss
            secondsell=max(secondsell,secondbuy+prices[i]);//gain
        }
        return secondsell;
    }
};
