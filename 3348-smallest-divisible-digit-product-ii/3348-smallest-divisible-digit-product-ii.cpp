class Solution {
public:
    typedef long long ll;

    string freeSlotFilter(ll num, int len) {
        string str;
        for (int dig = 9; dig >= 2; dig--) {
            while (num % dig == 0) {
                str.push_back(dig + '0');
                num /= dig;
            }
        }
        while (str.length() < len) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());

        return str;
    }
    string smallestNumber(string num, long long t) {
        int n = num.length();
        ll temp = t;
        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) {
                temp /= primeFact;
            }
        }

        if (temp != 1) {
            return "-1";
        }
        // precompute remainFactor[i] = if we take i degites of sum in my result
        // what factor remaining
        vector<ll> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if (digit == 0) {
                break;
            }
            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }
        if (remainingFactor[n] == 1) {
            return num;
        }
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        for (int i = zeroIdx; i >= 0; i--) {
            ll reqired = remainingFactor[i];
            int freeSlot = n - 1 - i;

            for (int dig = (num[i] - '0') + 1; dig <= 9; dig++) {
                ll furderReqired = reqired / gcd(reqired, (ll)dig);
                string requiedNumber = freeSlotFilter(furderReqired, freeSlot);

                if (requiedNumber.length() == freeSlot) {
                    return num.substr(0, i) + char(dig + '0') + requiedNumber;
                }
            }
        }
        return freeSlotFilter(t, n + 1);
    }
};