class Solution {
public:
    bool isNumber(string s) {
        while(s[0]==' ') s.erase(s.begin());
        while(s[s.length()-1]==' ') s.pop_back();
        if(s.length()==0) return false;
        bool e_exist=false;
        bool dot_exist=false;
        bool char_exist=false;
        bool sign_exist=false;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='+' || s[i]=='-'){
                if(dot_exist || char_exist) return false;
            }else if(s[i]<='9' && s[i]>='0'){
                char_exist=true;
            }else if(s[i]=='.'){
                if(dot_exist || e_exist) return false;
                dot_exist=true;
            } else if(s[i]=='e'){
                if(e_exist || !char_exist) return false;
                e_exist=true;
                dot_exist=char_exist=sign_exist =false;
            } else {
                return false;
            }
        }
        return char_exist;
    }
};