#include <cctype>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidIPv4(const string& ip) {
        int dot = 0;
        for (char c : ip) {
            if (c == '.') dot++;
        }

        if (dot != 3) return false;

        stringstream ss(ip);
        string token;
        int parts = 0;

        while (getline(ss, token, '.')) {
            parts++;

            if (token.empty() || token.size() > 3) return false;

            for (char c : token) {
                if (!isdigit(c)) return false;
            }

            if (token.size() > 1 && token[0] == '0') return false;

            int val = stoi(token);
            if (val < 0 || val > 255)  return false;
        }
        return parts == 4;
    }

    bool isValidIPv6(const string& ip) {
        int coln = 0;
        for (char c : ip) {
            if (c == ':') coln++;
        }
        if (coln != 7) return false;

        stringstream ss(ip);
        string token;
        int parts = 0;

        while (getline(ss, token, ':')) {
            parts++;

            if (token.empty() || token.size() > 4) return false;

            for (char c : token) {
                if (!isxdigit(c)) return false;
            }
        }
        return parts == 8;
    }

    string validIPAddress(string queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};