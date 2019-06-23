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

    class NewIngrInfo : public NewRecipeInfo {

    public:
        NewIngrInfo() noexcept = default;
        ~NewIngrInfo() noexcept = default;
        NewIngrInfo(const NewIngrInfo& other) noexcept = default;
        NewIngrInfo(NewIngrInfo&& other) noexcept = default;
        NewIngrInfo& operator=(const NewIngrInfo& other) noexcept = default;
        NewIngrInfo& operator=(NewIngrInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewUtensilsInfo : public NewRecipeInfo {

    public:
        NewUtensilsInfo() noexcept = default;
        ~NewUtensilsInfo() noexcept = default;
        NewUtensilsInfo(const NewUtensilsInfo& other) noexcept = default;
        NewUtensilsInfo(NewUtensilsInfo&& other) noexcept = default;
        NewUtensilsInfo& operator=(const NewUtensilsInfo& other) noexcept = default;
        NewUtensilsInfo& operator=(NewUtensilsInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewDirectionsInfo : public NewRecipeInfo {

    public:
        NewDirectionsInfo() noexcept = default;
        ~NewDirectionsInfo() noexcept = default;
        NewDirectionsInfo(const NewDirectionsInfo& other) noexcept = default;
        NewDirectionsInfo(NewDirectionsInfo&& other) noexcept = default;
        NewDirectionsInfo& operator=(const NewDirectionsInfo& other) noexcept = default;
        NewDirectionsInfo& operator=(NewDirectionsInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewVariationsInfo : public NewRecipeInfo {

    public:
        NewVariationsInfo() noexcept = default;
        ~NewVariationsInfo() noexcept = default;
        NewVariationsInfo(const NewVariationsInfo& other) noexcept = default;
        NewVariationsInfo(NewVariationsInfo&& other) noexcept = default;
        NewVariationsInfo& operator=(const NewVariationsInfo& other) noexcept = default;
        NewVariationsInfo& operator=(NewVariationsInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewPrepTimeInfo : public NewRecipeInfo {

    public:
        NewPrepTimeInfo() noexcept = default;
        ~NewPrepTimeInfo() noexcept = default;
        NewPrepTimeInfo(const NewPrepTimeInfo& other) noexcept = default;
        NewPrepTimeInfo(NewPrepTimeInfo&& other) noexcept = default;
        NewPrepTimeInfo& operator=(const NewPrepTimeInfo& other) noexcept = default;
        NewPrepTimeInfo& operator=(NewPrepTimeInfo&& other) noexcept = default;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

}

#endif // NEWRECIPEINFO_H
