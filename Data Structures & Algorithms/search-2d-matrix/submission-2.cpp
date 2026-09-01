class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = n * m - 1;
        int mid = 0;

        while(left <= right) {
            mid = left + (right - left) / 2;

            int val = matrix[mid/m][mid%m];
            cout << val << endl;

            if(target == val) return true;
            else if (target > val) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
