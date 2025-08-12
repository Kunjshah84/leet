class Solution {

    bool get(vector<int> &stones,int pow,map<int,int> &m,
    map<pair<int,int>,int> &s,int ind){
        if(ind==stones.size()-1)    return 1;
        pair<int,int> temp={ind,pow};
        if(s.find(temp)!=s.end())   return s[temp];
        if((m.find(stones[ind]+(pow-1))!=m.end() &&
        m[stones[ind]+(pow-1)] > ind &&
        get(stones,pow-1,m,s,m[stones[ind]+(pow-1)]))
        || (m.find(stones[ind]+(pow))!=m.end() &&
        m[stones[ind]+(pow)] > ind &&
        get(stones,pow,m,s,m[stones[ind]+(pow)])) ||
        (m.find(stones[ind]+(pow+1))!=m.end() &&
        m[stones[ind]+(pow+1)] > ind &&
        get(stones,pow+1,m,s,m[stones[ind]+(pow+1)])))    return 1;
        s[{ind,pow}]=0;
        return 0;
    }

public:
    bool canCross(vector<int>& stones) {
        if(stones[1]>1) return 0;
       map<pair<int,int>,int> s;
       map<int,int> m;
       for(int i=0;i<stones.size();i++) m[stones[i]]=i;
       return get(stones,1,m,s,1); 
    }
};