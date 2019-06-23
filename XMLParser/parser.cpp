#include "parser.h"

using namespace TestTask;

Parser::Parser(const char *fileloc) noexcept : _xmlParser(nullptr), _fileloc(fileloc), _recipe(nullptr) {}

Parser::~Parser() {
    delete _xmlParser;
    delete _recipe;
}


int Parser::loadDocument() {
    _xmlParser = new QDomDocument;
    QFile* file = new QFile(QString(_fileloc));
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Failed to open file.\n";
        delete file;
        return 1;
    }
    if (!_xmlParser->setContent(file)) {
        std::cout << "Failed to parce file.\n";
        file->close();
        delete file;
        return 2;
    }
    file->close();
    delete file;

    return 0;
}

int Parser::parseDocument() {
    // Check for errors
    if (_xmlParser->firstChildElement().isNull()) {
        std::cout << "Document is empty. Review XML-document.\n";
        return 3;
    }

    _recipe = new Recipe;

    QDomElement* root = new QDomElement;
    *root = _xmlParser->firstChildElement();

    QString* attributeValue = new QString;
    *attributeValue = root->attribute("type");
    if (*attributeValue == "") {
        std::cout << "Unknown structure. Please, review the XML-document.\n";
        delete root;
        delete attributeValue;
        return 4;
    }
    _recipe->setType(attributeValue->toStdString());

    QDomNodeList* rootChilden = new QDomNodeList;
    *rootChilden = root->childNodes();
    for (int i = 0; i < rootChilden->size(); ++i) {
        if (rootChilden->at(i).isElement()) {
            *root = rootChilden->at(i).toElement();
        }
        NewRecipeInfo* writer = findCorrectWriter(root);
        if (writer == nullptr) {
            std::cout << "Unknown tag. Please, add it or review the XML-document.\n";
            return 5;
        }
        InfoTypes* newRecipePart = writer->createNewPart(root);
        if (newRecipePart == nullptr) {
            std::cout << "Unknown structure. Please, review the XML-document.\n";
            delete writer;
            return 4;
        }
        _recipe->setNewRecipePart(newRecipePart);
        delete writer;
    }



    delete root;
    delete attributeValue;
    delete rootChilden;
    return 0;
}


void Parser::printDocument() const noexcept{
    _recipe->showRecipe();
}


NewRecipeInfo* Parser::findCorrectWriter(const QDomElement *element) {
    if (element->nodeName() == "recipename") {
        return new NewNameInfo;
    }
    else {
        return nullptr;
    }
}




















