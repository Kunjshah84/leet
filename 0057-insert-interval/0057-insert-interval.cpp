class Solution {


public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newin) {
        if(in.size()==0 && newin.size())    return {newin};
        else if(in.size()==0 && newin.size()==0)    return {};
        vector<vector<int>> ans;
        bool flg=0;
        for(int i=0;i<in.size();i++){
            if(!flg){
                if(in[i][0]<=newin[0] && in[i][1]>=newin[1])    return in;
                else if(newin[1]<in[i][0]){
                    ans.push_back(newin);
                    ans.push_back(in[i]);
                    flg=1;
                }
                else if(!(newin[0]>in[i][1])){
                    in[i][0]=min(newin[0],in[i][0]);
                    in[i][1]=max(newin[1],in[i][1]);
                    ans.push_back(in[i]);
                    flg=1;
                }
                else{
                    ans.push_back(in[i]);
                }
            }
            else{
                if(ans[ans.size()-1][1]>=in[i][0])   
                    ans[ans.size()-1][1]=max(ans[ans.size()-1][1],in[i][1]);
                else ans.push_back(in[i]);   
            }
        }
        if(!flg)    ans.push_back(newin);
        return ans;
    }
};