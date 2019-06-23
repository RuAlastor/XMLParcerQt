#include "infotypes.h"

using namespace TestTask;

void RecipeName::setName(const std::string& name) noexcept {
    _name = name;
}void RecipeName::setNewAttribute(const std::string& key, const std::string& value) noexcept {
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
