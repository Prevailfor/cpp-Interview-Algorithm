//链接：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423
//来源：牛客网

class Solution {
public:
    void replaceSpace(char *str,int length) {
        string s(str);
        int i=0;
        while((i=s.find(' ',i))>-1){
            s.erase(i,1);
            s.insert(i,"%20");
             
        }
        auto ret=s.c_str();
        strcpy(str,ret);
    }
};
