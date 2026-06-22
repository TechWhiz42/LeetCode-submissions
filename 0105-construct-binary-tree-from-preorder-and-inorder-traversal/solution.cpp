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
    unordered_map<int, int> pos;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inLeft, 
        int inRight){
            if(inLeft > inRight)
                return nullptr;

            int rootVal = preorder[preIdx++];
            TreeNode* root = new TreeNode(rootVal);

            int mid = pos[rootVal];

            root->left = build(preorder, inorder, inLeft, mid-1);
            root-> right = build(preorder, inorder, mid+1, inRight);

            return root;
        }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i< inorder.size(); i++){
            pos[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
