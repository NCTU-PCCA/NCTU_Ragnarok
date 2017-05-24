#include <bits/stdc++.h>
using namespace std;
template <typename E>
struct Node {
    E value;
    E* pointer;
};

template <class E>
struct node_ptr_less {
    bool operator()(E*& node1,
        E*& node2) const
    {
        return node1->value < node2->value;
    }
};
template <typename E>
std::vector<E> lis(const std::vector<E>& n)
{
    typedef E* NodePtr;

    std::vector<NodePtr> pileTops;
    // sort into piles
    for (typename std::vector<E>::const_iterator it = n.begin(); it != n.end(); it++) {
        NodePtr node(new Node<E>());
        node->value = *it;
        typename std::vector<NodePtr>::iterator j = std::lower_bound(pileTops.begin(), pileTops.end(), node, node_ptr_less<E>());
        if (j != pileTops.begin())
            node->pointer = *(j - 1);
        if (j != pileTops.end())
            *j = node;
        else
            pileTops.push_back(node);
    }
    // extract LIS from piles
    std::vector<E> result;
    for (NodePtr node = pileTops.back(); node != nullptr; node = node->pointer)
        result.push_back(node->value);
    std::reverse(result.begin(), result.end());
    return result;
}
int LIS(vector<int>& v)
{
    vector<int> ans;
    for (auto& i : v) {
        auto it = lower_bound(ans.begin(), ans.end(), i);
        if (ans.size() == 0 || i >= ans.back())
            ans.push_back(i);
        else {
            *it = i;
        }
    }
    return ans.size();
}
