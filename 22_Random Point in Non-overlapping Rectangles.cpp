class Solution {
public:
    vector<int> v;
    vector<vector<int>> rect;
    Solution(vector<vector<int>>& rects) 
    {
        rect=rects;
        int area=0;
        for(auto rec:rect)
        {
            int a= (rec[2]- rec[0]+1)*(rec[3]-rec[1]+1);
            area+=a;
            v.push_back(area);
        }
    }
    
    vector<int> pick() 
    {
        int rnd= rand()%v.back();
        int idx= upper_bound(v.begin(),v.end(),rnd) - v.begin();
        
        auto l=rect[idx];
        int x= rand() % (l[2]-l[0]+1) + l[0];
        int y= rand() % (l[3]-l[1]+1) + l[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
