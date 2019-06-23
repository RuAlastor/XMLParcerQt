#include "additionalinfo.h"

AdditionalInfo::~AdditionalInfo() {}


void IngrAndUtensilsAdditionalInfo::setNewText(const std::string& text) {
    _itemNames.push_back(text);
}
void IngrAndUtensilsAdditionalInfo::setNewMeasures(const std::string& units, const std::string& unitType) {
    _units.push_back(units);
    _unitType.push_back(unitType);
}

void IngrAndUtensilsAdditionalInfo::printInfo() {
    auto iterNames = _itemNames.begin();
    auto iterUnits = _units.begin();
    auto iterUnitTypes = _unitType.begin();
    std::cout << "YOU WILL NEED:\n";
    for (size_t i = 0; i < _itemNames.size(); i++) {
        if (*iterUnitTypes == "each") {
            std::cout << *iterUnits << ' ' << *iterNames << '\n';
        }
        else {
            std::cout << *iterUnits << ' ' << *iterUnitTypes << " of " << *iterNames << '\n';
        }
        iterNames++;
        iterUnits++;
        iterUnitTypes++;
    }
}


void DirectionsAdditionalInfo::setNewText(const std::string& text) {
    _steps.push_back(text);
}

void DirectionsAdditionalInfo::setNewMeasures(const std::string& units, const std::string& unitType) {}

void DirectionsAdditionalInfo::printInfo() {
    std::cout << "DIRECTIONS:\n";
    int i = 0;
    for (auto iter : _steps) {
        std::cout << "Step " << ++i << ": " << iter << '\n';
    }
}


void VariationsAdditionalInfo::setNewText(const std::string& text) {
    _variants.push_back(text);
}

void VariationsAdditionalInfo::setNewMeasures(const std::string& units, const std::string& unitType) {}

void VariationsAdditionalInfo::printInfo() {
    std::cout << "OTHER VARIANTS:\n";
    int i = 0;
    for (auto iter : _variants) {
        std::cout << ++i << ". " << iter << '\n';
    }
}
































