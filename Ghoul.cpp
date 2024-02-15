/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 2
*/

#include "Ghoul.hpp"

Ghoul::Ghoul():Creature() {
    level_of_decay_ = 0;
    faction_ = NONE;
    can_transform_ = false;
}

Ghoul::Ghoul(const std::string& name, Category c_category, int hitpoints, int level, bool tame, int decay, Faction f_faction, bool transform):Creature(name, c_category, hitpoints, level, tame), level_of_decay_(decay), faction_(f_faction), can_transform_(transform) {
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

    if (decay < 0) {
        level_of_decay_ = 0;
    }
    else {
        level_of_decay_ = decay;
    }

    switch(f_faction) {
        case NONE : faction_ = NONE; break;
        case FLESHGORGER : faction_ = FLESHGORGER; break;
        case SHADOWSTALKER : faction_ = SHADOWSTALKER; break;
        case PLAGUEWEAVER : faction_ = PLAGUEWEAVER; break;
        default : faction_ = NONE;
    }

    can_transform_ = transform;

}

bool Ghoul::setDecay(const int& decay) {
    if (decay < 0) {
        return false;
    }
    else {
        level_of_decay_ = decay;
        return true;
    }
}

int Ghoul::getDecay() const {
    return level_of_decay_;
}

void Ghoul::setFaction(const Faction& f_faction) {
    switch(f_faction) {
        case NONE : faction_ = NONE; break;
        case FLESHGORGER : faction_ = FLESHGORGER; break;
        case SHADOWSTALKER : faction_ = SHADOWSTALKER; break;
        case PLAGUEWEAVER : faction_ = PLAGUEWEAVER; break;
        default : faction_ = NONE;
    }
}

std::string Ghoul::getFaction() const {
    std::string faction;
    switch(faction_) {
        case NONE : faction = "NONE"; break;
        case FLESHGORGER : faction = "FLESHGORGER"; break;
        case SHADOWSTALKER : faction = "SHADOWSTALKER"; break;
        case PLAGUEWEAVER : faction = "PLAGUEWEAVER"; break;
    }
    return faction;
}

void Ghoul::setTransformation(const bool& transform) {
    can_transform_ = transform;
}

bool Ghoul::getTransformation() const {
    return can_transform_;
}