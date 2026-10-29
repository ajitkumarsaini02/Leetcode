class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string s = "";
        if ((numerator < 0) ^ (denominator < 0)) {
            s += "-";
        }

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        s += to_string(n / d);
        long long r = n % d;

        if (r == 0) return s;

        s += ".";
        unordered_map<long long, int> mp;

        while (r != 0) {
            if (mp.count(r)) {
                s.insert(mp[r], "(");
                s += ")";
                break;
            }

            mp[r] = s.length();
            r *= 10;
            s += to_string(r / d);
            r %= d;
        }

        return s;
    }
};