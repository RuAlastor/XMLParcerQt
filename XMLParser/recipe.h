#ifndef RECIPE_H
#define RECIPE_H

#include "newrecipeinfo.h"


namespace TestTask {

    class Recipe {

    public:
        Recipe() noexcept(false);
        ~Recipe() noexcept = default;

        Recipe(const Recipe& other) = delete;
        Recipe(Recipe&& other) = delete;
        Recipe& operator=(const Recipe& other) = delete;
        Recipe& operator=(Recipe&& other) = delete;

        void setType(const std::string& type) noexcept;
        void setNewRecipePart(InfoTypes* recipePart) noexcept;

        void showRecipe() const noexcept;

    private:
        std::string _type;
        std::list<InfoTypes*> _recipeParts;

    };

}
#endif // RECIPE_H
