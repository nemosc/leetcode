class Solution {
public:
    int largestRectangleArea(vector<char>& heights) {
        stack<int> st;
        int n = heights.size();
        int result = 0;
        int top;
        int value;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                top = st.top();
                st.pop();
                value=st.empty()?-1:st.top();
                result = max(result,(i-1-value)*heights[top]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            top= st.top();
            st.pop();
            value=st.empty()?-1:st.top();
            result = max(result,(n-1-value)*heights[top]);
        }
        return result;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m =matrix.size();
        if(m==0) return 0;
        int n  = matrix[0].size();
        for(int j = 0;j<n;j++) matrix[0][j]-='0';
        for(int i =1;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]=='0') matrix[i][j] = 0;
                else matrix[i][j] = matrix[i-1][j]+1;
            }
        }
        int result = 0;
        for(int i = 0;i<m;i++)
        {
            result = max(result,largestRectangleArea(matrix[i]));
        }
        return result;
    }
};
