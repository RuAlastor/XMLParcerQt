#include "infotypes.h"

using namespace TestTask;


void RecipeName::showInfo() const noexcept {
    std::cout << "Recipe name: " << _text;
    auto iter = _attribute.find("cuisine");
    std::cout << "\nCuisine: " << iter->second;
    iter = _attribute.find("servings");
    std::cout << "\nServings: " << iter->second << '\n';
}


IngrList::~IngrList() {
    for (auto iter : _ingridients) {
        delete iter;
    }
}
void IngrList::setIngredients(const std::string& name, const std::string& units, const std::string& unitType) noexcept(false) {
    Ingredient* tmp = new Ingredient;
    tmp->_name = name;
    tmp->_units = units;
    tmp->_unitType = unitType;
    _ingridients.push_back(tmp);
}
void IngrList::showInfo() const noexcept {
    std::cout << "Ingredients:\n";
    for (auto iter : _ingridients) {
        if (iter->_unitType == "each") {
            std::cout << iter->_units << ' ' << iter->_name << '\n';
        }
        else {
            std::cout << iter->_units << ' ' << iter->_unitType << " of " << iter->_name << '\n';
        }
    }
}


Utensils::~Utensils() {
    for (auto iter : _utensils) {
        delete iter;
    }
}
void Utensils::setUtensils(const std::string& name, const std::string& amount, const std::string& unitType) noexcept(false) {
    Utensil* tmp = new Utensil;
    tmp->_name = name;
    tmp->_amount = amount;
    tmp->_unitType = unitType;
    _utensils.push_back(tmp);
}
void Utensils::showInfo() const noexcept {
    std::cout << "Utensils:\n";
    for (auto iter : _utensils) {
        if (iter->_unitType == "each") {
            std::cout << iter->_amount << ' ' << iter->_name << '\n';
        }
        else {
            std::cout << iter->_amount << ' ' << iter->_unitType << " of " << iter->_name << '\n';
        }
    }
}


void Directions::showInfo() const noexcept {
    std::cout << "Steps to make:\n";
    for (auto iter : _steps) {
        std::cout << iter << '\n';
    }
}


void Variations::showInfo() const noexcept {
    std::cout << "Other possible variations:\n";
    for (auto iter : _variations) {
        std::cout << iter << '\n';
    }
}


void PrepTime::showInfo() const noexcept {
    std::cout << "Approximate prep time:\n"
              << _text << '\n';
}





