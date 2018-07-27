// 需要考虑有重复字符的情况，并且按字典序输出（输入的str本身为字典序）
// str = "aa", 输出为 "aa"，而非 {"aa","aa"}
vector<string> Permutation(string str){
    vector<string> vec, ans;
    string currString = "";
    AddPermutation(vec, currString, str);

    return vec;
}

void AddPermutation(vector<string> &vec, string currString,
                    string str){
    if(str.length() == 0)
        return;
    if(str.length() == 1){
        vec.push_back(currString + str);
        return;
    }
    for(int i = 0; i < str.length(); ++i){
        if(i == 0 || str[i] != str[i - 1]) // 去重
            AddPermutation(vec, currString + str[i], str.substr(0, i) + str.substr(i + 1));
    }
}
