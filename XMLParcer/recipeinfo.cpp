#include "recipeinfo.h"

InfoTypes* NameInfo::createNewInfo(QDomElement& element) {
    RecipeName* tmp = new RecipeName;
    tmp->setName(element.nodeName().toStdString());
    QString attributeName = "cuisine";
    tmp->setNewAttribute(attributeName.toStdString(), element.attribute(attributeName).toStdString());
    attributeName = "servings";
    tmp->setNewAttribute(attributeName.toStdString(), element.attribute(attributeName).toStdString());
    tmp->setText(element.text().toStdString());
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
        info->setNewMeasures(tmpElement.text().toStdString(),
                             tmpElement.attribute("units").toStdString());
        tmpElement = childrenOfChildren.at(1).toElement();
        info->setNewText(tmpElement.text().toStdString());
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
        info->setNewMeasures(tmpElement.text().toStdString(),
                             tmpElement.attribute("units").toStdString());
        tmpElement = childrenOfChildren.at(1).toElement();
        info->setNewText(tmpElement.text().toStdString());
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
        info->setNewText(tmpElement.text().toStdString());
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
        info->setNewText(tmpElement.text().toStdString());
    }
    tmp->setAdditionalInfo(info);
    return tmp;
}

InfoTypes* PrepTimeInfo::createNewInfo(QDomElement &element) {
    PrepTime* tmp = new PrepTime;
    tmp->setName(element.nodeName().toStdString());
    tmp->setText(element.text().toStdString());
    return tmp;
}



















