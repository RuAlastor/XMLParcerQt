#include "newrecipeinfo.h"

using namespace TestTask;

InfoTypes* NewNameInfo::createNewPart(const QDomElement* element) {
    RecipeName* tmp = new RecipeName;
    tmp->setName(element->nodeName().toStdString());
    QString* attributeName = new QString;
    *attributeName = "cuisine";
    QString* checker = new QString;
    *checker = element->attribute(*attributeName);
    if (*checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName->toStdString(), checker->toStdString());
    *attributeName = "servings";
    *checker = element->attribute(*attributeName);
    if (*checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName->toStdString(), checker->toStdString());
    *checker = element->text();
    if (*checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(checker->toStdString());
    return tmp;
}

InfoTypes* NewIngrInfo::createNewPart(const QDomElement* element) {
    IngrList* tmp = new IngrList;
    tmp->setName(element->nodeName().toStdString());
    QDomNodeList* elementChildren = new QDomNodeList;
    *elementChildren = element->childNodes();
    for (int i = 0; i < elementChildren->size(); i++) {
        if (elementChildren->at(i).isElement()) {
            QDomNodeList* ingredientValues = new QDomNodeList;
            *ingredientValues = elementChildren->at(i).childNodes();
            QDomElement* ingredientValue = new QDomElement;
            *ingredientValue = ingredientValues->at(0).toElement();
            QString* unitType = new QString;
            QString* units = new QString;
            QString* ingredientName = new QString;
            *unitType = ingredientValue->attribute("units");
            *units = ingredientValue->text();
            *ingredientValue = ingredientValues->at(1).toElement();
            delete ingredientValues;
            *ingredientName = ingredientValue->text();
            delete ingredientValue;
            if (*unitType == "" || *units == "" || *ingredientName == "") {
                delete unitType;
                delete units;
                delete ingredientName;
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setIngredients(ingredientName->toStdString(),
                                units->toStdString(),
                                unitType->toStdString());
            delete unitType;
            delete units;
            delete ingredientName;
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
            QDomNodeList* utensilValues = new QDomNodeList;
            *utensilValues = elementChildren->at(i).childNodes();
            QDomElement* utensilValue = new QDomElement;
            *utensilValue = utensilValues->at(0).toElement();
            QString* unitType = new QString;
            QString* amount = new QString;
            QString* utensilName = new QString;
            *unitType = utensilValue->attribute("units");
            *amount = utensilValue->text();
            *utensilValue = utensilValues->at(1).toElement();
            delete utensilValues;
            *utensilName = utensilValue->text();
            delete utensilValue;
            if (*unitType == "" || *amount == "" || *utensilName == "") {
                delete unitType;
                delete amount;
                delete utensilName;
                delete elementChildren;
                delete tmp;
                return nullptr;
            }
            tmp->setUtensils(utensilName->toStdString(),
                                amount->toStdString(),
                                unitType->toStdString());
            delete unitType;
            delete amount;
            delete utensilName;
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
            QString* stepText = new QString;
            *stepText = elementChildren->at(i).toElement().text();
            if (*stepText == "") {
                delete elementChildren;
                delete stepText;
                delete tmp;
                return nullptr;
            }
            tmp->setSteps(stepText->toStdString());
            delete stepText;
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
            QString* variationText = new QString;
            *variationText = elementChildren->at(i).toElement().text();
            if (*variationText == "") {
                delete elementChildren;
                delete variationText;
                delete tmp;
                return nullptr;
            }
            tmp->setVariations(variationText->toStdString());
            delete variationText;
        }
    }
    delete elementChildren;
    return tmp;
}

InfoTypes* NewPrepTimeInfo::createNewPart(const QDomElement *element) {
    PrepTime* tmp = new PrepTime;
    tmp->setName(element->nodeName().toStdString());
    QString* prepText = new QString;
    *prepText = element->text();
    if (*prepText == "") {
        delete prepText;
        delete tmp;
        return nullptr;
    }
    tmp->setText(prepText->toStdString());
    delete prepText;
    return tmp;
}
