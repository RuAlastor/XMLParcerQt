#ifndef ADDITIONALINFO_H
#define ADDITIONALINFO_H

#include <string>
#include <list>
#include <iterator>
#include <iostream>

class AdditionalInfo {

    /*
     * if parced node has /measures/ parameters
     * then /text/ is considered to be /units/
     * /measures/ are filled accordingly
     *
     * otherwise
     * /text/ is considered to be /text/
     * and class doesn't have /measures/ fields
    */

public:
    virtual void setNewText(const std::string& text) = 0;
    virtual void setNewMeasures(const std::string& units, const std::string& unitType) = 0;

    virtual void printInfo() = 0;

    virtual ~AdditionalInfo();

};

class IngrAndUtensilsAdditionalInfo : public AdditionalInfo {

private:
    std::list<std::string> _itemNames;
    std::list<std::string> _units;
    std::list<std::string> _unitType;

public:
    void setNewText(const std::string& text);
    void setNewMeasures(const std::string& units, const std::string& unitType);

    void printInfo();

};

class DirectionsAdditionalInfo : public AdditionalInfo {

private:
    std::list<std::string> _steps;

    /* Should throw exceptions */
    void setNewMeasures(const std::string& units, const std::string& unitType);

public:
    void setNewText(const std::string& text);

    void printInfo();

};

class VariationsAdditionalInfo : public AdditionalInfo {

private:
    std::list<std::string> _variants;

    /* Should throw exceptions */
    void setNewMeasures(const std::string& units, const std::string& unitType);

public:
    void setNewText(const std::string& text);

    void printInfo();

};

#endif // ADDITIONALINFO_H
