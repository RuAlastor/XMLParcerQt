#include "recipe.h"

using namespace TestTask;

Recipe::Recipe() noexcept(false) : _type("") {}
Recipe::~Recipe() noexcept {
    for (auto iter : _recipeParts) {
        delete iter;
    }
}


void Recipe::setType(const std::string& type) noexcept {
    _type = type;
}

void Recipe::setNewRecipePart(InfoTypes *recipePart) noexcept {
    _recipeParts.push_back(recipePart);
}


void Recipe::showRecipe() const noexcept {
    std::cout << "Recipe type: " << _type << '\n';
    if (_recipeParts.empty()) {
        std::cout << "Recept is empty.\n";
    }
    else {
        for (auto iter : _recipeParts) {
            iter->showInfo();
        }
    }
}
