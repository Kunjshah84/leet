class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1){
            bool flg=0;
            for(int i=0;i<(s.size());i++){
                if(s[i]==part[0]){
                    string temp=  s.substr(i, part.size());
                    if(temp==part){
                        s=(s.substr(0,i)+s.substr(i+part.size(),(s.size()-i-part.size())));
                        flg=1;
                    }
                }
                if(flg) break ;
            }
            if(!flg)    break ;
        }
        return s;
    }
};