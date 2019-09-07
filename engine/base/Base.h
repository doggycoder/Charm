//
// Created by wuwang on 18-12-23.
//

#ifndef _CHARM_BASE_H_
#define _CHARM_BASE_H_

#include <memory>

#define byte unsigned char

template <typename T>
class SPtr{
public:
    template <typename A>
    class Ptr{
    private:
        friend class SPtr<A>;
        A * t;
        int count;

        explicit Ptr(A * t):t(t),count(1){}
        ~Ptr(){delete t;}
    };
private:
    Ptr<T> * realPointer{nullptr};
public:
    SPtr() = default;
    explicit SPtr(T * p):realPointer(new Ptr<T>(p)){};
    SPtr(SPtr<T> &t):realPointer(t.realPointer){
        ++realPointer->count;
    }

    SPtr<T>& operator=(const SPtr<T> &t){
        ++t.realPointer->count;
        if (realPointer && --realPointer->count <= 0)
            delete realPointer;
        realPointer = t.realPointer;
        return *this;
    }

    SPtr<T>&operator=(T * t){
        if (realPointer && --realPointer->count <= 0)
            delete realPointer;
        realPointer = new Ptr<T>(t);
    }

    ~SPtr(){
        if(realPointer){
            if(--realPointer->count <= 0){
                delete realPointer;
            }
        }
    }

    T *operator->(){
        return (realPointer->t);
    }

    T &operator*(){
        return *(realPointer->t);
    };

    explicit operator bool(){
        return realPointer == nullptr || realPointer->t == nullptr;
    }

    int count(){
        if(realPointer){
            return realPointer->count;
        }
        return 0;
    }


};

#endif //_CHARM_BASE_H_
