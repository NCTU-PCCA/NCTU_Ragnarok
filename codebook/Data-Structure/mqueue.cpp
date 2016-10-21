template <typename Item>
struct mqueue {
    deque<Item> data, aux;
    void push(Item& x)
    {
        data.push_back(x);
        while (!aux.empty() && aux.back() < x)
            aux.pop_back();
        aux.push_back(x);
    }
    void pop()
    {
        if (data.front() == aux.front())
            aux.pop_front();
        data.pop_front();
    }
    int size()
    {
        return data.size();
    }
    Item max()
    {
        return aux.front();
    }
};
