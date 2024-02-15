/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 2
*/
#ifndef MINDFLAYER_HPP_
#define MINDFLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "Creature.hpp"

class Mindflayer : public Creature {
    public:
        enum Variant {PSIONIC, TELEPATHIC, ILLUSIONARY};

        struct Projectile {
            Variant type_;
            int quantity_;
        };

        Mindflayer();

        Mindflayer(const std::string& name, Category c_category = ALIEN, int hitpoints = 1, int level = 1, bool tame = false, std::vector<Projectile> missle = std::vector<Projectile>(), bool summon = false, std::vector<Variant> affinity = std::vector<Variant>());

        void setProjectiles(const std::vector<Projectile>& missle);

        std::vector<Projectile> getProjectiles() const;

        void setSummoning(const bool& summon);

        bool getSummoning() const;

        void setAffinities(const std::vector<Variant>& affinity);

        std::vector<Variant> getAffinities() const;

        std::string variantToString(const Variant& v_variant);

    private:
        std::vector<Projectile> projectiles_;
        std::vector<Variant> affinities_;
        bool summoning_;
        std::string name_;
        Category category_;
        int hitpoints_;
        int level_;
        bool is_tame_;

};

#endif