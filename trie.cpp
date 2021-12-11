#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Trie
{
    T data;
    vector<Trie *> childrens;
    Trie<T> *search(const string &key);
    T &insert(const string &key, const T &data);

public:
    Trie();
    T &operator[](const string &key);
    ~Trie();
};

template <typename T>
Trie<T>::Trie()
{
    data = T();
    childrens = vector<Trie *>(26, nullptr);
}

template <typename T>
T &Trie<T>::insert(const string &key, const T &data)
{
    int idx = 0;
    Trie *node = this;
    while (idx < key.size() && (node->childrens)[key[idx] - 'a'] != nullptr)
    {
        node = (node->childrens)[key[idx] - 'a'];
        idx++;
    }

    while (idx < key.size())
    {
        (node->childrens)[key[idx] - 'a'] = new Trie();
        node = (node->childrens)[key[idx] - 'a'];
        idx++;
    }

    node->data = data;
    return node->data;
}

template <typename T>
Trie<T> *Trie<T>::search(const string &key)
{
    int idx = 0;
    auto node = this;

    while (idx < key.size())
    {
        if ((node->childrens)[key[idx] - 'a'] == nullptr)
            return nullptr;
        node = (node->childrens)[key[idx] - 'a'];
        idx++;
    }

    return node;
}

template <typename T>
Trie<T>::~Trie()
{
    for (int i = 0; i < childrens.size(); i++)
        if (childrens[i] != nullptr)
        {
            delete childrens[i];
            childrens[i] = nullptr;
        }
}

template <typename T>
T &Trie<T>::operator[](const string &key)
{
    auto ptr = search(key);
    if (ptr == nullptr)
        return insert(key, T());

    return ptr->data;
}

int main()
{
    auto pairTrie = Trie<pair<int, int>>();
    pairTrie["abc"] = {1, 2};
    pairTrie["abc"] = {2, 3};
    cout << pairTrie["abc"].first << " " << pairTrie["abc"].second << endl;
    pairTrie["adb"] = {4, 5};
    pairTrie["adb"] = {5, 6};
    cout << pairTrie["abcd"].first << " " << pairTrie["abcd"].second << endl;

    auto stringTrie = Trie<string>();
    stringTrie["abc"] = "chihuahua";
    stringTrie["abc"] = "hello";
    cout << stringTrie["abc"] << endl;
    stringTrie["adb"] = "woof";
    stringTrie["adb"] = "world";
    cout << stringTrie["abcd"] << endl;

    return 0;
}