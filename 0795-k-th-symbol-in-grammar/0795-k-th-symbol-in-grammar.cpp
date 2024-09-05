class Solution {

    int get(int n,int k){
        if(n==2)
            if(k%2)
                return 0;
            else return 1;
        return (get(n-1,((k/2)+k%2))) ? ((k%2) ? 1: 0) : ((k%2) ? 0: 1);
    }

public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        return get(n,k);
    }
};