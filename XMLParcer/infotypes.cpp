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
