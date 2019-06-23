#include "newrecipeinfo.h"

using namespace TestTask;


InfoTypes* NewNameInfo::createNewPart(const QDomElement* element) {
    RecipeName* tmp = new RecipeName;
    tmp->setName(element->nodeName().toStdString());
    std::string attributeName = "cuisine";
    std::string checker = getElementAttribute(element, attributeName);
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName, checker);
    attributeName = "servings";
    checker = getElementAttribute(element, attributeName);
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName, checker);
    checker = element->text().toStdString();
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(checker);
    return tmp;
}

InfoTypes* NewIngrInfo::createNewPart(const QDomElement* element) {
    IngrList* tmp = new IngrList;
    tmp->setName(element->nodeName().toStdString());
    QDomNodeList* elementChildren = new QDomNodeList;
    *elementChildren = element->childNodes();
    for (int i = 0; i < elementChildren->size(); i++) {
        if (elementChildren->at(i).isElement()) {
            QDomElement* ingredientValue = new QDomElement;
            *ingredientValue = elementChildren->at(i).childNodes().at(0).toElement();
            std::string unitType;
            std::string attributeName = "units";
            unitType = getElementAttribute(ingredientValue, attributeName);
            std::string units = ingredientValue->text().toStdString();
            *ingredientValue = elementChildren->at(i).childNodes().at(1).toElement();
            std::string ingredientName = ingredientValue->text().toStdString();
            delete ingredientValue;
            if (unitType == "" || units == "" || ingredientName == "") {
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setIngredients(ingredientName, units, unitType);
        }
    }
    delete elementChildren;
    return tmp;
}

InfoTypes* NewUtensilsInfo::createNewPart(const QDomElement* element) {
    Utensils* tmp = new Utensils;
    tmp->setName(element->nodeName().toStdString());
    QDomNodeList* elementChildren = new QDomNodeList;
    *elementChildren = element->childNodes();
    for (int i = 0; i < elementChildren->size(); i++) {
        if (elementChildren->at(i).isElement()) {
            QDomElement* utensilValue = new QDomElement;
            *utensilValue = elementChildren->at(i).childNodes().at(0).toElement();
            std::string unitType;
            std::string attributeName = "units";
            unitType = getElementAttribute(utensilValue, attributeName);
            std::string amount = utensilValue->text().toStdString();
            *utensilValue = elementChildren->at(i).childNodes().at(1).toElement();
            std::string utensilName = utensilValue->text().toStdString();
            delete utensilValue;
            if (unitType == "" || amount == "" || utensilName == "") {
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setUtensils(utensilName, amount, unitType);
        }
    }
    delete elementChildren;
    return tmp;
}

InfoTypes* NewDirectionsInfo::createNewPart(const QDomElement *element) {
    Directions* tmp = new Directions;
    tmp->setName(element->nodeName().toStdString());
    QDomNodeList* elementChildren = new QDomNodeList;
    *elementChildren = element->childNodes();
    for (int i = 0; i < elementChildren->size(); i++) {
        if (elementChildren->at(i).isElement()) {
            std::string stepText = elementChildren->at(i).toElement().text().toStdString();
            if (stepText == "") {
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setSteps(stepText);
        }
    }
    delete elementChildren;
    return tmp;
}

InfoTypes* NewVariationsInfo::createNewPart(const QDomElement *element) {
    Variations* tmp = new Variations;
    tmp->setName(element->nodeName().toStdString());
    QDomNodeList* elementChildren = new QDomNodeList;
    *elementChildren = element->childNodes();
    for (int i = 0; i < elementChildren->size(); i++) {
        if (elementChildren->at(i).isElement()) {
            std::string variationText = elementChildren->at(i).toElement().text().toStdString();
            if (variationText == "") {
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setVariations(variationText);
        }
    }
    delete elementChildren;
    return tmp;
}

InfoTypes* NewPrepTimeInfo::createNewPart(const QDomElement *element) {
    PrepTime* tmp = new PrepTime;
    tmp->setName(element->nodeName().toStdString());
    std::string prepText = element->text().toStdString();
    if (prepText == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(prepText);
    return tmp;
}
