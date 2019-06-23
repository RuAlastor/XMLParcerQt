#ifndef INFOTYPES_H
#define INFOTYPES_H

#include <map>

#include "additionalinfo.h"

class InfoTypes {

public:
    virtual void setName(const std::string& name) = 0;
    virtual void setNewAttribute(const std::string& key, const std::string& value) = 0;
    virtual void setText(const std::string& text) = 0;
    virtual void setAdditionalInfo(AdditionalInfo* info) = 0;

    virtual void showInfo() = 0;

    virtual ~InfoTypes();
};

class RecipeName : public InfoTypes {

private:
    std::string _name;
    std::map<std::string, std::string> _attribute;
    std::string _text;

    void setAdditionalInfo(AdditionalInfo* info);

public:
    void setName(const std::string& name);
    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

    void showInfo();
};

class IngrList : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

public:
    void setName(const std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

    void showInfo();

};

class Utensils : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

public:
    void setName(const std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

    void showInfo();

};

class Directions : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

public:
    void setName(const std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

    void showInfo();

};

class Variations : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

public:
    void setName(const std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

    void showInfo();

};
class PrepTime : public InfoTypes {

private:
    std::string _name;
    std::string _text;

    void setAdditionalInfo(AdditionalInfo* info);
    void setNewAttribute(const std::string& key, const std::string& value);

public:
    void setName(const std::string& name);
    void setText(const std::string& text);

    void showInfo();

};

#endif // INFOTYPES_H
