class Solution {

    int get(int n,int k){
        if(n==2)
            if(k%2)
                return 0;
            else return 1;
        int t=get(n-1,((k/2)+k%2));
        if(t==0)
            if(k%2==0) return 1;
            else return 0;
        else
            if(k%2==0) return 0;
            else return 1;
    }

public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        return get(n,k);
    }
};