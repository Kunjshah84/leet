class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long int> temp(skill.size(),0);
        for(int i=0;i<mana.size();i++){
            temp[0]+=(mana[i]*skill[0]*1ll);
            for(int j=1;j<skill.size();j++)
                temp[j]=(max(temp[j],temp[j-1])+(skill[j]*mana[i]));
            for(int ind=skill.size()-1;ind>=1;ind--){
                temp[ind-1]=temp[ind]-(skill[ind]*mana[i]);
            }
        }   
        return temp[temp.size()-1]; 
    }
};