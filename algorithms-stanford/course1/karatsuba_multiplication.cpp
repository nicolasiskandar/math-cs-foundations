#include <bits/stdc++.h>

using namespace std;

string trim(const string &s)
{
    size_t i = s.find_first_not_of('0');
    return (i == string::npos) ? "0" : s.substr(i);
}

string add(const string &a, const string &b)
{
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return trim(res);
}

string sub(const string &a, const string &b)
{
    string res;
    int borrow = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0) // assuming a > b
    {
        int diff = (a[i--] - '0') - borrow;
        if (j >= 0)
            diff -= b[j--] - '0';
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        res.push_back(char('0' + diff));
    }

    reverse(res.begin(), res.end());
    return trim(res);
}

string shift(const string &a, int zeros)
{
    if (a == "0")
        return "0";
    return a + string(zeros, '0');
}

string karatsuba(const string &x, const string &y)
{
    int n = max(x.size(), y.size());

    if (n == 1)
    {
        int prod = (x[0] - '0') * (y[0] - '0');
        return to_string(prod);
    }

    string first = string(n - x.size(), '0') + x;
    string second = string(n - y.size(), '0') + y;

    int m = n / 2;

    string a = first.substr(0, n - m);
    string b = first.substr(n - m);
    string c = second.substr(0, n - m);
    string d = second.substr(n - m);

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);

    // Guass trick: we want ad+bc, we have (a+b)(c+d)=ac+ad+bc+bd
    // so we can subtract ac and bd which we have calculated earlier
    string z = karatsuba(add(a, b), add(c, d));
    string mid = sub(sub(z, ac), bd);

    string res = add(add(shift(ac, 2 * m), shift(mid, m)), bd);
    return trim(res);
}

int main()
{
    string x, y;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    cout << "Result: " << karatsuba(x, y) << endl;

    return 0;
}
