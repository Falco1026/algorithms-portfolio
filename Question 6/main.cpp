#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// helper function to check if the word matches exactly at this text index
bool checkMatch(const char * text, const char * word, int tIdx, int wIdx) {
    // if we successfully reached the end of 'word'
    if (word[wIdx] == '\0') {
        // it's a full word ONLY if the text also has a space here or ends
        return text[tIdx] == ' ' || text[tIdx] == '\0';
    }

    // if text ended early, or letters don't match, return false
    if (text[tIdx] == '\0' || text[tIdx] != word[wIdx]) {
        return false;
    }

    // check the next letter recursively
    return checkMatch(text, word, tIdx + 1, wIdx + 1);
}

// main recursive function to traverse the text
int countWords(const char * text, const char * word, int tIdx) {
    // base case: end of the text
    if (text[tIdx] == '\0') {
        return 0;
    }

    // we only check for a match if we are standing at the start of a word
    bool isStartOfWord = (tIdx == 0) || (text[tIdx - 1] == ' ');

    if (isStartOfWord && checkMatch(text, word, tIdx, 0)) {
        // found an exact match! add 1 and keep moving forward
        return 1 + countWords(text, word, tIdx + 1);
    } else {
        // no match here, just keep moving forward
        return countWords(text, word, tIdx + 1);
    }
}

int main() {
    char text1[100] = "hola mundo hola amigos hola";
    char text2[100] = "hola mundo hola holanda";
    char word[20] = "hola";

    cout << left << setw(40) << "TEXTO" << setw(20) << "PALABRA" << setw(20) << "SALIDA" << endl;

    // test case 1
    int count1 = countWords(text1, word, 0);
    cout << left << setw(40) << text1 << setw(20) << word << setw(20) << count1 << endl;

    // test case 2
    int count2 = countWords(text2, word, 0);
    cout << left << setw(40) << text2 << setw(20) << word << setw(20) << count2 << endl;

    return 0;
}