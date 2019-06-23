#include "recipeinfo.h"

RecipeInfo::~RecipeInfo() {}


InfoTypes* NameInfo::createNewInfo(QDomElement& element) {
    RecipeName* tmp = new RecipeName; /* If error - deleted here, if not in Parcer destructor */
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
    IngrList* tmp = new IngrList; /* If error - deleted here, if not in Parcer destructor */
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new IngrAndUtensilsAdditionalInfo; /* If error - deleted here, if not in IngrList destructor */
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
    Utensils* tmp = new Utensils; /* If error - deleted here, if not in Parcer destructor */
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new IngrAndUtensilsAdditionalInfo; /* If error - deleted here, if not in Utensils destructor */
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
    Directions* tmp = new Directions; /* If error - deleted here, if not in Parcer destructor */
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new DirectionsAdditionalInfo; /* If error - deleted here, if not in Directions destructor */
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
    Variations* tmp = new Variations; /* If error - deleted here, if not in Parcer destructor */
    tmp->setName(element.nodeName().toStdString());
    AdditionalInfo* info = new VariationsAdditionalInfo; /* If error - deleted here, if not in Variations destructor */
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
    PrepTime* tmp = new PrepTime; /* If error - deleted here, if not in Parcer destructor */
    tmp->setName(element.nodeName().toStdString());
    QString checker = element.text();
    if (checker == "") {
        delete tmp;
        return nullptr;
    }
    tmp->setText(checker.toStdString());
    return tmp;
}



















