class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        if(n==2){
            return true;
        }
        if(n%2==0){
            return false;
        }
        for (int i = 3; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int createPalindrome(int x) {
        string s = to_string(x);
        string rev = s.substr(0, s.size()-1);
        reverse(rev.begin(), rev.end());
        return stoi(s + rev);
    }
        
    int primePalindrome(int n) {
        if(n <= 11){
            vector<int>v={2,3,5,7,11};
            for(int p : v){
                if(n<=p){
                    return p;
                }
            }
        }
        for(int i=1;i<100000;i++){
            int a = createPalindrome(i);
            if(a >= n && isPrime(a)){
                return a;
            }
        }
        return -1;
    }
};