class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size()==2)
            return skill[0]*skill[1];
        sort(skill.begin(),skill.end());
        int s=1,e=skill.size()-2;
        long long ans=skill[0]*skill[skill.size()-1];
        int pre=skill[0]+skill[skill.size()-1];
        while(s<e){
            if(skill[s]+skill[e]!=pre){
                cout<<s<<" "<<e<<endl;
                return -1;
            }
            else
                ans+=(skill[s]*skill[e]);
            s++;
            e--;
        }
        return ans;
    }
};