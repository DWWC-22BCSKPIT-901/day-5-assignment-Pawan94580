Ques 4. You are given an m x n matrix mat that has its rows sorted in non
decreasing order and an integer k. 
You are allowed to choose exactly one element from each row to form an 
array. 
Return the kth smallest array sum among all possible arrays. 
Program Code: 
#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
int kthSmallest(vector<vector<int>>& mat, int k) { 
    priority_queue<int, vector<int>, greater<>> minHeap; 
    minHeap.push(0); 
    for (const auto& row : mat) { 
        priority_queue<int, vector<int>, greater<>> nextHeap; 
        while (!minHeap.empty()) { 
            int sum = minHeap.top(); 
            minHeap.pop(); 
            for (int num : row) { 
                nextHeap.push(sum + num); 
                if (nextHeap.size() > k) nextHeap.pop(); 
            } 
        } 
        minHeap.swap(nextHeap); 
    } 
    return minHeap.top(); 
} 
int main() { 
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}}; 
    int k = 5; 
    cout << kthSmallest(mat, k) << endl; 
    return 0; 
} 
