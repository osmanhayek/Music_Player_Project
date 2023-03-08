#include "list.h"

template<typename T>
list<T>::list(){
    this->first=new Node(0);
    this->first->next=this->first;
    this->first->pre=nullptr;
}
template<typename T>
list<T>::list(std::vector<T> vec){
    this->first=new Node(vec.at(0));
    this->first->next=this->first;
    this->first->pre=this->first;
    Node<T> *last=first;
    for(int i=1;i<vec.size();i++){
        Node<T> *q=new Node(vec.at(i));
        q->next=first;
        q->pre=last;
        last->next=q;
        first->pre=q;
        last=q;
    }
}
template<typename T>
list<T>::~list(){
    Node<T> *p=first;
    int n=this->size();
    for(int i=0;i<n;i++){
        first=first->next;
        delete p;
        p=first;
    }
}
template<typename T>
void list<T>::display(){
    Node<T> *p=first;
    do{
        std::cout<<p->value;
        p=p->next;
    }while(p!=first);
}

template<typename T>
Node<T> *list<T>::begin(){
    return first;
}
template<typename T>
Node<T> *list<T>::end(){
    return first->pre;
}

template<typename T>
void list<T>::push_back(T value){
    Node<T> *last=first->pre;
    Node<T> *q=new Node(value);
    last->next=q;
    q->pre=last;
    q->next=first;
    first->pre=q;
}
template<typename T>
int list<T>::size(){
    int x=0;
    Node<T> *p=first;
    do{
        x++;
        p=p->next;
    }while(p!=first);
    return x;
}

template<typename T>
void list<T>::insert(int index,T value){
    if(index==0){
        Node<T> *nw=new Node(value);
        nw->next=first;
        nw->pre=first->pre;
        first->pre->next=nw;
        first->pre=nw;
        first=nw;
    }
    else if(index==this->size()){
        Node<T> *nw=new Node(value);
        first->pre->next=nw;
        nw->next=first;
        nw->pre=first->pre;
        first->pre=nw;
    }
    else if(index>0&&index<this->size()){
        Node<T> *p=first;
        for(int i=0;i<index-1;i++)p=p->next;
        Node<T> *nw=new Node(value);
        nw->next=p->next;
        nw->pre=p;
        p->next->pre=nw;
        p->next=nw;
        
    }
    else return;
}

template<typename T>
void list<T>::Delete(int index){
    if(index==1){
        Node<T> *p=first;
        p->pre->next=first->next;
        first->next->pre=p->pre;
        first=first->next;
        delete p;
        
    }
    else if(index==this->size()){
        Node<T> *p=first->pre;
        p->pre->next=first;
        first->pre=p->pre;
        delete p;
    }
    else if(index>1&&index<this->size()){
        Node<T> *p=first;
        for(int i=0;i<index-1;i++)p=p->next;
        p->pre->next=p->next;
        p->next->pre=p->pre;
        delete p;
    }
    else return;
}

