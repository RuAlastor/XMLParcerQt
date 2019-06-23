#ifndef PARSER_H
#define PARSER_H

#include "recipe.h"

namespace TestTask {

    class Parser {

    public:
        explicit Parser(const char* fileloc) noexcept;
        ~Parser() noexcept;

        Parser() = delete;
        Parser(const Parser& other) = delete;
        Parser(Parser&& other) = delete;
        Parser& operator=(const Parser& other) = delete;
        Parser& operator=(Parser&& other) = delete;

        int loadDocument() noexcept(false);
        int parseDocument() noexcept(false);

        void printDocument() const noexcept;

    private:
        QDomDocument* _xmlParser;
        const char* _fileloc;
        Recipe* _recipe;

        NewRecipeInfo* findCorrectWriter(const QDomElement* element);

    };

}

#endif // PARSER_H
