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
    AdditionalInfo* info = new IngrAdditionalInfo;
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
