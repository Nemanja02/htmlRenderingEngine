#pragma once

#include<iostream>
#include<vector>
#include<string>
#include "attribute.h"

typedef std::vector<Attribute> AttrMap;

class Element {
    private:
        std::string tag;
        AttrMap attrs;
        std::string text;
        std::vector<Element> children;
    public:
        void setText(std::string data) {
            text = data;
        }
        std::string getTag() {
            return tag;
        }

        std::string getText() {
            return text;
        }

        std::vector<Element> getChildren() {
            return children;
        }

        AttrMap getAttributes() {
            return attrs;
        }

        Element() {
            
        }

        Element(std::string tag) {
            this->tag = tag;
        }

        Element(std::string tag, std::vector<Element> children) {
            this->tag = tag;
            this->children = children;
        }

        Element(std::string tag, std::string text) {
            this->tag = tag;
            this->text = text;
        }

        Element(std::string tag, std::string text, std::vector<Element> children) {
            this->tag = tag;
            this->text = text;
            this->children = children;
        }

        Element(std::string tag, AttrMap attrs) {
            this->tag = tag;
            this->attrs = attrs;
        }

        Element(std::string tag, AttrMap attrs, std::vector<Element> children) {
            this->tag = tag;
            this->attrs = attrs;
            this->children = children;
        }

        Element(std::string tag, AttrMap attrs, std::string text) {
            this->tag = tag;
            this->attrs = attrs;
            this->text = text;
        }

        Element(std::string tag, AttrMap attrs, std::string text, std::vector<Element> children) {
            this->tag = tag;
            this->attrs = attrs;
            this->text = text;
            this->children = children;
        }

        void addChild(Element e) {
            children.insert(children.begin(), e);
        }

        void addAttr(std::string attr, std::string value) {
            attrs.insert(attrs.begin(), Attribute(attr, value));
        }

        std::string stringifySelf() {
            std::string val = "<" + tag + " ";
            std::string attrsString = "";
            for (int i = 0; i < attrs.size(); i++)
                attrsString += attrs[i].getName() + "=" + "\"" + attrs[i].getValue() + "\" ";
            val += attrsString;
            val = val.substr(0, val.size()-1) + ">";
            val = val + text;
            for (int x = 0; x < children.size(); x++) 
                val += children[x].stringifySelf();
            val = val + "</" + tag + ">";
            return val;
        }

        static std::string stringify(Element e) {
            std::string tag = e.getTag();
            std::string text = e.getText();
            AttrMap attrs = e.getAttributes();
            std::vector<Element> children = e.getChildren();

            std::string val = "<" + tag + " ";
            std::string attrsString = "";
            for (int i = 0; i < attrs.size(); i++)
                attrsString += attrs[i].getName() + "=" + "\"" + attrs[i].getValue() + "\" ";
            val += attrsString;
            val = val.substr(0, val.size()-1) + ">";
            val = val + text;
            for (int x = 0; x < children.size(); x++) 
                val += children[x].stringifySelf();
            val = val + "</" + tag + ">";
            return val;
        }

        // friend ostream& operator << (ostream& os, const Element e) {
        //     string val = e.stringifySelf();
        //     os << val;
        // }
};

// int main() {
//     Element html("html");
//     Element head("head");
//     Element title("title", "Zelim da umrem");
//     Element body("body");
//     Element h2("h2", "Zelim da umrem");
//     h2.addAttr("class", "header");
//     h2.addAttr("id", "kurac");
//     body.addChild(h2);
//     html.addChild(body);
//     head.addChild(title);
//     html.addChild(head);
//     std::cout << html.stringifySelf() << std::endl;
//     return 0;
// }