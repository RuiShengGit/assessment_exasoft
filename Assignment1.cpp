// Assignment 1

// PROBLEM DEFINITION
// ------------------
// Reverse each word in the input string.
// The order of the words will be unchanged.
// A word is made up of letters and/or numbers.
// Other characters (spaces, punctuation) will not be reversed.
// NOTES
// ------
// Write production quality code
// We prefer clarity over performance (though if you can achieve both - great!)
// You can use the language that best highlights your programming ability
// the template below is in C++
// A working solution is preferred (assert in main() should succeed)
// Bonus points for good tests
#include <string>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <iostream>
std::string reverse_words(const std::string &str){
    // TODO: Implement this function
    std::string result = str;
    int n = result.size();
    int start = 0;
    int i = 0;

    while (i < n)
    {
        if (std::isalnum(result[i]))
        {
            int start = i;

            while (i < n && std::isalnum(result[i]))
            {
                i++;
            }
            std::reverse(result.begin() + start, result.begin() + i);
        }
        else
        {
            i++;
        }
    }

    return result;
}

int main(){
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    assert(reverse_words(" ") == " ");
    assert(reverse_words("a1b2") == "2b1a");
    assert(reverse_words("Hello, world!") == "olleH, dlrow!");
    assert(reverse_words("123456") == "654321");
    assert(reverse_words("Mix3d W0rd5!") == "d3xiM 5dr0W!");
    assert(reverse_words("") == "");
    std::cout << "All tests passed!\n";
    return 0;
}
