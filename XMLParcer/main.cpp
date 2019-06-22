/* To add a new tag to read go to chooseInfoType function */

#include "recipeinfo.h"

RecipeInfo* chooseInfoType(QDomElement& element);

int main() {

    // Setting up parcer
    QDomDocument xmlParcer;
    QFile file("/home/student/C++/XMLParcerQt/example.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Failed to open \"example.xml\".\n";
        return -1;
    }
    if (!xmlParcer.setContent(&file)) {
        std::cout << "Failed to parce \"example.xml\".\n";
        file.close();
        return -1;
    }

    // Setting up factory
    std::list<InfoTypes*> recipe;
    RecipeInfo* writer;

    // Factory's working on a parced document
    QDomNodeList rootChildren = xmlParcer.firstChildElement().childNodes();
    for (int i = 0; i < rootChildren.size(); i++ ) {
        QDomElement elem;
        if (rootChildren.item(i).isElement()) {
            elem = rootChildren.item(i).toElement();
            writer = chooseInfoType(elem);
        }
        if (writer == nullptr) {
            std::cout << "Unknown tag. Please, check XML file.\n";
            return -1;
        }
        recipe.push_back(writer->createNewInfo(elem));
        delete writer;
        recipe.back()->showInfo();
    }


    return 0;
}

/* to add new tag to read add new /if/ statement
 *
 * else if (elementName == "/new tag/") {
 *     return new /new dirivative class from "factory class"/
 * }
 *
 * next step is recipeinfo.h
 * create new derivative class from RecipeInfo
*/
RecipeInfo* chooseInfoType(QDomElement &element) {
    std::string elementName = element.nodeName().toStdString();
    if (elementName == "recipename") {
        return new NameInfo;
    }
    else if (elementName == "ingredlist") {
        return new IngrInfo;
    }
    /*else if (elementName == "utensils") {
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
    }*/
    else {
        return nullptr;
    }
}
