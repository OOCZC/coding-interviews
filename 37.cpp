// 序列化二叉树，'$'代替 nullptr
char* Serialize(TreeNode *root){
    if(root == nullptr)
        return nullptr;
    string str;  // 用string可以控制char数组的大小
    Serialize(str, root);
    char *c_str = new char[str.length() + 1];
    for(int i = 0; i < str.length(); ++i){
        c_str[i] = str[i];
    }
    c_str[str.length()] = 0;
    return c_str;
}

void Serialize(string &str, TreeNode *root){
    if(root == nullptr){
        str += "$,";
        return;
    }
    str += to_string(root -> val); // to_string可以直接写入
    str += ',';
    Serialize(str, root -> left);
    Serialize(str, root -> right);
}

TreeNode* Deserialize(char *str, int &str_length){
    if(str[str_length] == 0 || str[str_length] == '$'){
        str_length += 2;
        return nullptr;
    }
    int val = 0;
    while(str[str_length] != ','){
        val = val * 10;
        val += str[str_length++] - '0';
    }
    str_length ++;
    TreeNode *node = new TreeNode(val);
    node -> left = Deserialize(str, str_length);
    node -> right = Deserialize(str, str_length);
    return node;
}

TreeNode* Deserialize(char *str){
    if(str == nullptr)
        return nullptr;
    int str_length = 0;
    return Deserialize(str, str_length);
}


