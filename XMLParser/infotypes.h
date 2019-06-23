#ifndef INFOTYPES_H
#define INFOTYPES_H

#include "additionalinfo.h"

namespace TestTask {

    class InfoTypes {

    public:
        InfoTypes() noexcept = default;
        virtual ~InfoTypes() noexcept = default;

        InfoTypes(const InfoTypes& other) noexcept = delete;
        InfoTypes(InfoTypes&& other) noexcept = delete;
        InfoTypes& operator=(const InfoTypes& other) noexcept = delete;
        InfoTypes& operator=(InfoTypes& other) noexcept = delete;

        virtual void showInfo() const = 0;

    };

    class RecipeName : public InfoTypes {

    public:
        RecipeName() noexcept = default;
        ~RecipeName() noexcept = default;

        RecipeName(const RecipeName& other) noexcept = delete;
        RecipeName(RecipeName&& other) noexcept = delete;
        RecipeName& operator=(const RecipeName& other) noexcept = delete;
        RecipeName& operator=(RecipeName& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        inline void setNewAttribute(const std::string& key,
                                    const std::string& value) noexcept {
            _attribute.insert(std::pair<std::string, std::string>(key, value));
        }
        inline void setText(const std::string& text) noexcept {
            _text = text;
        }

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::unordered_map<std::string, std::string> _attribute;
        std::string _text;

    };

    class IngrList : public InfoTypes {

    public:
        ~IngrList() noexcept;

        IngrList() noexcept = default;

        IngrList(const IngrList& other) noexcept = delete;
        IngrList(IngrList&& other) noexcept = delete;
        IngrList& operator=(const IngrList& other) noexcept = delete;
        IngrList& operator=(IngrList& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        void setIngredients(const std::string& name,
                            const std::string& units,
                            const std::string& unitType) noexcept(false);

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::list<Ingredient*> _ingridients;


    };

    class Utensils : public InfoTypes {

    public:
        ~Utensils() noexcept;

        Utensils() noexcept = default;

        Utensils(const Utensils& other) noexcept = delete;
        Utensils(Utensils&& other) noexcept = delete;
        Utensils& operator=(const Utensils& other) noexcept = delete;
        Utensils& operator=(Utensils& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        void setUtensils(const std::string& name,
                         const std::string& amount,
                         const std::string& unitType) noexcept(false);

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::list<Utensil*> _utensils;

    };

    class Directions : public InfoTypes {

    public:
        Directions() noexcept = default;
        ~Directions() noexcept = default;

        Directions(const Directions& other) noexcept = delete;
        Directions(Directions&& other) noexcept = delete;
        Directions& operator=(const Directions& other) noexcept = delete;
        Directions& operator=(Directions& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        inline void setSteps(const std::string& step) noexcept {
            _steps.push_back(step);
        }

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::list<std::string> _steps;

    };

    class Variations : public InfoTypes {

    public:
        Variations() noexcept = default;
        ~Variations() noexcept = default;

        Variations(const Variations& other) noexcept = delete;
        Variations(Variations&& other) noexcept = delete;
        Variations& operator=(const Variations& other) noexcept = delete;
        Variations& operator=(Variations& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        inline void setVariations(const std::string& variation) noexcept {
            _variations.push_back(variation);
        }

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::list<std::string> _variations;

    };

    class PrepTime : public InfoTypes {

    public:
        PrepTime() noexcept = default;
        ~PrepTime() noexcept = default;

        PrepTime(const PrepTime& other) noexcept = delete;
        PrepTime(PrepTime&& other) noexcept = delete;
        PrepTime& operator=(const PrepTime& other) noexcept = delete;
        PrepTime& operator=(PrepTime& other) noexcept = delete;

        inline void setName(const std::string& name) noexcept {
            _name = name;
        }
        inline void setText(const std::string& text) noexcept {
            _text = text;
        }

        void showInfo() const noexcept;

    private:
        std::string _name;
        std::string _text;

    };

}

#endif // INFOTYPES_H
