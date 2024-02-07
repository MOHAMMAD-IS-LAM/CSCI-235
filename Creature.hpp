/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 1 interface (This is a .hpp file that includes all of the hidden code).
*/
#include <iostream>
#include <ctype.h>

#ifndef CREATURE_INTERFACE
#define CREATURE_INTERFACE

class Creature {

    public:

        enum Category {UNKNOWN, UNDEAD, MYSTICAL, ALIEN};

        Creature();

        Creature(std::string name, Category c_category = UNKNOWN, int hitpoints = 1, int level = 1, bool tame = false);

        bool setName(const std::string& name);

        std::string getName() const;

        void setCategory(const Category& n_category);

        std::string getCategory() const;

        bool setHitpoints (const int& hitpoints);

        int getHitpoints() const;

        bool setLevel(const int& level);

        int getLevel() const;

        void setTame(const bool& tame);

        bool isTame() const;

        void display() const;

    private:
        std::string name_;
        Category category_;
        int hitpoints_;
        int level_;
        bool is_tame_;
        

};
#endif