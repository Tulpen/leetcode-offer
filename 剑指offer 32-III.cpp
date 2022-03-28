// round 1 backup
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 使用stack 先访问右子树
        vector<vector<int>> result;
        if(!root) return result;
        stack<TreeNode*> point1;  // 奇数层
        stack<TreeNode*> point2; // 偶数层
        point2.push(root);
        int cont=0;
        while(point1.size() || point2.size()){
            int cnt1 = point1.size();
            int cnt2 = point2.size();
            vector<int> tmp;
            //cout<<cont
            if(cont%2==0){
                for(int i =0;i<cnt2;i++){
                    TreeNode* pNode = point2.top();
                    tmp.push_back(pNode->val);
                    point2.pop();
                    if(pNode->left){
                        point1.push(pNode->left);
                    }
                    if(pNode->right){
                        point1.push(pNode->right);
                    }
                }
                cont++;
            }else{
                for(int i =0;i<cnt1;i++){
                    TreeNode* pNode = point1.top();
                    tmp.push_back(pNode->val);
                    // cout<<pNode->val<<endl;
                    point1.pop();
                    if(pNode->right){
                        point2.push(pNode->right);
                    }
                    if(pNode->left){
                        point2.push(pNode->left);
                    }
                }
                cont++;
            }
           
            result.push_back(tmp);
        }
        return result;

    }
};

// round 2 3-28
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode* > qnode;
        if(root == nullptr)
            return ans;
        qnode.push(root);
        int layer = 0;
        while(!qnode.empty()){
            vector<int> temp;
            int n = qnode.size();
            // 利用栈实现奇数层的倒序
            // stack<int> reverse;
            for(int i = 0; i < n; ++i){
                TreeNode *key = qnode.front();
                qnode.pop();
                temp.push_back(key->val);
                if(key->left != nullptr) qnode.push(key->left);
                if(key->right != nullptr) qnode.push(key->right);
            }
            // 先加入temp 层序遍历 然后奇数层倒序temp
            if(layer % 2 != 0){
                reverse(temp.begin(), temp.end());
            }
            layer++;
            ans.push_back(temp);
        }
        return ans;
    }
};