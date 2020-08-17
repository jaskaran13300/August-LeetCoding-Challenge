class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int candy=1,index=0;
        while(candies>0){
            ans[index++%(num_people)]+=min(candy,candies);
            candies=candies-candy;
            candy++;
        }
        return ans;
    }
};
