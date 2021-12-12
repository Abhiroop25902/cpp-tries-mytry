#include <bits/stdc++.h>
#include "trie.h"
using namespace std;
int main()
{
    auto pairTrie = Trie<pair<int, int>>();
    pairTrie["abc"] = {1, 2};
    pairTrie["abc"] = {2, 3};
    cout << pairTrie["abc"].first << " " << pairTrie["abc"].second << endl;
    pairTrie["adb"] = {4, 5};
    pairTrie["adb"] = {5, 6};
    pairTrie.erase("adb");
    cout << pairTrie["abcd"].first << " " << pairTrie["abcd"].second << endl;
    cout << pairTrie["adb"].first << " " << pairTrie["adb"].second << endl;

    auto stringTrie = Trie<string>();
    stringTrie["ball"] = "red ball";
    stringTrie["bat"] = "mrf bat";
    stringTrie["bear"] = "brown bear";
    stringTrie["bell"] = "golden bell";
    stringTrie["bored"] = "yes I am";
    stringTrie["stack"] = "balanced parenthesis";
    stringTrie["stock"] = "AAPL";
    stringTrie["stop"] = "yes, please";
    cout << stringTrie["stock"] << endl;
    stringTrie.erase("stock");
    cout << stringTrie["stock"] << endl;
    cout << stringTrie["abc"] << endl;

    return 0;
}