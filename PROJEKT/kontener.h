#ifndef KONTENER_H
#define KONTENER_H
#include <iostream>
#include <string.h>
#include  <string>
using namespace std;
template<typename T,typename U>class Kontener
{
private:
    T _size;
    U *_wsk;
public:
    Kontener(T size=0):_size(size),_wsk(new U[size] ) {}
    void push_back(U val);
    void push_front(U val);
    void insert(unsigned index,U val);
    U show(unsigned index);
    U& operator[](unsigned index);
    int size(){
        return _size;
    }
    int length(unsigned index);
    virtual ~Kontener();
};
template<typename T,typename U>void Kontener <T,U>::push_back(U val)
{
    if(this->_size==0){
        ++_size;
        _wsk = new U[_size];
        _wsk[0]=val;
    }
    else{
        U *temp=new U[++_size];
        int i=0;
        for(i; i<_size-1; ++i)
            temp[i]=_wsk[i];
        temp[i]=val;
        if(_size-1>0 &&_wsk!=nullptr){
            delete []_wsk;
            _wsk = nullptr;
        }
        else{
            delete _wsk;
            _wsk =nullptr;
        }
        _wsk=temp;
    }
}
template<typename T,typename U>void Kontener<T,U>::push_front(U val)
{
    if(this->_size==0){
        _wsk = new U(val);
        ++_size;
    }
    else{
        U* temp=new U[++_size];
        temp[0]=val;
        unsigned i=1;
        for(i; i<_size; i++)
            temp[i]=_wsk[i-1];
        if(_size-1>0 &&_wsk!=nullptr){
            delete []_wsk;
            _wsk = nullptr;
        }
        else{
            delete _wsk;
            _wsk =nullptr;
        }
        _wsk=temp;
    }
}
template<typename T,typename U>void Kontener<T,U>::insert(unsigned index,U val)
{
    if(index>=_size){
        cout<<endl<<"Error: Wrong value: "<<index<<endl;
    }
    else{
        this->_wsk[index]=val;
    }
}
template<typename T,typename U>U Kontener<T,U>::show(unsigned index)
{
    if(index>=_size){
        cout<<endl<<"Error: Wrong value: "<<index<<endl;
    }
    else
        return _wsk[index];
}
template<typename T,typename U>U& Kontener<T,U>::operator[](unsigned index)
{
    if(!(index>=_size))
        return _wsk[index];
    else{
        cout<<"Wrong data: "<<index<<endl;
    }
}
template<typename T,typename U>int Kontener<T,U>::length(unsigned index)
{
    return _wsk[index].length();
}
template<typename T,typename U>   Kontener<T,U>::~Kontener()
{
    if(_size-1>0 &&_wsk!=nullptr){
        delete []_wsk;
        _wsk = nullptr;
    }
    else{
        delete _wsk;
        _wsk =nullptr;
    }
}
#endif // KONTENER_H
