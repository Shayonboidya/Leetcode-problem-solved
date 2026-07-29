class Solution
{
public:
    // Function to calculate nCr (Combination = n choose r)
    // Returns the number of ways to choose r items from n items.
    // If the result becomes greater than or equal to k, we return k
    // immediately to avoid unnecessary calculations and overflow.
    long long n_C_r(int k, int n, int r)
    {
        long long res = 1;

        // Use the smaller value of r for faster computation.
        // nCr = nC(n-r)
        r = min(r, n - r);

        for (int i = 1; i <= r; i++)
        {
            // Compute nCr iteratively.
            res = res * (n - r + i) / i;

            // No need to calculate further if the result is already >= k.
            if (res >= k)
            {
                return k;
            }
        }

        return res;
    }

    string smallestPalindrome(string s, int k)
    {
        int n = s.length();

        // Store the middle character for odd-length palindromes.
        char mid = ' ';
        if (n % 2 == 1)
        {
            mid = s[n / 2];
        }

        // Count the frequency of each character.
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++)
        {
            // Skip the middle character because it is fixed.
            if (n % 2 == 1 && i == n / 2)
                continue;

            count[s[i] - 'a']++;
        }

        // Only half of each character is needed to build
        // the left half of the palindrome.
        for (int i = 0; i < 26; i++)
        {
            count[i] /= 2;
        }

        string halfresult = "";
        int half = n / 2;

        // Construct the left half of the palindrome.
        for (int i = 0; i < half; i++)
        {
            bool placeCharter = false;

            // Try placing every possible character
            // in lexicographical order.
            for (int j = 0; j < 26; j++)
            {
                if (count[j] > 0)
                {
                    // Temporarily use one occurrence of this character.
                    count[j]--;

                    long long ways = 1;

                    // Count how many characters remain.
                    int letter = 0;
                    for (int c = 0; c < 26; c++)
                    {
                        letter += count[c];
                    }

                    // Calculate the number of different arrangements
                    // possible with the remaining characters.
                    for (int c = 0; c < 26; c++)
                    {
                        if (count[c] > 0)
                        {
                            ways *= n_C_r(k, letter, count[c]);
                            letter -= count[c];
                        }

                        // Stop early if ways already reaches k.
                        if (ways >= k)
                        {
                            break;
                        }
                    }

                    // If the kth palindrome is inside these arrangements,
                    // choose this character.
                    if (ways >= k)
                    {
                        halfresult.push_back('a' + j);
                        placeCharter = true;
                        break;
                    }

                    // Otherwise skip all these arrangements.
                    k -= ways;

                    // Restore the character because it wasn't chosen.
                    count[j]++;
                }
            }

            // If no character can be placed,
            // the kth palindrome does not exist.
            if (placeCharter == false)
            {
                return "";
            }
        }

        // Create the right half by reversing the left half.
        string rev = halfresult;
        reverse(rev.begin(), rev.end());

        // Insert the middle character for odd-length palindromes.
        if (mid != ' ')
        {
            halfresult.push_back(mid);
        }

        // Final palindrome = left half + middle (if any) + reversed left half.
        return (halfresult + rev);
    }
};