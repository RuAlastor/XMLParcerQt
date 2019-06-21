#ifndef INFOTYPES_H
#define INFOTYPES_H

#include "additionalinfo.h"

class InfoTypes {

public:
    virtual void setName(std::string& name) = 0;
    virtual void setNewAttribute(std::string& key, std::string& value);
    virtual void setText(std::string& text);
    virtual void setAdditionalInfo(AdditionalInfo* info);

};

class RecipeName : public InfoTypes {

private:
    std::string _name;
    std::map<std::string, std::string> _attribute;
    std::string _text;

public:
    void setName(std::string& name);
    void setNewAttribute(std::string& key, std::string& value);
    void setText(std::string& text);
};

class IngrList : public InfoTypes {

private:
    std::string _name;
    AdditionalInfo* _info;

public:
    void setName(std::string& name);
    void setAdditionalInfo(AdditionalInfo* info);

};

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

#endif // INFOTYPES_H
