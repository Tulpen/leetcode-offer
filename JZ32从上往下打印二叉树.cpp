// 牛客网二刷
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 树的按层打印
        // 二叉树的广度优先搜索 BFS
        vector<int> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode* > node;
        node.push(root);
        while(!node.empty()){
            int n = node.size();
            for(int i = 0; i < n; i++){
                TreeNode* key = node.front();
                node.pop();
                
                ans.push_back(key->val);
                if(key->left != nullptr) node.push(key->left);
                if(key->right != nullptr) node.push(key->right);
            }
        }
        return ans;
    }
};