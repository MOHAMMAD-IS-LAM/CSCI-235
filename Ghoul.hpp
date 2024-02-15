/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 2
*/

#ifndef GHOUL_HPP_
#define GHOUL_HPP_

#include <iostream>
#include <string>
#include "Creature.hpp"

class Ghoul : public Creature {
    public:
        enum Faction {NONE, FLESHGORGER, SHADOWSTALKER, PLAGUEWEAVER};

        Ghoul();

        Ghoul(const std::string& name, Category c_category = MYSTICAL, int hitpoints = 1, int level = 1, bool tame = false, int decay = 0, Faction f_faction = NONE, bool transform = false);

        bool setDecay(const int& decay);

        int getDecay() const;

        void setFaction(const Faction& f_faction);

        std::string getFaction() const;

        void setTransformation(const bool& transfom);

        bool getTransformation() const;

    private:
        int level_of_decay_;
        Faction faction_;
        bool can_transform_;
        std::string name_;
        Category category_;
        int hitpoints_;
        int level_;
        bool is_tame_;
};

#endif