#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
#include<vector>
template<typename T>
struct Node{
    Node *pre;
    T value;
    Node *next;

    Node(T value):value{value},pre{nullptr},next{nullptr}{}
   
};
template<typename T>
class list{
private:
    Node<T> *first;
public:
    list();
    list(std::vector<T> vec);
    void display();
    Node<T> *begin();
    Node <T> *end();
    int size();
    void push_back(T value);
    void insert(int index,T value);
    void Delete(int index);

    ~list();

};
#endif //_LIST_H_ 