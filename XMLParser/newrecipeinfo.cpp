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
