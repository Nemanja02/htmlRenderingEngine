#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include "element.h"
#include "attribute.h"

class Parser {
    private:
        Element DOM;
        std::string data;
        unsigned long int pos;
    public:

        std::string getHtml() {
            std::string val = "";
            for (int i = pos; i < data.length(); i++)
                val += data[i];
            return val;
        }

        Parser(std::string html) {
            data = trim(html);
            pos = 0;
        }

        std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
            str.erase(0, str.find_first_not_of(chars));
            return str;
        }
        
        std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
            str.erase(str.find_last_not_of(chars) + 1);
            return str;
        }

        std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
            return ltrim(rtrim(str, chars), chars);
        }
        
        char nextChar() {
            return data[pos];
        }

        bool startsWith(std::string str) {
            for (int i = 0; i < str.length(); i++) 
                if (data[pos + i] != str[i]) return false;
            return true;
        }

        bool eof() {
            return pos == data.length();
        }

        char consumeChar() {
            char current = data[pos];
            pos++;
            return current;
        }

        std::string consumeWhile(char ch) {
            std::string val = "";
            while(data[pos] == ch) {
                val += data[pos];
                pos++;
            };

            return val;
        }

        std::string consumeUntil(char ch) {
            std::string val = "";
            while(data[pos] != ch) {
                val += data[pos];
                pos++;
            };
            return val;
        }

        void consumeWhitespace() {
            std::string val = "";
            while(data[pos] == ' ' || data[pos] == '\t' || data[pos] == '\n') {
                val += data[pos];
                pos++;
            };
        }

        std::string parseTag() {
            std::string tag = "";
            while(isalnum(data[pos])) {
                tag += data[pos];
                pos++;
            }
            return tag;
        }

        Attribute parseAttribute() {
            Attribute a;
            consumeWhitespace();
            a.setName(parseTag());
            consumeWhitespace();
            consumeChar();
            consumeWhitespace();
            consumeChar();
            a.setValue(parseTag());
            consumeWhitespace();
            consumeChar();
            return a;
        }

        AttrMap parseAttributes() {
            AttrMap attrs;
            while (nextChar() != '>') {
                attrs.insert(attrs.begin(), parseAttribute());
            }
            consumeChar();
            return attrs;
        }

        Element parseElement() {
            std::vector<Element> children;
            std::string text;
            consumeChar();
            std::string tag = parseTag();
            AttrMap attrs = parseAttributes();
            consumeWhitespace();
            while(!startsWith("</")) {
                if (nextChar() == '<') {
                    children.insert(children.end(), parseElement());
                    consumeChar();
                } else {
                    text = consumeUntil('<');
                }
            }
            consumeUntil('>');

            return Element(tag, attrs, trim(text), children);
        }

        Element parseDocument() {
            if (nextChar() != '<')
                return Element();
            else {
                return parseElement();
            }
        }
};