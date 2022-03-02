class Solution {
public:
    int missingElement(const vector<int>& A, int k) {
        // inline function to get missing numbers count
        auto MissingNumbers = [&A](int pivot) -> int {
            return A[pivot] - A.front() - pivot;
        };
        
        int left = 0, right = A.size() - 1;
        int value = MissingNumbers(right);
        
        // kth missing element is outside the bounds of the array
        if (value < k) return A.back() + k - value;
        
        // simply binary search
        while (left < right) {
            
            // get the midpoint
            int pivot = left + (right - left) / 2;
            value = MissingNumbers(pivot);
            
            // compare and update pointers
            value < k ? left = pivot + 1 : right = pivot;
        }

        // return the kth smallest
        return A[left - 1] + k - MissingNumbers(left - 1);
    }
};