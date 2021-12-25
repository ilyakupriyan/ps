#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

template <typename T>
struct Cache {
    T data;
    unsigned int priority = 0;
};


template <class S>
class CacheList {
private:
    list<Cache<S>> array;

public:
    CacheList() {}
    ~CacheList() {}

    typename list<Cache<S>>::iterator iter;

    void sort(typename list<Cache<S>>::iterator itr) {
        //Cache<S> buffer;
        auto iter_bigger = itr;
        while (itr != array.begin()) {
            iter_bigger--;
            if (itr->priority > iter_bigger->priority) {
                swap(*iter_bigger, *itr);
            }
            else {
                break;
            } 
            itr--;
        }
    }

    S getCache(S value) {
        for (iter = array.begin(); iter != array.end(); iter++) {
            if (iter->data == value) {
                iter->priority++;
                sort(iter);
                return iter->data;
            }
        }
    }

    void add(S value) {
        Cache<S> new_cache;
        new_cache.data = value;
        array.push_back(new_cache);
    }

    void print(){
        for (iter = array.begin(); iter != array.end(); iter++) {
            cout << iter->data << ": " << iter->priority << endl;
        }
    }
};

int main() {
    CacheList<char> table;
    for (char i = 65; i <= 90; i++) {
        table.add(i);
    }
    table.getCache('A');
    table.getCache('B');
    table.getCache('C');
    table.getCache('F');
    table.getCache('G');
    table.getCache('G');
    table.getCache('G');
    table.print();

    _getch();
    return 0;
}