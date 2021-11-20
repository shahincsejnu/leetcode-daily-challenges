class Solution {
public:
    string Add(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        string ans = "";

        for(int i = n1; i < n2; i++) s1 += '0';
        for(int i = n2; i < n1; i++) s2 += '0';

        int n = max(n1, n2), carry = 0;

        for(int i = 0; i < n; i++){
            int val = (s1[i]-'0') + (s2[i]-'0');
            val += carry;

            carry = val/10;

            int d = val%10;

            ans += (d + '0');
        }

        if(carry) ans += (carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string Multi(string s, int num)
    {
        int n = s.size(), carry = 0;
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++){
            int val = s[i]-'0';
            val *= num;
            val += carry;
            carry = val/10;

            int d = val % 10;

            ans += (d + '0');
        }

        if(carry) ans += (carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        string ans = "";
        string zero = "";

        for(int i = n2-1; i >= 0; i--){
            string s = Multi(num1, num2[i]-'0');
            s += zero;
            ans = Add(ans, s);
            zero += '0';
        }

        return ans;
    }
};