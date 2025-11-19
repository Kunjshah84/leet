class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for(auto it:tasks)  map[it-'A']++;
        sort(map.begin(),map.end());
        int gaps=map[25]-1;
        int idels=gaps*n;
        for(int i=24;i>=0;i--)  idels-=min(gaps,map[i]);
        if(idels<=0)    return tasks.size();
        return tasks.size()+idels;
    }
};