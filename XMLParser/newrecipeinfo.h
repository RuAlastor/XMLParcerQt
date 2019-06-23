#ifndef NEWRECIPEINFO_H
#define NEWRECIPEINFO_H

#include "infotypes.h"

namespace TestTask {

    class NewRecipeInfo {

    public:
        NewRecipeInfo() noexcept = default;
        virtual ~NewRecipeInfo() noexcept = default;
        NewRecipeInfo(const NewRecipeInfo& other) noexcept = default;
        NewRecipeInfo(NewRecipeInfo&& other) noexcept = default;
        NewRecipeInfo& operator=(const NewRecipeInfo& other) noexcept = default;
        NewRecipeInfo& operator=(NewRecipeInfo& other) noexcept = default;

        virtual InfoTypes* createNewPart(const QDomElement* element) noexcept(false) = 0;

    };

    class NewNameInfo : public NewRecipeInfo {

    public:
        NewNameInfo() noexcept = default;
        ~NewNameInfo() noexcept = default;
        NewNameInfo(const NewNameInfo& other) noexcept = default;
        NewNameInfo(NewNameInfo&& other) noexcept = default;
        NewNameInfo& operator=(const NewNameInfo& other) noexcept = default;
        NewNameInfo& operator=(NewNameInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);
    };

}

#endif // NEWRECIPEINFO_H
