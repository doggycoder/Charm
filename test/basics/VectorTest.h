#include <utility>

//
// Created by wuwang on 19-1-18.
//

#ifndef CHARM_VECTORTEST_H
#define CHARM_VECTORTEST_H

#include <vector>
#include <string>
#include <iostream>


class VectorTest {
private:
    std::vector<int> data;
    void info(){
        std::cout<<"size:"<<data.size()<<",cap:"<<data.capacity()<<std::endl;
        for (auto d:data) {
            std::cout<<d<<",";
        }
        std::cout<<std::endl;
    }
public:
    void addData(int id){
        data.push_back(id);
        info();
    }

    void popData(){
        data.pop_back();
        info();
    }

    void eraseData(int pos){
        auto d = data.begin() + pos;
        data.erase(d);
        info();
    }


    void test(){
        addData(1);
        addData(2);
        addData(3);
        addData(4);
        addData(5);
        addData(6);
        popData();
        eraseData(2);
    }
};


#endif //CHARM_VECTORTEST_H
