#include "parcer.h"


/* to add new tag to read add new /if/ statement
 *
 * else if (elementName == "/new tag/") {
 *     return new /new dirivative class from RecipeInfo/
 * }
 *
 * next step is recipeinfo.h
 * create new derivative class from RecipeInfo
*/

RecipeInfo* Parcer::chooseInfoType(QDomElement &element) {
    std::string elementName = element.nodeName().toStdString();
    if (elementName == "recipename") {
        return new NameInfo;
    }
    else if (elementName == "ingredlist") {
        return new IngrInfo;
    }
    else if (elementName == "utensils") {
        return new UtensilsInfo;
    }
    else if (elementName == "directions") {
        return new DirectionsInfo;
    }
    else if (elementName == "variations") {
        return new VariationsInfo;
    }
    else if (elementName == "preptime") {
        return new PrepTimeInfo;
    }
    else {
        return nullptr;
    }
}

int Parcer::loadDocument(QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Failed to open \"example.xml\".\n";
        return -1;
    }
    if (!xmlParcer.setContent(&file)) {
        std::cout << "Failed to parce \"example.xml\".\n";
        file.close();
        return -1;
    }
    return 0;
}

int Parcer::parceLoadedFile() {
    if (xmlParcer.isNull()) {
        std::cout << "Load file first.\n";
        return -1;
    }
    QDomNodeList rootChildren = xmlParcer.firstChildElement().childNodes();
    for (int i = 0; i < rootChildren.size(); i++ ) {
        QDomElement elem;
        if (rootChildren.item(i).isElement()) {
            elem = rootChildren.item(i).toElement();
            writer = chooseInfoType(elem);
        }
        if (writer == nullptr) {
            std::cout << "Unknown tag. Please, add it or review the XML-document.\n";
            return -1;
        }
        recipe.push_back(writer->createNewInfo(elem));
        delete writer;
    }
    return 0;
}

int Parcer::printRecipe() {
    if (recipe.empty()) {
        std::cout << "Recipe is empty.\n";
        return -1;
    }
    for (auto iter : recipe) {
        iter->showInfo();
    }
}









