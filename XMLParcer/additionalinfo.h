#ifndef ADDITIONALINFO_H
#define ADDITIONALINFO_H

#include <string>
#include <list>
#include <iterator>
#include <iostream>

class AdditionalInfo {

public:
    virtual void setNewText(const std::string& text) = 0;
    virtual void setNewMeasures(const std::string& units, const std::string& unitType) = 0;

    virtual void printInfo() = 0;

};

class IngrAdditionalInfo : public AdditionalInfo {

private:
    std::list<std::string> _itemNames;
    std::list<std::string> _units;
    std::list<std::string> _unitType;

public:
    void setNewText(const std::string& text);
    void setNewMeasures(const std::string& units, const std::string& unitType);

    void printInfo();

};

#endif // ADDITIONALINFO_H
