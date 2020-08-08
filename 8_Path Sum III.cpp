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
class Solution {
public:
    unordered_map<int,int>mp;
    int count,target;
    void help(TreeNode * root,int s){
        if(!root){
            return;
        }
        s=s+root->val;
        count=count+mp[s-target];
        mp[s]++;
        help(root->left,s);
        help(root->right,s);
        mp[s]--;
    }
    int pathSum(TreeNode* root, int sum) {
        count=0;
        target=sum;
        mp[0]=1;
        int s=0;
        help(root,s);
        return count;
    }
};
