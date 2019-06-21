#ifndef XMLNODE_H
#define XMLNODE_H

#include <map>

template <class T>
class XMLNode {

public:

    virtual void setName(std::string& name) = 0;
    virtual std::string getName() = 0;

    virtual void setNewAttribute(std::string& key, T& value) = 0;
    virtual T getAttributeValue(std::string& key) = 0;
    virtual std::string* getAttributesArray() = 0;

    virtual void setText(std::string& text) = 0;
    virtual std::string getText() = 0;

    virtual XMLNode** getChildren() = 0;

    virtual bool isRoot() = 0;


};

#endif // XMLNODE_H
