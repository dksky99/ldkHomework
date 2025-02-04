

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

//stack, queue
/*
    stack : 선입후출-> FILO : 팬케이크
    Queue :  선입선출 -> FIFO : 줄서는것



*/
using namespace std;

template<typename T, typename Container=vector<T>>
class Stack
{
public:
    void push(T n) { data.push_back(n); }
    T top() { return data.back(); }
    void pop() { data.pop_back(); }
    bool empty() { return data.empty(); }
    void clear() { data.clear(); }

private:
    
    Container data;
    

};


int main()
{
    stack<int> s;

    s.push(10);
    s.push(1);
    s.push(15);
    s.push(6);
    s.push(100);

    while (true)
    {
        if (s.empty() == true)
        {
            break;
        }
        cout << s.top() << endl;
        s.pop();
    }
    return 0;

}