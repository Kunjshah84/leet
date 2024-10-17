class Solution {

    void convert(vector<int> &r,int n){
        if(!n)
            r.push_back(0);
        while(n){   
            r.push_back(n%10);
            n/=10;
        }
        reverse(r.begin(),r.end());
    }

    int converttoint(vector<int> &r){
        int sum=0,i=0;
        while(i<r.size()){
            sum=(sum*10)+r[i];
            i++;
        }
        return sum;
    }   

public:
    int maximumSwap(int num) {
        vector<int> r;
        convert(r,num);
        vector<int> l=r;
        sort(l.begin(),l.end());
        int i=0,j=l.size()-1;
        while(i<r.size()){
            if(r[i]!=l[j]){
                int temp=i,ind=l.size()-1;
                while(r[ind]!=l[j])
                    ind--;
                swap(r[temp],r[ind]);
                break ;
            }
            i++;
            j--;
        }
        return converttoint(r);
    }
};