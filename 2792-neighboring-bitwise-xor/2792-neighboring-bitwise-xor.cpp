class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int c1=0,v1=0,c2=1,v2=1;
        for(int i=0;i<derived.size()-1;i++)
            if(derived[i]){
                v1=(!v1);
                v2=(!v2);
            }
        if(derived[derived.size()-1])   return (v1==(!c1) || v2==(!c2)) ? 1: 0;
        return (v1==c1 || v2==c2) ? 1: 0;

    }
};