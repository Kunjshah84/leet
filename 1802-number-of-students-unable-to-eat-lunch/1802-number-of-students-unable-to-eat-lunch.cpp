class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& san) {
        int cnt=0;
        queue<int> q;
        stack<int> s;
        int i=san.size()-1;
        while(i>=0)
            s.push(san[i--]);
        i=0;
        while(i<stu.size()){
            q.push(stu[i]);
            if(stu[i])  cnt++;
            i++;
        }
        while(!q.empty()){
            if(q.front()==s.top()){
                s.pop();
                cnt-=q.front();
                q.pop();
            }
            else{
                cout<<cnt<<" "<<q.size()<<endl;
                if((s.top()==0 && cnt==q.size()) || (s.top()==1 && cnt==0))   
                    return  q.size();
                int val=q.front();
                q.pop();
                q.push(val);
            }
        }
        return 0;      
    }
};