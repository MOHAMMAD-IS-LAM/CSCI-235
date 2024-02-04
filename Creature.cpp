/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 1 interface (This is a .hpp file that includes all of the hidden code).
*/

#include "Creature.hpp"

Creature::Creature() {
   name_ = "NAMELESS";
   hitpoints_ = 1;
   level_ = 1;
   is_tame_ = false;
   category_ = UNKNOWN;
}

Creature::Creature(std::string name, Category c_category, int level, int hitpoints, bool tame) {
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
}

bool Creature::setName(const std::string& name) {
   for (int q = 0; q < name.length(); q++) {
         if (!isalpha(name[q])) {
            return false;
            break;
         }
   }
   name_ = name;
   for (int k = 0; k < name_.length(); k++) {
      name_[k] = toupper(name_[k]);
   }
   return true;   
}

std::string Creature::getName() {
   return name_;
}

void Creature::setCategory(const Category& n_category) {
   switch(n_category) {
         case UNDEAD : category_ = UNDEAD; break;
         case MYSTICAL : category_ = MYSTICAL; break;
         case ALIEN : category_ = ALIEN; break;
         case UNKNOWN : category_ = UNKNOWN; break;
         default : category_ = UNKNOWN;
   }
}

std::string Creature::getCategory() {
   std::string category;
   switch (category_) {
         case UNDEAD : category = "UNDEAD"; break;
         case MYSTICAL : category = "MYSTICAL"; break;
         case ALIEN : category = "ALIEN"; break;
         case UNKNOWN : category = "UNKNOWN"; break;
   }
   return category;
}

bool Creature::setHitpoints (const int& hitpoints) {
   if (hitpoints >= 0) {
         hitpoints_ = hitpoints;
         return true;
   }
   else {
         return false;
   }
}

int Creature::getHitpoints() {
   return hitpoints_;
}

bool Creature::setLevel(const int& level) {
   if (level >= 0) {
         level_ = level;
         return true;
   }
   else return false;
}

int Creature::getLevel() {
   return level_;
}

void Creature::setTame(const bool& tame) {
   is_tame_ = &tame;
}

bool Creature::isTame() {
   return is_tame_;
}

void Creature::display() {
   std::cout << getName() << std::endl;
   std::cout << "Category: " << getCategory() << std::endl;
   std::cout << "Level: " << getLevel() << std::endl;
   std::cout << "Hitpoints: " << getHitpoints() << std::endl;
   std::cout << "Tame: " << (isTame() ? "Yes" : "No") << std::endl;
}