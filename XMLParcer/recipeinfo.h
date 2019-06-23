#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QtCore>
#include <QtXml>

#include "infotypes.h"

/* Helps factory to choose info type about recipe */
class RecipeInfo {
public:
    virtual InfoTypes* createNewInfo(QDomElement& element) = 0;

    virtual ~RecipeInfo();
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
