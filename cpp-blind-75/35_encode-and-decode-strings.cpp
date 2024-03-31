// DATE: 05-Aug-2023
/* PROGRAM: 35_String - Encode and Decode Strings


Design an algorithm to encode a list of strings to a string. The encoded string is then sent over
the network and is decoded back to the original list of strings.

Please implement encode and decode

Example 1:
Input: ["lint","code","love","you"]
Output: ["lint","code","love","you"]
Explanation:
One possible encode method is: "lint:;code:;love:;you"

Example 2:
Input: ["we", "say", ":", "yes"]
Output: ["we", "say", ":", "yes"]
Explanation:
One possible encode method is: "we:;say:;:::;yes"

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res = "";
        for (string s : strs) {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &s) {
        vector<string> res;
        int i = 0, j = 0, len = 0;
        while (i < s.length()) {
            j = i;
            while (s[j] != '#') {
                j++;
            }
            len = stoi(s.substr(i, j));           // get the length of the next string
            res.push_back(s.substr(j + 1, len));  // append the next string
            i = j + 1 + len;
        }
        return res;
    }
};

// printer function to print string formatted
void printStr(vector<string> &v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << "\"" << v[i] << "\"";
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    vector<string> strs = {"lint", "code", "love", "you"};
    Solution sol;
    string en         = sol.encode(strs);
    vector<string> dc = sol.decode(en);
    printStr(strs);
    printStr(dc);

    return 0;
}
