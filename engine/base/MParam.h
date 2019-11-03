//
// Created by wuwang on 19-8-31.
//

#pragma once

#include <string>

class MParam {
public:

    enum Type{
        eMPT_Uniform = 0,
        eMPT_Attribute,
        eMPT_AttributeWithBo,
        eMPT_Unknown = 0x10,
    };
    enum State{
        eMPS_UnInit,
        eMPS_ERROR,
        eMPS_OK
    };

    std::string name;
    int key{-1};
    Type type{eMPT_Unknown};
    State state{eMPS_UnInit};
    uint64_t extra{0};

public:
    explicit MParam(const char * name, Type type = eMPT_Uniform):name(name), type(type){

    }

    MParam() = default;

    bool operator<(const MParam& right) const;
    bool operator>(const MParam& right) const;
    bool operator==(const MParam& right) const;
    bool operator>=(const MParam& right) const;
    bool operator<=(const MParam& right) const;
    bool operator<(MParam& right);
    bool operator>(MParam& right);
    bool operator==(MParam& right);
    bool operator>=(MParam& right);
    bool operator<=(MParam& right);
};


