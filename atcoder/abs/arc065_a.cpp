#include <bits/stdc++.h>
using namespace std;

vector<string> divisions = {"dream", "dreamer", "erase", "eraser"};

bool CanConsist(const string &s)
{
    int n = s.length();
    vector<bool> dp(n, false); // 検証を開始すべきIndexをtrueとする
    dp[0] = true;              // まずは1文字目から

    for (int i = 0; i <= n; i++)
    {
        if (!dp[i]) continue;

        for (const string &div : divisions)
        {
            if (i + div.length() <= n && s.substr(i, div.length()) == div)
            {
                int idx = i + div.length();
                if (idx == n) return true; // 最後の文字列まで一致したらOK
                dp[idx] = true;
            }
        }
    }

    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << (CanConsist(input) ? "YES" : "NO") << endl;
}