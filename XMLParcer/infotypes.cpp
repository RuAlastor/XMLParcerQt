#include "infotypes.h"


InfoTypes::~InfoTypes() {}


void RecipeName::setName(const std::string& name) {
    _name = name;
}
void RecipeName::setNewAttribute(const std::string& key, const std::string& value) {
    _attribute.insert(std::pair<std::string, std::string>(key, value));
}
void RecipeName::setText(const std::string& text) {
    _text = text;
}

void RecipeName::setAdditionalInfo(AdditionalInfo *info) {}

void RecipeName::showInfo() {
    std::cout << "GENERAL INFO\n"
              << "Dish name: " << _text << '\n'
              << "Cuisine: " << _attribute["cuisine"] << '\n'
              << "Servings: " << _attribute["servings"] << '\n';

}


IngrList::IngrList() : _name(""), _info(nullptr) {}
IngrList::~IngrList() {
    delete _info;
}

void IngrList::setName(const std::string& name) {
    _name = name;
}
void IngrList::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

void IngrList::setNewAttribute(const std::string& key, const std::string& value) {}
void IngrList::setText(const std::string& text) {}

void IngrList::showInfo() {
    _info->printInfo();
}


Utensils::Utensils() : _name(""), _info(nullptr) {}
Utensils::~Utensils() {
    delete _info;
}

void Utensils::setName(const std::string& name) {
    _name = name;
}
void Utensils::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

void Utensils::setNewAttribute(const std::string& key, const std::string& value) {}
void Utensils::setText(const std::string& text) {}

void Utensils::showInfo() {
    _info->printInfo();
}


Directions::Directions() : _name(""), _info(nullptr) {}
Directions::~Directions() {
    delete _info;
}

void Directions::setName(const std::string& name) {
    _name = name;
}
void Directions::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

void Directions::setNewAttribute(const std::string& key, const std::string& value) {}
void Directions::setText(const std::string& text) {}

void Directions::showInfo() {
    _info->printInfo();
}


Variations::Variations()  : _name(""), _info(nullptr) {}
Variations::~Variations() {
    delete _info;
}

void Variations::setName(const std::string& name) {
    _name = name;
}
void Variations::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

void Variations::setNewAttribute(const std::string& key, const std::string& value) {}
void Variations::setText(const std::string& text) {}

void Variations::showInfo() {
    _info->printInfo();
}


void PrepTime::setName(const std::string& name) {
    _name = name;
}
void PrepTime::setText(const std::string& text) {
    _text = text;
}

void PrepTime::setAdditionalInfo(AdditionalInfo *info) {}
void PrepTime::setNewAttribute(const std::string& key, const std::string& value) {}

void PrepTime::showInfo() {
    std::cout << "Approximate preparation time: " << _text << '\n';
}










