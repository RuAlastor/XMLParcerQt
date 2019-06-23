#include "infotypes.h"

using namespace TestTask;

void RecipeName::setName(const std::string& name) noexcept {
    _name = name;
}
void RecipeName::setNewAttribute(const std::string& key, const std::string& value) noexcept {
    _attribute.insert(std::pair<std::string, std::string>(key, value));
}
void RecipeName::setText(const std::string& text) noexcept {
    _text = text;
}

void RecipeName::showInfo() noexcept {
    std::cout << "Recipe name: " << _text
              << "\nCuisine: " << _attribute["cuisine"]
              << "\nServings: " << _attribute["servings"]
              << '\n';
}


IngrList::~IngrList() {
    for (auto iter : _ingridients) {
        delete iter;
    }
}

void IngrList::setName(const std::string& name) noexcept {
    _name = name;
}
void IngrList::setIngredients(const std::string& name, const std::string& units, const std::string& unitType) noexcept(false) {
    Ingredient* tmp = new Ingredient;
    tmp->_name = name;
    tmp->_units = units;
    tmp->_unitType = unitType;
    _ingridients.push_back(tmp);
}

void IngrList::showInfo() noexcept {
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

void Utensils::setName(const std::string& name) noexcept {
    _name = name;
}
void Utensils::setUtensils(const std::string& name, const std::string& units, const std::string& unitType) noexcept(false) {
    Utensil* tmp = new Utensil;
    tmp->_name = name;
    tmp->_amount = units;
    tmp->_unitType = unitType;
    _utensils.push_back(tmp);
}

void Utensils::showInfo() noexcept {
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


void Directions::setName(const std::string& name) noexcept {
    _name = name;
}
void Directions::setSteps(const std::string& step) noexcept {
    _steps.push_back(step);
}

void Directions::showInfo() noexcept {
    std::cout << "Steps to make:\n";
    for (auto iter : _steps) {
        std::cout << iter << '\n';
    }
}


void Variations::setName(const std::string& name) noexcept {
    _name = name;
}
void Variations::setVariations(const std::string& variation) noexcept {
    _variations.push_back(variation);
}

void Variations::showInfo() noexcept {
    std::cout << "Other possible variations:\n";
    for (auto iter : _variations) {
        std::cout << iter << '\n';
    }
}


void PrepTime::setName(const std::string& name) noexcept {
    _name = name;
}
void PrepTime::setText(const std::string& text) noexcept {
    _text = text;
}

void PrepTime::showInfo() noexcept {
    std::cout << "Approximate prep time:\n"
              << _text << '\n';
}





