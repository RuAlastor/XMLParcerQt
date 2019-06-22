#include "additionalinfo.h"

void IngrAdditionalInfo::setNewText(const std::string& text) {
    _itemNames.push_back(text);
}
void IngrAdditionalInfo::setNewMeasures(const std::string& units, const std::string& unitType) {
    _units.push_back(units);
    _unitType.push_back(unitType);
}
void IngrAdditionalInfo::printInfo() {
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
