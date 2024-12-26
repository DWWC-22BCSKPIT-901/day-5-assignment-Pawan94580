#include <iostream> 
#include <vector> 
using namespace std; 
vector<int> searchRange(const vector<int>& nums, int target) { 
auto findBound = [&](bool isFirst) -> int { 
int left = 0, right = nums.size() - 1; 
int bound = -1; 
        while (left <= right) { 
            int mid = left + (right - left) / 2; 
            if (nums[mid] == target) { 
                bound = mid; 
                if (isFirst) { 
                    right = mid - 1;  
                } else { 
                    left = mid + 1; 
                } 
            } else if (nums[mid] < target) { 
                left = mid + 1; 
            } else { 
                right = mid - 1; 
            } 
        } 
        return bound; 
    }; 
    int start = findBound(true);  
    int end = findBound(false);   
    return {start, end}; 
} 
int main() { 
    vector<int> nums = {5, 7, 7, 8, 8, 10}; 
    int target = 8; 
    vector<int> result = searchRange(nums, target); 
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; 
    return 0; 
} 
