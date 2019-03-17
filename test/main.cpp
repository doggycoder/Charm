#include <utility>

//
// Created by wuwang on 19-1-18.
//
#include "basics/VectorTest.h"
#include "base/Random.h"
#include "base/Base.h"

class Name{
public:
    std::string m;
    Name(std::string name){
        m = std::move(name);
    }
};

void changeName(Name ** a){
    delete *a;
}

int main(){
    Name * name = new Name("hello");
    std::cout<<"name addr:"<<name<<std::endl;
    std::cout<<"program start:"<<std::endl;
    {
        SPtr<Name> A;
        std::cout<<"count:"<<A.count()<<std::endl;
        {
            A = SPtr<Name>(name);
        }
        std::cout<<"count:"<<A.count()<<std::endl;
        std::cout<<"count:"<<A->m<<std::endl;
    }

    std::vector<Name*> names;
    Name n("Hello You First");
    std::cout<<"Name Addr:"<< &n<<std::endl;
    names.push_back(&n);
    std::cout<<"Name Addr:"<< names[0]<<std::endl;
    std::cout<<"Name Addr:"<< names.back()<<std::endl;
    std::cout<<"Name Addr:"<< names.back()<<std::endl;
    Name B("Fad");
    names.push_back(&B);
    std::cout<<"Name Addr:"<< names[0]<<std::endl;
    std::cout<<"Name Addr:"<< names[1]<<std::endl;

    Name * test = new Name("Hell Name");
    changeName(&test);

    std::cout<<"Name Addr:"<< test<<std::endl;

    return 0;
}