#include <iostream> 
#include <vector> 
using namespace std; 
int findFirstOccurrence(int k, const vector<int>& arr) { 
    for (int i = 0; i < arr.size(); i++) { 
        if (arr[i] == k) { 
            return i + 1;  
        } 
    } 
    return -1;  
} 
int main() { 
    int k = 16; 
    vector<int> arr = {9, 7, 16, 16, 4}; 
int result = findFirstOccurrence(k, arr); 
cout << result << endl; // Output: 3 
return 0; 
} 
