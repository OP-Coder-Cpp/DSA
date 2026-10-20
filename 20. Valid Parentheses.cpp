#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> umap;
        umap[')']='(';
        umap['}']='{';
        umap[']']='[';

        stack<char> st;

        for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else
            {
                if(st.empty())
                    return false;
                else if((ch==')' && st.top()==umap[ch]) || (ch=='}' && st.top()==umap[ch]) || (ch==']' && st.top()==umap[ch]))
                    st.pop();
                else
                    return false;

            }
        }
        if(st.empty())
            return true;
        return false;
    }
};