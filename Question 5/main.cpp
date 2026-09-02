#include <iostream>
#include <string>
#include <fstream>
#include "Aditional Library/BST.h"
#include "Aditional Library/BSTFunctions.h"

using namespace std;

// recursive autocomplete using In-Order logic to keep it alphabetical
void autocomplete(BSTNode * node, string prefix) {
    // base case: nowhere else to go
    if (isEmptyNode(node)) {
        return;
    }

    // string::substr extracts characters from index 0 to prefix length
    bool startsWith = (node->element.spanish.substr(0, prefix.length()) == prefix);

    // 1. Check left side if current word is >= prefix (or matches)
    if (node->element.spanish >= prefix || startsWith) {
        autocomplete(node->left, prefix);
    }

    // 2. Process current node: if it's a match, print it
    if (startsWith) {
        cout << node->element.spanish << " -> "
             << node->element.english << " | "
             << node->element.french << " | "
             << node->element.portuguese << endl;
    }

    // 3. Check right side if current word is < prefix (or matches)
    if (node->element.spanish < prefix || startsWith) {
        autocomplete(node->right, prefix);
    }
}

int main() {
    BST tree;
    buildTree(tree);

    // load up those files
    ifstream file1("spanish.txt", ios::in);
    ifstream file2("english.txt", ios::in);
    ifstream file3("portuguese.txt", ios::in);
    ifstream file4("french.txt", ios::in);

    if (!file1 || !file2 || !file3 || !file4) {
        cout << "Error opening files! Check your paths." << endl;
        return 1;
    }

    // read line by line until spanish file is empty
    BSTElement element;
    while (getline(file1, element.spanish)) {
        getline(file2, element.english);
        getline(file3, element.portuguese);
        getline(file4, element.french);

        insert(tree, element);
    }

    file1.close(); file2.close(); file3.close(); file4.close();

    string prefix;
    cout << "Input: ";
    cin >> prefix;
    cout << endl << "Output:" << endl;

    // start
    autocomplete(tree.root, prefix);

    return 0;
}