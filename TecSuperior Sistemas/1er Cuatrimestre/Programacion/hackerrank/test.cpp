#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumMoves(vector<int> arr1, vector<int> arr2)
{
    int minimunMoves = 0;
    int arrLength = arr1.size();

    float num = arr1[0];
    int numLength = 0;

    while (num >= 1)
    {
        numLength++;
        num = num / 10;
    }

    int evaluatedNum1, evaluatedNum2;
    int divisor;
    int mod;

    for (int i = 0; i < arrLength; i++)
    {
        evaluatedNum1 = arr1[i]; //123
        evaluatedNum2 = arr2[i];
        for (int j = 1; j <= numLength; j++)
        {
            divisor = pow(10, numLength - j);
            mod = pow(10, numLength - j + 1);

            if (j == 1)
            {
                evaluatedNum1 = evaluatedNum1 / divisor;
                evaluatedNum2 = evaluatedNum2 / divisor;
            }
            else if (j == numLength)
            {
                evaluatedNum1 = evaluatedNum1 % mod;
                evaluatedNum2 = evaluatedNum2 % mod;
            }
            else
            {
                evaluatedNum1 = (evaluatedNum1 / divisor);
                if (evaluatedNum1 >= 10)
                {
                    evaluatedNum1 %= mod;
                }
                evaluatedNum2 = (evaluatedNum2 / divisor);
                if (evaluatedNum2 >= 10)
                {
                    evaluatedNum2 %= mod;
                }
            }

            if (evaluatedNum1 >= evaluatedNum2)
            {
                minimunMoves = minimunMoves + (evaluatedNum1 - evaluatedNum2);
            }
            else
            {
                minimunMoves = minimunMoves + (evaluatedNum2 - evaluatedNum1);
            }
        }
    }
    return minimunMoves;
}

int main()
{
    vector<int> arr1(2) = {1234, 4321};
    vector<int> arr2(2) = {2345, 3214};

    int match = minimumMoves(arr1, arr2);
    cout << match << endl;
    return 0;
}
string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
