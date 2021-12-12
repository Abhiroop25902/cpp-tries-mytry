#ifndef TRIE
#define TRIE
// Had to include all code here due to templates, compiler creates typebased code from this template so all of the code's presence is required
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Trie
{
    T data;
    vector<Trie *> childrens;
    Trie<T> *search(const string &key);
    T &insert(const string &key, const T &data);
    static bool onlyOneNotNull(Trie<T> *node);

public:
    Trie();
    /**
     * @brief overloaded subscript operator that can be used to refer existing data and also create new entries for the trie
     * 
     * @param key the string key
     * @return T& -> the reference to the data created or retrieved
     */
    T &operator[](const string &key);
    /**
     * @brief deletes the data with the give key value, does not throw excpetion if key is not present
     * 
     * @param key 
     */
    void erase(const string &key);
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
bool Trie<T>::onlyOneNotNull(Trie<T> *node)
{
    int notNullCount = 0;
    for (auto ptr : node->childrens)
        if (ptr != nullptr)
            notNullCount++;

    return notNullCount == 1;
}

template <typename T>
T &Trie<T>::operator[](const string &key)
{
    auto ptr = search(key);
    if (ptr == nullptr)
        return insert(key, T());

    return ptr->data;
}

template <typename T>
void Trie<T>::erase(const string &key)
{
    if (search(key) == nullptr)
        return;

    int idx = 0;
    auto node = this;

    while (idx < key.size() && !onlyOneNotNull(node))
    {
        node = (node->childrens)[key[idx] - 'a'];
        idx++;
    }

    delete (node->childrens)[key[idx] - 'a'];
    (node->childrens)[key[idx] - 'a'] = nullptr;
}

#endif