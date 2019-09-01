//
// Created by wuwang on 19-8-31.
//

#pragma once

#include <string>

class MParam {
public:

    enum Type{
        eMPT_UNKNOWN,
        eMPT_UNIFORM,
        eMPT_ATTRIBUTE
    };
    enum State{
        eMPS_UNINIT,
        eMPS_ERROR,
        eMPS_OK
    };

    std::string name;
    uint64_t key{0};
    Type type{eMPT_UNKNOWN};
    State state{eMPS_UNINIT};

public:
    explicit MParam(char * name):name(name){

    }

    bool operator<(MParam& right);
    bool operator>(MParam& right);
    bool operator==(MParam& right);
    bool operator>=(MParam& right);
    bool operator<=(MParam& right);
};


