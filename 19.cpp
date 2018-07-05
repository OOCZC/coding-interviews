bool match(char* str, char* patten){
    if(str == nullptr || patten == nullptr)
        return false;
    
    return matchCore(str, patten);
}

bool matchCore(char* str, char* patten){
    if(str[0] == 0 && patten[0] == 0)
        return true;
    if(str[0] != 0 && patten[0] == 0)
        return false;
    bool ans = false;
    if(str[0] == patten[0]){
        ans = ans || matchCore(str + 1, patten + 1);
    }
    if(patten[0] == '.' && str[0] != 0){ // 注意这里str[0] != 0
        ans = ans || matchCore(str + 1, patten + 1);
    }
    if(patten[1] == '*'){
        ans = ans || matchCore(str, patten + 2);
        if(str[0] == patten[0] || (patten[0] == '.' && str[0] != 0)){
        // 注意这里patten[0] == '.' 的情况
            ans = ans || matchCore(str + 1, patten);
        }
    }
    return ans;
}
