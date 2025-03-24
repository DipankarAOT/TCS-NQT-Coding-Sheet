/*
Sort Elements of an Array by Frequency

Problem Statement: Given an array of integers, having some duplicate elements, sort the array by frequency.

Examples:

Example 1:
Input: N = 8, array[] = {1,2,3,2,4,3,1,2}
Output: 2 2 2 1 1 3 3 4 
Explanation: Since  2 is present 3 times in an array , so print it 3 times ,then print ‘1’ 2 times and then ‘3’ 2 times and 4 has least frequency, it will be printed at last.

Example 2:
Input: N = 6, array[] = {-199,6,7,-199,3,5}
Output: -199 -199 3 5 6 7
Explanation: Since -199 is present 2 times so it will be printed at first , then 3 , 5 ,6 ,7 are present once in array , so print them in their sorted order.

*/ 


#include <bits/stdc++.h>
using namespace std;

// Custom comparator for sorting
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first; // Sort by value if frequency is same
    return a.second > b.second;  // Sort by frequency (higher first)
}

void sortByFrequency(vector<int>& v) {
    unordered_map<int, int> freqMap;

    // Count frequency of each element
    for (int num : v) {
        freqMap[num]++;
    }

    // Move map elements to a vector for sorting
    vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

    // Sort by frequency (descending) and then by value (ascending)
    sort(freqVec.begin(), freqVec.end(), cmp);

    // Print sorted elements
    cout << "Sorted by frequency: ";
    for (auto it : freqVec) {
        for (int i = 0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> v = {4, 2, 2, 6, 1, 5, 5, 5, 3};
    sortByFrequency(v);
    return 0;
}

