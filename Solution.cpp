
#include <queue>
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com.
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    int minDepth(TreeNode* root) const {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        int depthLevel = 0;
        bool leafNodeFound = false;

        while (!queue.empty() && !leafNodeFound) {
            ++depthLevel;
            int nodesInDepthLevel = queue.size();

            while (nodesInDepthLevel-- > 0) {
                TreeNode* current = queue.front();
                queue.pop();
                
                if (isLeafNode(current)) {
                    leafNodeFound = true;
                    break;
                }
                if (current->left != nullptr) {
                    queue.push(current->left);
                }
                if (current->right != nullptr) {
                    queue.push(current->right);
                }
            }
        }
        return depthLevel;
    }

private:
    bool isLeafNode(const TreeNode* node) const {
        return node->left == nullptr && node->right == nullptr;
    }
};
