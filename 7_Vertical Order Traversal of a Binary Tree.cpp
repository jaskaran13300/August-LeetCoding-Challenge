/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// firstly same level then print acc to y and if y is same print according to small value


void fill_map(TreeNode* root,map<int,vector<pair<int,int>>> &mp,int x,int y){
    if(!root){
        return;
    }
    mp[x].push_back({y,root->val});
    fill_map(root->left,mp,x-1,y+1);
    fill_map(root->right,mp,x+1,y+1);
    
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        int hd=0;
        vector<vector<int>>ans;
        fill_map(root,mp,hd,hd);
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            vector<int>temp;
            sort(itr->second.begin(),itr->second.end());
            for(auto num : itr->second){
                temp.push_back(num.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
