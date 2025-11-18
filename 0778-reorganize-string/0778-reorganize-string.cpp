class Solution {
public:
    string reorganizeString(string s) {
        vector<int> CharVector(26,0);
        int sizeLimit=((s.size()+1)/2);
        for(auto it:s){
            CharVector[it-'a']++;
            if(CharVector[it-'a']>sizeLimit)    return "";
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++)   
            if(CharVector[i])    pq.push({CharVector[i],'a'+i});
        string ans="";
        while(pq.size()>=2){
            pair<int,char> firstv=pq.top();
            pq.pop();
            pair<int,char> secondv=pq.top();
            pq.pop();
            ans+=(firstv.second);
            ans+=(secondv.second);
            if(firstv.first-1 > 0 )  pq.push({firstv.first-1,firstv.second});
            if(secondv.first-1 > 0 )  pq.push({secondv.first-1,secondv.second});
        }
        if(pq.size())   ans+=(pq.top().second);
        return ans;
    }
};