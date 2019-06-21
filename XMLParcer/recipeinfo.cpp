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
