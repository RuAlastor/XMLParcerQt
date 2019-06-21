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
void RecipeName::setAdditionalInfo(const AdditionalInfo *info) {}

void RecipeName::showInfo() {
    std::cout << "GENERAL INFO\n"
              << "Dish name: " << _text << '\n'
              << "Cuisine: " << _attribute["cuisine"] << '\n'
              << "Servings: " << _attribute["servings"] << '\n';

}
