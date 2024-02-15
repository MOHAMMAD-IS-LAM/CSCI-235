/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 2
*/

#ifndef DRAGON_HPP_
#define DRAGON_HPP_

#include <iostream>
#include <string>
#include "Creature.hpp"

class Dragon : public Creature{
    public:
        enum Element {NONE, FIRE, WATER, EARTH, AIR};

        Dragon();

        Dragon(const std::string& name, Category c_category = MYSTICAL, int hitpoints = 1, int level = 1, bool tame = false, Element e_element = NONE, int heads = 1, bool flight = false);

        void setElement(const Element& e_element);

        std::string getElement() const;

        bool setNumberOfHeads(const int& heads);

        int getNumberOfHeads() const;

        void setFlight(const bool& flight);

        bool getFlight() const;

    private:
        Element affinity_;
        int num_heads_;
        bool can_fly_;
        std::string name_;
        Category category_;
        int hitpoints_;
        int level_;
        bool is_tame_;        
};

#endif