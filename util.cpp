#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> words;
    stringstream ss;
    ss << rawWords;
    string temp;
    while (!ss.fail()){
        ss >> temp;
        if (!ss.fail()){
            std::string punct = ",.-()'/?&%$#@!_[]{}\":;";
            int punctCount = 0;
            int punctA[10];
            for (int i = 0; i < (int) temp.size(); i++){
                if (punct.find(temp[i]) != std::string::npos){
                    punctA[punctCount] = i;
                    punctCount++;
                }
            }
            if (punctCount > 0){
                int last = 0;
                for (int i = 0; i < punctCount; i++){
                    std::string newWord = temp.substr(last, punctA[i]-last);
                    if ((int) newWord.size() >= 2){
                        words.insert(newWord);
                    }
                    last = punctA[i] + 1;
                }
                if (last < (int) temp.size()){
                    std::string lastWord = temp.substr(last);
                    if ((int) lastWord.size() >= 2){
                        words.insert(lastWord);
                    }
                }
            }
            else {
                words.insert(temp);
            }
        }
    }
    return words;








}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
