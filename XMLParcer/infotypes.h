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
};

class RecipeName : public InfoTypes {

private:
    std::string _name;
    std::map<std::string, std::string> _attribute;
    std::string _text;

public:
    void setName(const std::string& name);
    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

    void setAdditionalInfo(AdditionalInfo* info);

    void showInfo();
};

class IngrList : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

public:
    void setName(const std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

    void setNewAttribute(const std::string& key, const std::string& value);
    void setText(const std::string& text);

    void showInfo();

};
/*
class Utensils : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

public:
    void setName(std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

};

class Directions : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

public:
    void setName(std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

};

class Variations : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

public:
    void setName(std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

};

class PrepTime : public InfoTypes {

private:
    std::string _name;
    std::string _text;

public:
    void setName(std::string& name);
    void setText(std::string& text);
};
*/

#endif // INFOTYPES_H
