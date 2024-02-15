/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
*/

#include <iostream>
#include "Dragon.hpp"

Dragon::Dragon():Creature() { 
   affinity_ = NONE;
   num_heads_ = 1;
   can_fly_ = false;
}

Dragon::Dragon(const std::string& name, Category c_category, int hitpoints, int level, bool tame, Element e_element, int heads, bool flight)
    : Creature(name, c_category, hitpoints, level, tame), affinity_(e_element), num_heads_(heads), can_fly_(flight) {
    for (int c = 0; c < name.length(); c++) {
        if (!isalpha(name[c])) {
            name_ = "NAMELESS";
            break;
        }
        else {
            name_ = name;
        } 
    }

    for (int i = 0; i < name_.length(); i++) {
        name_[i] = toupper(name_[i]);
    }

    if (hitpoints <= 0) {
        hitpoints_ = 1;
    }
    else {
        hitpoints_ = hitpoints;
    }

    if (level <= 0) {
        level_ = 1;
    }
    else {
        level_ = level;
    }

    is_tame_ = tame;

    switch(c_category) {
        case UNDEAD : category_ = UNDEAD; break;
        case MYSTICAL : category_ = MYSTICAL; break;
        case ALIEN : category_ = ALIEN; break;
        case UNKNOWN : category_ = UNKNOWN; break;
        default : category_ = UNKNOWN;
    }

    switch(e_element) {
        case NONE : affinity_ = NONE; break;
        case FIRE : affinity_ = FIRE; break;
        case WATER : affinity_ = WATER; break;
        case EARTH : affinity_ = EARTH; break;
        case AIR : affinity_ = AIR; break;
        default : affinity_ = NONE;
    }

    if (heads <= 0) {
        num_heads_ = 1;
    }
    else {
        num_heads_ = heads;
    }

    can_fly_ = flight;

}

void Dragon::setElement(const Element& e_element) {
    switch(e_element) {
        case NONE : affinity_ = NONE; break;
        case FIRE : affinity_ = FIRE; break;
        case WATER : affinity_ = WATER; break;
        case EARTH : affinity_ = EARTH; break;
        case AIR : affinity_ = AIR; break;
        default : affinity_ = NONE;
    }
}

std::string Dragon::getElement() const {
    std::string element;
    switch(affinity_) {
        case NONE : element = "NONE"; break;
        case FIRE : element = "FIRE"; break;
        case WATER : element = "WATER"; break;
        case EARTH : element = "EARTH"; break;
        case AIR : element = "AIR"; break;
    }
    return element;
}

int Dragon::getNumberOfHeads() const {
    return num_heads_;
}

bool Dragon::setNumberOfHeads(const int& heads) {
    if (heads <= 0) {
        return false;
    }
    else {
        num_heads_ = heads;
        return num_heads_;
    }
}

void Dragon::setFlight(const bool& flight) {
    can_fly_ = flight;
}

bool Dragon::getFlight() const {
    return can_fly_;
}