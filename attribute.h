#pragma once
#include <iostream>
#include <unordered_map>

class Attribute {
    private:
        std::string name, val;
    public:
        Attribute() {

        }

        Attribute(std::string name, std::string val) {
            this->name = name;
            this->val = val;
        }

        std::string getName() {
            return name;
        }

        std::string getValue() {
            return val;
        }

        void setName(std::string name) {
            this->name = name;
        }

        void setValue(std::string value) {
            val = value;
        }
};