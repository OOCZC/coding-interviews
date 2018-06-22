#include <iostream>
#include <string.h>
using namespace std;

class CMYString{

public:
    CMYString(char* pData = nullptr);
    CMYString(const CMYString& str);
    ~CMYString(void);
    void StringPrint();
    CMYString& operator=(const CMYString& str);
private:
    char* m_pData;
};

void CMYString::StringPrint(){
    cout << m_pData << endl;
}


CMYString::CMYString(char* pData){
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData = '\0';
    }
    else{
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMYString::CMYString(const CMYString& str){
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
} 
CMYString::~CMYString(){
    delete[] m_pData;
}

CMYString& CMYString::operator = (const CMYString &str){
// 加const因为不想修改str对象，且加上const可以接收const或非const实参，不加只能接收非const实参。
// 返回一个左值引用
// 这里返回值去掉引用&也可连续赋值？
    if(this == &str)
        return *this;

    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    
    return *this;
}

int main(){

    char* text = (char *)"111";
    CMYString str1(text);
    CMYString str2((char*)"222");
    CMYString str3((char*)"333");
    // 调用 CMYString(char* pData = nullptr); 用nullptr参数
    str3 = str2 = str1;
    str1.StringPrint();
    str2.StringPrint();
    str3.StringPrint();

    return 0;
}
