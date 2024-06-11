class Solution {
public:
    vector<int> NSR(vector<int>& arr) {
        vector<int> v;
        stack<pair<int, int>> stk;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty())
                v.push_back(n);
            else {
                if (stk.top().first <= arr[i])
                    v.push_back(stk.top().second);
                else {
                    while (!stk.empty() and stk.top().first > arr[i])
                        stk.pop();
                    if (stk.empty())
                        v.push_back(n);
                    else
                        v.push_back(stk.top().second);
                }
            }
            stk.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    vector<int> NSL(vector<int>& arr) {
        vector<int> v;
        stack<pair<int, int>> stk;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (stk.empty())
                v.push_back(-1);
            else {
                if (stk.top().first < arr[i])
                    v.push_back(stk.top().second);
                else {
                    while (!stk.empty() and stk.top().first >= arr[i])
                        stk.pop();
                    if (stk.empty())
                        v.push_back(-1);
                    else
                        v.push_back(stk.top().second);
                }
            }
            stk.push({arr[i], i});
        }
        return v;
    }
    vector<int> width(vector<int> x, vector<int> y) {
        vector<int> p;
        for (int i = 0; i < x.size(); i++)
            p.push_back(x[i] - y[i] - 1);
        return p;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rSmall = NSR(heights);
        vector<int> lSmall = NSL(heights);
        int MAX = INT_MIN;
        vector<int> Width = width(rSmall, lSmall);
        for (int i = 0; i < heights.size(); i++) {
            MAX = max(MAX, (heights[i] * Width[i]));
        }
        return MAX;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size(), result = 0;
        vector<int> histogram(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    histogram[j] += 1;
                else
                    histogram[j] = 0;
            }

            result = max(result, largestRectangleArea(histogram));
           
        }
        return result;
    }
};