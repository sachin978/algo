class Solution {
public:
    int validSubarraySize(vector<int>& a, int threshold) {
        int n = a.size();
        
        vector<int> stk;                            // used as a stack
        vector<int> nextS(n, -1), prevS(n, -1);     // used for storing next and previous smaller elements
                
        // firstly, let's find out the next smaller elements
        for(int i = 0; i < n; i++) {
            while (!stk.empty() && a[i] < a[stk.back()]) {
                nextS[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }

        // clear up our stack
        stk.clear();
        
        // now, let's find out the previous smaller elements for each index
        for(int i = n-1; i >= 0; i--) {
            while (!stk.empty() && a[i] < a[stk.back()]) {
                prevS[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        for(int i = 0; i < n; i++) {
            int left = prevS[i];                            // left boundary
            int right = nextS[i] == -1 ? n : nextS[i];      // right boundary
            
            int len = right - left - 1;                     // length of subarray formed with a[i] as minimum
            
            if (a[i] > (threshold / ((double) len)))
                return len;
        }
        
        return -1;
    }
};
