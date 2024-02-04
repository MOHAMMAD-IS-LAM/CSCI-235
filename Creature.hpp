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

        Creature(std::string name, Category c_category, int level = 1, int hitpoints = 1, bool tame = false);

        bool setName(const std::string& name);

        std::string getName();

        void setCategory(const Category& n_category);

        std::string getCategory();

        bool setHitpoints (const int& hitpoints);

        int getHitpoints();

        bool setLevel(const int& level);

        int getLevel();

        void setTame(const bool& tame);

        bool isTame();

        void display();

    private:
        std::string name_;
        Category category_;
        int hitpoints_;
        int level_;
        bool is_tame_;
        

};
#endif