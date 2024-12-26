Ques 3 You are given an integer array arr[]. Your task is to find the 
smallest positive number missing from the array. 
 
Program Code: 
#include <iostream> 
#include <vector> 
using namespace std; 
int findSmallestMissingPositive(vector<int>& arr) { 
    int n = arr.size(); 
    for (int i = 0; i < n; i++) { 
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) { 
            swap(arr[i], arr[arr[i] - 1]); 
        } 
    } 
    for (int i = 0; i < n; i++) { 
        if (arr[i] != i + 1) return i + 1; 
    } 
    return n + 1; 
} 
int main() { 
vector<int> arr = {2, -3, 4, 1, 1, 7}; 
cout << findSmallestMissingPositive(arr) << endl; 
return 0; 
} 
