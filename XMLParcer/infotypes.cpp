#include "infotypes.h"

/* RecipeName setters */
void RecipeName::setName(const std::string& name) {
    _name = name;
}
void RecipeName::setNewAttribute(const std::string& key, const std::string& value) {
    _attribute.insert(std::pair<std::string, std::string>(key, value));
}
void RecipeName::setText(const std::string& text) {
    _text = text;
}
/* Should throw exception */
void RecipeName::setAdditionalInfo(AdditionalInfo *info) {}

/* RecipeName printer */
void RecipeName::showInfo() {
    std::cout << "GENERAL INFO\n"
              << "Dish name: " << _text << '\n'
              << "Cuisine: " << _attribute["cuisine"] << '\n'
              << "Servings: " << _attribute["servings"] << '\n';

}

/* IngrList setters */
void IngrList::setName(const std::string& name) {
    _name = name;
}
void IngrList::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}
/* Should throw exception */
void IngrList::setNewAttribute(const std::string& key, const std::string& value) {}
void IngrList::setText(const std::string& text) {}

/* IngrList printer */
void IngrList::showInfo() {
    _info->printInfo();
}


/* Utensils setters */
void Utensils::setName(const std::string& name) {
    _name = name;
}
void Utensils::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

/* Should throw exception */
void Utensils::setNewAttribute(const std::string& key, const std::string& value) {}
void Utensils::setText(const std::string& text) {}

/* Utensils printer */
void Utensils::showInfo() {
    _info->printInfo();
}

/* Direction setters */
void Directions::setName(const std::string& name) {
    _name = name;
}
void Directions::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

/* Should throw exceptions */
void Directions::setNewAttribute(const std::string& key, const std::string& value) {}
void Directions::setText(const std::string& text) {}

/* Directions printer */
void Directions::showInfo() {
    _info->printInfo();
}

/* Variations setters */
void Variations::setName(const std::string& name) {
    _name = name;
}
void Variations::setAdditionalInfo(AdditionalInfo *info) {
    _info = info;
}

/* Should throw exceptions */
void Variations::setNewAttribute(const std::string& key, const std::string& value) {}
void Variations::setText(const std::string& text) {}

/* Variation printer */
void Variations::showInfo() {
    _info->printInfo();
}

/* PrepTime setters */
void PrepTime::setName(const std::string& name) {
    _name = name;
}
void PrepTime::setText(const std::string& text) {
    _text = text;
}

/* Should throw exceptions */
void PrepTime::setAdditionalInfo(AdditionalInfo *info) {}
void PrepTime::setNewAttribute(const std::string& key, const std::string& value) {}

/* PrepTime printer */
void PrepTime::showInfo() {
    std::cout << "Approximate preparation time: " << _text << '\n';
}










