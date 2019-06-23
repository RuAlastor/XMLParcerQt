#include "recipeinfo.h"

RecipeInfo::~RecipeInfo() {}

InfoTypes* NameInfo::createNewInfo(QDomElement& element) {
    RecipeName* tmp = new RecipeName;
    tmp->setName(element.nodeName().toStdString());
    QString attributeName = "cuisine";
    QString checker = element.attribute(attributeName);
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName.toStdString(), checker.toStdString());
    attributeName = "servings";
    checker = element.attribute(attributeName);
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setNewAttribute(attributeName.toStdString(), checker.toStdString());
    checker = element.text();
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(checker.toStdString());
    return tmp;
}

InfoTypes* IngrInfo::createNewInfo(QDomElement &element) {
    IngrList* tmp = new IngrList;
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new IngrAndUtensilsAdditionalInfo;
    QDomNodeList elementChildren = element.childNodes();
    for (int i = 0; i < elementChildren.size(); i++) {
        QDomNodeList childrenOfChildren = elementChildren.at(i).childNodes();
        QDomElement tmpElement = childrenOfChildren.at(0).toElement();
        QString unitType = tmpElement.text();
        QString units = tmpElement.attribute("units");
        if (unitType == "" || units == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewMeasures(units.toStdString(),
                             unitType.toStdString());
        tmpElement = childrenOfChildren.at(1).toElement();
        QString text = tmpElement.text();
        if (text == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewText(text.toStdString());
    }
    tmp->setAdditionalInfo(info);
    return tmp;
}

InfoTypes* UtensilsInfo::createNewInfo(QDomElement &element) {
    Utensils* tmp = new Utensils;
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new IngrAndUtensilsAdditionalInfo;
    QDomNodeList elementChildren = element.childNodes();
    for (int i = 0; i < elementChildren.size(); i++) {
        QDomNodeList childrenOfChildren = elementChildren.at(i).childNodes();
        QDomElement tmpElement = childrenOfChildren.at(0).toElement();
        QString unitType = tmpElement.text();
        QString units = tmpElement.attribute("units");
        if (unitType == "" || units == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewMeasures(units.toStdString(),
                             unitType.toStdString());
        tmpElement = childrenOfChildren.at(1).toElement();
        QString text = tmpElement.text();
        if (text == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewText(text.toStdString());
    }
    tmp->setAdditionalInfo(info);
    return tmp;
}

InfoTypes* DirectionsInfo::createNewInfo(QDomElement &element) {
    Directions* tmp = new Directions;
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new DirectionsAdditionalInfo;
    QDomNodeList elementChildren = element.childNodes();
    for (int i = 0; i < elementChildren.size(); i++) {
        QDomElement tmpElement = elementChildren.at(i).toElement();
        QString text = tmpElement.text();
        if (text == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewText(text.toStdString());
    }
    tmp->setAdditionalInfo(info);
    return tmp;
}

InfoTypes* VariationsInfo::createNewInfo(QDomElement &element) {
    Variations* tmp = new Variations;
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new VariationsAdditionalInfo;
    QDomNodeList elementChildren = element.childNodes();
    for (int i = 0; i < elementChildren.size(); i++) {
        QDomElement tmpElement = elementChildren.at(i).toElement();
        QString text = tmpElement.text();
        if (text == "") {
            delete tmp;
            delete info;
            return nullptr;
        }
        info->setNewText(text.toStdString());
    }
    tmp->setAdditionalInfo(info);
    return tmp;
}

InfoTypes* PrepTimeInfo::createNewInfo(QDomElement &element) {
    PrepTime* tmp = new PrepTime;
    tmp->setName(element.nodeName().toStdString());
    QString checker = element.text();
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(checker.toStdString());
    return tmp;
}



















