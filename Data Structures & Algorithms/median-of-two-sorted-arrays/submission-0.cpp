class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int median_pos=(n+m+1)/2;
        int low=0;
        int high=n;

        while(low<=high){
            int cut1=(high-low)/2+low;
            int cut2=median_pos-cut1;

            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;

            if(cut1>=1) l1=nums1[cut1-1];
            if(cut1<n)  r1=nums1[cut1];
            if(cut2>=1) l2=nums2[cut2-1];
            if(cut2<m)  r2=nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0) return (double)(max(l1,l2)+min(r1,r2))/2;
                else return max(l1,l2);
            }
            else if(l1>r2){
                high=cut1-1;
            }
            else low=cut1+1;
        }
        return (double) -1;
    }
};