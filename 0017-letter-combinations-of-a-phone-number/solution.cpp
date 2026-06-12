class Solution {
public:
    vector<string> result;
    void backtrack(string& digits, int index, unordered_map<int, string>& myMap, string current){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for(char ch: myMap[digit]){
            backtrack(digits, index+1, myMap, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};


        unordered_map<int, string> myMap;
        myMap[2] = "abc";
        myMap[3] = "def";
        myMap[4] = "ghi";
        myMap[5] = "jkl";
        myMap[6] = "mno";
        myMap[7] = "pqrs";
        myMap[8] = "tuv";
        myMap[9] = "wxyz";

        backtrack(digits, 0, myMap, "");

        return result;
    }
};
