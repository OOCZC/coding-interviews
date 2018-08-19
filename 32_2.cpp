class Solution {
public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> ans;
        stack<TreeNode*> sta[2];
        if (pRoot == nullptr)
            return ans;
        sta[0].push(pRoot);
        while (sta[0].size() > 0) {
            vector<int> layer, layer1;
            while (sta[0].size() > 0) {
                TreeNode *p = sta[0].top();
                layer.push_back(p -> val);
                if (p -> left != nullptr)
                    sta[1].push(p -> left);
                if (p -> right != nullptr)
                    sta[1].push(p -> right);
                sta[0].pop();
            }
            while (sta[1].size() > 0) {
                TreeNode *p = sta[1].top();
                layer1.push_back(p -> val);
                if (p -> right != nullptr)
                    sta[0].push(p -> right);
                if (p -> left != nullptr)
                    sta[0].push(p -> left);
                sta[1].pop();
            }
            ans.push_back(layer);
            if (layer1.size() > 0)
                ans.push_back(layer1);
        }
        return ans;
    }
};
