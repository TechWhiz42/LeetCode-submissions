/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* root, string& s){
        if(!root) return;

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* build(vector<int>& pre, int& idx, long long low, long long high){
        if(idx == pre.size())
            return nullptr;

        int val = pre[idx];

        if(val <=low || val >= high)
            return nullptr;

        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = build(pre, idx, low, val);
        root->right = build(pre, idx, val, high);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;

        vector<int> pre;
        stringstream ss(data);
        string token;

        while(getline(ss, token, ',')){
            if(!token.empty())
                pre.push_back(stoi(token));
        }
        int idx = 0 ;

        return build(pre, idx, LLONG_MIN, LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
