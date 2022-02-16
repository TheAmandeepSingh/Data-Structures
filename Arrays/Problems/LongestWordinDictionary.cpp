/**
 * Given a string "atdoer" and a dictionary {"to", "toe", "top"}, in this case answer will be "toe",
 * what is the maximum length word that can be formed using the letters in the string,
 * and that word must be present in dictionary as well.
 *
 *                                          OR
 *
 * Given a string s and a string array dictionary, return the longest string in the dictionary
 * that can be formed by deleting some of the given string characters.
 * If there is more than one possible result, return the longest word with the smallest
 * lexicographical order. If there is no possible result, return the empty string.
 *
 * Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * Output: "apple"
 * Input: s = "abpcplea", dictionary = ["a","b","c"]
 * Output: "a"
 **/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string &getSmallestLexicographicalWord(string &x, string &y)
{
    for (int i = 0; i < x.length(); ++i)
    {
        if (x[i] == y[i])
        {
            continue;
        }
        else if (x[i] > y[i])
        {
            return y;
        }
        else
        {
            return x;
        }
    }
    return x;
}

bool isSubsequence(const string &s, const string &word)
{
    int j = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == word[j])
        {
            ++j;
        }
    }

    return j == word.length();
}

string findLongestWord(const string &s, vector<string> &dictionary)
{
    string longestWord("");

    for (auto word : dictionary)
    {
        if (isSubsequence(s, word))
        {
            if (word.length() > longestWord.length())
            {
                longestWord = word;
            }
            else if (word.length() == longestWord.length())
            {
                longestWord = getSmallestLexicographicalWord(word, longestWord);
            }
        }
    }

    return longestWord;
}

int main()
{
    string s("abpcplea");
    //vector<string> dictionary {"ale","apple","monkey","plea"};
    vector<string> dictionary {"b","a","c","d"};

    cout<<"Longest word: " << findLongestWord(s, dictionary) << endl;
}