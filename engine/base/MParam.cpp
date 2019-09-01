//
// Created by wuwang on 19-8-31.
//

#include "MParam.h"


bool MParam::operator<(MParam &right) {
    return name.compare(right.name) < 0;
}

bool MParam::operator>(MParam &right) {
    return name.compare(right.name) > 0;
}

bool MParam::operator==(MParam &right) {
    return name == right.name;
}

bool MParam::operator>=(MParam &right) {
    return name.compare(right.name) >= 0;
}

bool MParam::operator<=(MParam &right) {
    return name.compare(right.name) <= 0;
}