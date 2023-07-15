#include<iostream>

using namespace std;


int pivot(int nums[], int n){
    int start = 0;
    int end = n-1;

while (start< end)
{
    int mid = (start +  end)/2;
    if (nums[mid] > nums[mid+1])
    {
        return mid;
    }
    if (nums[mid] < nums[mid-1])
    {
        return mid-1;
    }
    if (nums[start] > nums[mid])
    {
        end = mid-1;
    } else if(nums[start] < nums[mid]){
        start = mid+1;
    }
    
    
}

return -1;
}
// how many times array is shifted
int noOfRotations(int nums[], int size){
  int ans= pivot(nums, size);
if (ans==-1)
{
    return -1;
}


return ans +1;
}



int main(){
    int nums[] = {12, 10, 2,4,6,7, 8};
    int pivt = noOfRotations(nums, 7);
    cout<< pivt;
    return 0;
}