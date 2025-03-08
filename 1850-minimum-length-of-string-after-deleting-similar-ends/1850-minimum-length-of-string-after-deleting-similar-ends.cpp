class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1,counter=s.size();
        int left_counter=1,right_counter=1;
        while(i<j){
            while(i<j-1 && s[i]==s[i+1]){
                left_counter++;
                i++;
            }
            while(j>i+1 && s[j]==s[j-1]){
                right_counter++;
                j--;
            }
            if(s[i]==s[j]){
                counter-=(left_counter+right_counter);
                left_counter=1;
                right_counter=1;
            }
            else
                break ;
            i++;
            j--;
        }
        return counter;
    }
};