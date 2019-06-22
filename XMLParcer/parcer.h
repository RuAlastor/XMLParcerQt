#ifndef PARCER_H
#define PARCER_H

#include "recipeinfo.h"

class Parcer {

private:
    QDomDocument xmlParcer;
    std::list<InfoTypes*> recipe;
    RecipeInfo* writer;

    RecipeInfo* chooseInfoType(QDomElement& element);

public:
    int loadDocument(QString& filename);
    int parceLoadedFile();
    int printRecipe();

};

#endif // PARCER_H
