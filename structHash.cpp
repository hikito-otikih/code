#include <iostream>
#include <vector>

using namespace std;

struct HashTable
{
    int *table;
    bool *flag;
    int p;
    HashTable(int _p = 0)
    {
        p = _p;
        table = new int[p];
        flag = new bool[p];
        for (int i = 0; i < p; i++) flag[i] = false;
    }
    bool insert(int x)
    {
        int i = x % p;
        int j = i;
        while (flag[j])
        {
            j = (j + 1) % p;
            if (j == i) return 0;
        }
        table[j] = x;
        flag[j] = true;
        return 1;
    }
    int findX(int x)
    {
        int i = x % p;
        int j = i;
        while (flag[j] && table[j] != x)
        {
            j = (j + 1) % p;
            if (j == i) return -1;
        }
        if (flag[j]) return j;
        else return -1;
    }
    bool remove(int x)
    {
        int i = findX(x);
        if (i != -1)
        {
            flag[i] = false;
            return 1;
        }
        return 0;
    }
    ~HashTable()
    {
        delete[] table;
        delete[] flag;
    }
};

int main()
{
    /*HashTable h(5);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(5);
    h.insert(7);

    cout << h.findX(1) << endl;
    cout << h.findX(2) << endl;
    cout << h.findX(5) << endl;
    h.remove(5);
    cout << h.findX(5) << endl;*/
    return 0;
}