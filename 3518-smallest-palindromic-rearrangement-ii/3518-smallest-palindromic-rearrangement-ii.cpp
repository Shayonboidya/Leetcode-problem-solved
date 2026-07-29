class Solution
{
public:
    long long n_C_r(int k, int n, int r)
    {
        long long res = 1;
        r = min(r, n-r);
        for (int i = 1; i <= r; i++)
        {
            res = res * (n - r + i) / i;
            if (res >= k) {
                return k;
            }
        }
        return res;
    }

    string smallestPalindrome(string s, int k)
    {
        int n = s.length();
        char mid = ' ';
        if (n % 2 == 1)
        {
            mid = s[n / 2];
        }

        vector<int> count(26, 0);
        for (int i = 0; i < n; i++)
        {
            if (n % 2 == 1 && i == n / 2)
                continue;
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            count[i] /= 2;
        }

        string halfresult = "";
        int half = n / 2;
        for (int i = 0; i < half; i++)
        {
            bool placeCharter = false;
            for (int j = 0; j < 26; j++)
            {
                if (count[j] > 0)
                {
                    count[j] -= 1;
                    long long ways = 1;
                    int letter = 0;
                    for (int c = 0; c < 26; c++)
                    {
                        letter += count[c];
                    }
                    for (int c = 0; c < 26; c++)
                    {
                        if (count[c] > 0)
                        {
                            ways *= n_C_r(k, letter, count[c]);
                            letter -= count[c];
                        }
                        if (ways >= k)
                        {
                            break;
                        }
                    }
                    if (ways >= k)
                    {
                        halfresult.push_back('a' + j);
                        placeCharter = true;
                        break;
                    }
                    k -= ways;
                    count[j] += 1;
                }
            }
            if (placeCharter == false)
            {
                return "";
            }
        }
        string rev = halfresult;
        reverse(rev.begin(), rev.end());
        if (mid != ' ')
        {
            halfresult.push_back(mid);
        }
        return (halfresult + rev);
    }
};