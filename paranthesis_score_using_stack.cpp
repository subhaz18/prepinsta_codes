#include <bits/stdc++.h>
#include <stack>
using namespace std;
long long scoreOfParentheses(string S)
{
stack<string> s;
int i = 0;
long long ans = 0;
while (i < S.length()) {
// If s[i] is '('
if (S[i] == '(')
s.push("(");
else {
if (s.top() == "(") {
s.pop();
s.push("1");
}
else {
long long count = 0;
while (s.top() != "(") {
count += stoi(s.top());
s.pop();
}
s.pop();
s.push(to_string(2 * count));
}
}
i++;
}
while (!s.empty()) {
ans += stoi(s.top());
s.pop();
}
return ans;
}

int main()
{
string S1 = "(()(())";
cout << scoreOfParentheses(S1) << endl;
return 0;
}