/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            // 剑指offer 32 -II
            // BFS
            vector<vector<int> > ans;
            if(pRoot == nullptr) return ans;
            
            queue<TreeNode* > qnode;
            qnode.push(pRoot);
            
            while(!qnode.empty()){
                vector<int> temp;
                int n = qnode.size();
                for(int i = 0; i < n; ++i){
                    TreeNode* key = qnode.front();
                    qnode.pop();
                    temp.push_back(key->val);
                    if(key->left != nullptr) qnode.push(key->left);
                    if(key->right != nullptr) qnode.push(key->right);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};