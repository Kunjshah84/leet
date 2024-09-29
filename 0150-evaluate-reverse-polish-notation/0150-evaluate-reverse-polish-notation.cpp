class Solution {

    int cal(int v1,int v2,string p){
        if(p=="+")  return v1+v2;
        if(p=="-")  return v1-v2;
        if(p=="*")  return v1*v2;
        return v1/v2;
    }

public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(int i=0;i<t.size();i++){
            if(t[i]!="+" && t[i]!="-" && t[i]!="*" && t[i]!="/")  
                s.push(stoi(t[i]));
            else{
                int v2=s.top();
                s.pop();
                int v1=s.top();
                s.pop();
                s.push(cal(v1,v2,t[i]));
            }
        }
        return s.top();
    }
};