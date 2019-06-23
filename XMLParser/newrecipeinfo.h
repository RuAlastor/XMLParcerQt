#ifndef NEWRECIPEINFO_H
#define NEWRECIPEINFO_H

#include "infotypes.h"

namespace TestTask {

    class NewRecipeInfo {

    public:
        NewRecipeInfo() noexcept = default;
        virtual ~NewRecipeInfo() noexcept = default;

        NewRecipeInfo(const NewRecipeInfo& other) noexcept = delete;
        NewRecipeInfo(NewRecipeInfo&& other) noexcept = delete;
        NewRecipeInfo& operator=(const NewRecipeInfo& other) noexcept = delete;
        NewRecipeInfo& operator=(NewRecipeInfo& other) noexcept = delete;

        virtual InfoTypes* createNewPart(const QDomElement* element) noexcept(false) = 0;

    };

    class NewNameInfo : public NewRecipeInfo {

    public:
        NewNameInfo() noexcept = default;
        ~NewNameInfo() noexcept = default;

        NewNameInfo(const NewNameInfo& other) noexcept = delete;
        NewNameInfo(NewNameInfo&& other) noexcept = delete;
        NewNameInfo& operator=(const NewNameInfo& other) noexcept = delete;
        NewNameInfo& operator=(NewNameInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewIngrInfo : public NewRecipeInfo {

    public:
        NewIngrInfo() noexcept = default;
        ~NewIngrInfo() noexcept = default;

        NewIngrInfo(const NewIngrInfo& other) noexcept = delete;
        NewIngrInfo(NewIngrInfo&& other) noexcept = delete;
        NewIngrInfo& operator=(const NewIngrInfo& other) noexcept = delete;
        NewIngrInfo& operator=(NewIngrInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewUtensilsInfo : public NewRecipeInfo {

    public:
        NewUtensilsInfo() noexcept = default;
        ~NewUtensilsInfo() noexcept = default;

        NewUtensilsInfo(const NewUtensilsInfo& other) noexcept = delete;
        NewUtensilsInfo(NewUtensilsInfo&& other) noexcept = delete;
        NewUtensilsInfo& operator=(const NewUtensilsInfo& other) noexcept = delete;
        NewUtensilsInfo& operator=(NewUtensilsInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewDirectionsInfo : public NewRecipeInfo {

    public:
        NewDirectionsInfo() noexcept = default;
        ~NewDirectionsInfo() noexcept = default;

        NewDirectionsInfo(const NewDirectionsInfo& other) noexcept = delete;
        NewDirectionsInfo(NewDirectionsInfo&& other) noexcept = delete;
        NewDirectionsInfo& operator=(const NewDirectionsInfo& other) noexcept = delete;
        NewDirectionsInfo& operator=(NewDirectionsInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewVariationsInfo : public NewRecipeInfo {

    public:
        NewVariationsInfo() noexcept = default;
        ~NewVariationsInfo() noexcept = default;

        NewVariationsInfo(const NewVariationsInfo& other) noexcept = delete;
        NewVariationsInfo(NewVariationsInfo&& other) noexcept = delete;
        NewVariationsInfo& operator=(const NewVariationsInfo& other) noexcept = delete;
        NewVariationsInfo& operator=(NewVariationsInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

    class NewPrepTimeInfo : public NewRecipeInfo {

    public:
        NewPrepTimeInfo() noexcept = default;
        ~NewPrepTimeInfo() noexcept = default;

        NewPrepTimeInfo(const NewPrepTimeInfo& other) noexcept = delete;
        NewPrepTimeInfo(NewPrepTimeInfo&& other) noexcept = delete;
        NewPrepTimeInfo& operator=(const NewPrepTimeInfo& other) noexcept = delete;
        NewPrepTimeInfo& operator=(NewPrepTimeInfo&& other) noexcept = delete;

        InfoTypes* createNewPart(const QDomElement* element) noexcept(false);

    };

}

#endif // NEWRECIPEINFO_H
