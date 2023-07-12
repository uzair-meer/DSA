#include <iostream>

using namespace std;

// naive aproach with linear search

int* findPositions(int nums[], int target){
 int* ans = new int[2];
 
    ans[0] = -1;
    ans[1] = -1;

    for (int i = 0; i < 6; i++)
    {
        if (target == nums[i])
        {
            if (ans[0] == -1)
            {
                ans[0] = i;
            }
          ans[1] = i;
        }
        
    }
    return ans;
}





// find first and last position/ occurence of taget in array
//optimized with binary search
int search(int nums [], int target, bool firstIndex){

        int ans =-1;
        int start = 0;
        int end = 6 - 1 ;
        // if first index true find in first half else in second half
        while(start  <= end){
            int mid = (start + end) /2;
            if(target == nums[mid]){
                // potential ans => // first timme/run answer

                // now ans will update on each find in first half after the intial find
                ans = mid;
                if(firstIndex){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else if (target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        
     return ans;   
    }
int* searchRange(int nums [], int target){
     int* ans = new int[2];
    ans[0] = -1;
    ans[1] = -1;
         
         // first index
        ans[0] = search(nums, target, true);
        // 2nd index
        ans[1] = search(nums, target, false);
     
    return ans;
    }

int main()
{
   int nums[] = {5, 7, 7, 8, 8, 10};
//   int* ptr =   searchRange(nums, 8);
  int* ptr =   findPositions(nums, 8);

   cout << ptr[0] << ", " << ptr[1] <<endl;
    return 0;
}




// search in infinte sorted array

int binarySearch(int nums[], int target, int start, int end){
    while(start <= end){
        int mid = (start + end) /2;
        if(target > nums[mid]){
            start = mid+1;
        }
        else if(target < nums[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
    
}

int findPositionInInfineArray(int nums [], int target){
    
    // first we gotta define the range in which ans lies
    
    int start = 0;
    int end = 1;
    
    // first we gotta start from box size int32_t
    
    // and unless its not greater than end means its no in range
    while(target > nums[end]){
        
        // new start
        int newStart = end+1;
        // now updating end
        end = end -(end- start +1) * 2;
        
        start = newStart;
        
    }
    return binarySearch(nums, target, start, end);
}
