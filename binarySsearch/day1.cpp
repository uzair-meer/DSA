#include <iostream>

using namespace std;

// array is sorted
int findPeakInMounatainArray(int nums[]){
   int start = 0;
   int end = 6;
   while (start<end)
   {
    int mid = (start+end)/2;
    if (nums[mid] > nums[mid+1] )
    {
    // array in descending part
    // coz ans lies in left
    end = mid;
    }
    else if (nums[mid] < nums[mid+1] )
    {
        // ascending part
        // ans may lies in right
        start = mid+1;
    }
    
    
   }
   // both end and start will be pointing to peak at loop break
return start;
}



int main(){
int nums[] = {1,3,5,7,6,2,0};
int ans = findPeakInMounatainArray(nums);
cout<< ans;
    return 0;
}
