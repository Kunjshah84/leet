class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //To solve the question by using the binary search 
        //find the ceil value of the given K;
        /*int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==k)
                return k+mid+1;
            if(arr[mid]<k)
                s=mid+1;
            else
                e=mid-1;
        }
        //here s is the ceil value of the given k:-
        return ((s>=arr.size())?k:k+s+1);*/


        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2,temp=arr[mid]-(mid+1);
            if(k>temp)
                s=mid+1;
            else
                e=mid-1;
        }
        return s+k;//or you can right the low+k
    }
};