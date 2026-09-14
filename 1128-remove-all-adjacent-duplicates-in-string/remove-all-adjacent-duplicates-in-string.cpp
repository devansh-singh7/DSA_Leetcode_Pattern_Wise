class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st; // stack
        int i;
        string res;

        for(i = 0; i < s.size(); i++)
        {
            if(st.empty())    // Put the first value in stack.
            {
                st.push(s[i]);
                continue;
            }

            if(st.top() == s[i])   // Check of duplicate from stack top and s string.
            {
                st.pop();
                continue;
            }

            st.push(s[i]);  // Push if no duplicate found.
        }

        // Extract string from stack and then reverse it.

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};