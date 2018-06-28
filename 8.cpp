// 找节点中序遍历的上一个节点
TreeNode* GetNext(TreeNode* node){
    if(node == nullptr)
        return nullptr;
    TreeNode* p = nullptr;
    if(node -> right != nullptr){
        p = node -> right;
        while(p -> left != nullptr)
            p = p -> left;
        return p;
    }
    else{
        p = node -> parent;
        if(p == nullptr)
            return nullptr;
        else if(p -> left == node){
            return p;
        }
        else if(p -> right == node){
            while(p -> parent != nullptr){
                if(p -> parent -> left == p)
                    return p -> parent;
                p = p -> parent;
            }
            return nullptr;
        }
        else
            throw std::exception();
    }
} 
