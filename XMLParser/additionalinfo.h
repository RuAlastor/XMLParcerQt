#ifndef ADDITIONALINFO_H
#define ADDITIONALINFO_H

#include "headers.h"

namespace TestTask {

    struct Ingredient {
        std::string _name;
        std::string _units;
        std::string _unitType;
    };

    struct Utensil {
        std::string _name;
        std::string _amount;
        std::string _unitType;
    };

}


#endif // ADDITIONALINFO_H
