#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QtCore>
#include <QtXml>

#include "infotypes.h"

/* create a derivative from "factory class"
 *
 * class ...Info : public RecipeInfo {
 * public:
 *     InfoTypes* createNewInfo(QDomElement& element);
 * };
 *
 * method should:
 * 1. allocate memory for a your infotype
 * 2. fill it with info according to the content of its XML-sibling
 * 3. return pointer to the allocated memory
 *
 * next step is infotype.h
 * create a new derivative class from InfoTypes
*/

class RecipeInfo {
public:
    virtual InfoTypes* createNewInfo(QDomElement& element) = 0;
};

class NameInfo : public RecipeInfo {
public:
    InfoTypes* createNewInfo(QDomElement& element);
};
class IngrInfo : public RecipeInfo {
public:
    InfoTypes* createNewInfo(QDomElement& element);
};
class UtensilsInfo : public RecipeInfo {
public:
    InfoTypes* createNewInfo(QDomElement& element);
};
class DirectionsInfo : public RecipeInfo {
    InfoTypes* createNewInfo(QDomElement& element);
};
class VariationsInfo : public RecipeInfo {
    InfoTypes* createNewInfo(QDomElement& element);
};
class PrepTimeInfo : public RecipeInfo {
    InfoTypes* createNewInfo(QDomElement& element);
};

#endif // RECIPEINFO_H
