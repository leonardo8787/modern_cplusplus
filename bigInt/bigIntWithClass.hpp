#ifndef BIGINT_H
#define BIGINT_H

#include<bits/stdc++.h>
using namespace std;

class BigIng {
    private:
        vector<long long int> digits;
    public:
        BigIng(string num_str) {
            for (long long int i = num_str.size() - 1; i >= 0; i--)
                digits.push_back(num_str[i] - '0');
        }

        BigIng(const BigIng& other) : digits(other.digits) {}

        string toString() const {
            string result;
            for (int i = digits.size() - 1; i >= 0; i--)
                result += to_string(digits[i]);
            return result;
        }

        BigIng operator+(const BigIng& other) const {
            BigIng result("0"); 
            long long int max_len = max(digits.size(), other.digits.size());
            long long int carry = 0;
            for (long long int i = 0; i < max_len; i++) {
                if (i < other.digits.size()) {
                    result.digits[i] += other.digits[i] + carry;
                } else {
                    result.digits[i] += carry;
                }
                carry = result.digits[i] / 10;
                result.digits[i] %= 10;
            }
            if (carry != 0) {
                result.digits.push_back(carry);
            }
            return result;
        }

        BigIng operator-(const BigIng& other) const {
            BigIng result("0");
            long long int borrow = 0;
            for (long long int i = 0; i < digits.size(); i++) {
                long long int s = borrow + digits[i];
                if (i < other.digits.size())
                    s -= other.digits[i];
                if (s < 0) {
                    s += 10;
                    borrow = -1;
                } else 
                    borrow = 0;
                result.digits[i] = s;
            }
      
            for (long long int i = result.digits.size() - 1; i > 0; i--) {
                if (result.digits[i] == 0)
                    result.digits.pop_back();
                else
                    break;
            }
            return result;
        }
};

#endif