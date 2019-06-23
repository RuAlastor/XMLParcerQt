#ifndef INFOTYPES_H
#define INFOTYPES_H

#include "additionalinfo.h"

namespace TestTask {

    class InfoTypes {

    public:
        InfoTypes() noexcept = default;
        virtual ~InfoTypes() noexcept = default;
        InfoTypes(const InfoTypes& other) noexcept = default;
        InfoTypes(InfoTypes&& other) noexcept = default;
        InfoTypes& operator=(const InfoTypes& other) noexcept = default;
        InfoTypes& operator=(InfoTypes& other) noexcept = default;

        virtual void showInfo() noexcept = 0;

    };

    class RecipeName : public InfoTypes {

    public:
        RecipeName() noexcept = default;
        ~RecipeName() noexcept = default;
        RecipeName(const RecipeName& other) noexcept = default;
        RecipeName(RecipeName&& other) noexcept = default;
        RecipeName& operator=(const RecipeName& other) noexcept = default;
        RecipeName& operator=(RecipeName& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setNewAttribute(const std::string& key, const std::string& value) noexcept;
        void setText(const std::string& text) noexcept;

        void showInfo() noexcept;

    private:
        std::string _name;
        std::map<std::string, std::string> _attribute;
        std::string _text;

    };

    class IngrList : public InfoTypes {

    public:
        ~IngrList() noexcept;

        IngrList() noexcept = default;
        IngrList(const IngrList& other) noexcept = default;
        IngrList(IngrList&& other) noexcept = default;
        IngrList& operator=(const IngrList& other) noexcept = default;
        IngrList& operator=(IngrList& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setIngredients(const std::string& name,
                            const std::string& units,
                            const std::string& unitType) noexcept(false);

        void showInfo() noexcept;

    private:
        std::string _name;
        std::list<Ingredient*> _ingridients;


    };

    class Utensils : public InfoTypes {

    public:
        ~Utensils() noexcept;

        Utensils() noexcept = default;
        Utensils(const Utensils& other) noexcept = default;
        Utensils(Utensils&& other) noexcept = default;
        Utensils& operator=(const Utensils& other) noexcept = default;
        Utensils& operator=(Utensils& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setUtensils(const std::string& name,
                         const std::string& units,
                         const std::string& unitType) noexcept(false);

        void showInfo() noexcept;

    private:
        std::string _name;
        std::list<Utensil*> _utensils;

    };

    class Directions : public InfoTypes {

    public:
        Directions() noexcept = default;
        ~Directions() noexcept = default;
        Directions(const Directions& other) noexcept = default;
        Directions(Directions&& other) noexcept = default;
        Directions& operator=(const Directions& other) noexcept = default;
        Directions& operator=(Directions& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setSteps(const std::string& step) noexcept;

        void showInfo() noexcept;

    private:
        std::string _name;
        std::list<std::string> _steps;

    };

    class Variations : public InfoTypes {

    public:
        Variations() noexcept = default;
        ~Variations() noexcept = default;
        Variations(const Variations& other) noexcept = default;
        Variations(Variations&& other) noexcept = default;
        Variations& operator=(const Variations& other) noexcept = default;
        Variations& operator=(Variations& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setVariations(const std::string& variation) noexcept;

        void showInfo() noexcept;

    private:
        std::string _name;
        std::list<std::string> _variations;

    };

    class PrepTime : public InfoTypes {

    public:
        PrepTime() noexcept = default;
        ~PrepTime() noexcept = default;
        PrepTime(const PrepTime& other) noexcept = default;
        PrepTime(PrepTime&& other) noexcept = default;
        PrepTime& operator=(const PrepTime& other) noexcept = default;
        PrepTime& operator=(PrepTime& other) noexcept = default;

        void setName(const std::string& name) noexcept;
        void setText(const std::string& text) noexcept;

        void showInfo() noexcept;

    private:
        std::string _name;
        std::string _text;

    };

}

#endif // INFOTYPES_H
