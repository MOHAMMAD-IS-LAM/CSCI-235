/*
Name: Mohammad Islam
Date: 2/1/2024
Class: CSCI 235
Assingment: Project 2
*/

#include "Mindflayer.hpp"
#include <vector>


Mindflayer::Mindflayer() {
    name_ = "NAMELESS";
    hitpoints_ = 1;
    level_ = 1;
    is_tame_ = false;
    category_ = ALIEN;
    summoning_ = false;
}

Mindflayer::Mindflayer(const std::string& name, Category c_category, int hitpoints, int level, bool tame, std::vector<Projectile> missle, bool summon, std::vector<Variant> affinity) : Creature(name, c_category, hitpoints, level, tame), projectiles_(missle), affinities_(affinity), summoning_(summon) {

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
        };

    projectiles_ = missle;

    affinities_ = affinity;

    summoning_ = summon;

    for (int i = 0; i < projectiles_.size(); i++) {
        for (int j = i + 1; j < projectiles_.size(); j++) {
            if (projectiles_[j].type_ < projectiles_[i].type_) {
                std::swap(projectiles_[j], projectiles_[i]);
            }
        }
    }

    for (int p = 0; p < projectiles_.size();) {
        if(projectiles_[p].quantity_ <= 0) {
            projectiles_.erase(projectiles_.begin() + p);
        }
        else {
            p++;
        }
    }

    for (int q = 1; q < projectiles_.size(); q++) {
        if (projectiles_[q].type_ == projectiles_[q - 1].type_) {
            projectiles_[q].quantity_ = projectiles_[q].quantity_ + projectiles_[q - 1].quantity_;
            projectiles_.erase(projectiles_.begin() + (q - 1));
            q--;
        }
    }

    for (int z = 0; z < affinities_.size(); z++) {
        for (int x = z + 1; x < affinities_.size(); x++) {
            if (affinities_[x] < affinities_[z]) {
                std::swap(affinities_[x], affinities_[z]);
            } 
        }
    }

    for (int t = 1; t < affinities_.size(); t++) {
        if(affinities_[t] == affinities_[t - 1]) {
            affinities_.erase(affinities_.begin() + (t - 1));
            t--;
        }
    }

}

void Mindflayer::setProjectiles(const std::vector<Projectile>& missle) {
    projectiles_ = missle;
    for (int i = 0; i < projectiles_.size(); i++) {
        for (int j = i + 1; j < projectiles_.size(); j++) {
            if (projectiles_[j].type_ < projectiles_[i].type_) {
                std::swap(projectiles_[j], projectiles_[i]);
            }
        }
    }

    for (int p = 0; p < projectiles_.size();) {
        if(projectiles_[p].quantity_ <= 0) {
            projectiles_.erase(projectiles_.begin() + p);
        }
        else {
            p++;
        }
    }

    for (int q = 1; q < projectiles_.size(); q++) {
        if (projectiles_[q].type_ == projectiles_[q - 1].type_) {
            projectiles_[q].quantity_ = projectiles_[q].quantity_ + projectiles_[q - 1].quantity_;
            projectiles_.erase(projectiles_.begin() + (q - 1));
            q--;
        }
    }
}

std::vector<Mindflayer::Projectile> Mindflayer::getProjectiles() const {
    return projectiles_;
}

void Mindflayer::setSummoning(const bool& summon) {
    summoning_ = summon;
}

bool Mindflayer::getSummoning() const {
    return summoning_;
}

void Mindflayer::setAffinities(const std::vector<Variant>& affinity) {
    affinities_ = affinity;
    for (int z = 0; z < affinities_.size(); z++) {
        for (int x = z + 1; x < affinities_.size(); x++) {
            if (affinities_[x] < affinities_[z]) {
                std::swap(affinities_[x], affinities_[z]);
            } 
        }
    }

    for (int t = 1; t < affinities_.size(); t++) {
        if(affinities_[t] == affinities_[t - 1]) {
            affinities_.erase(affinities_.begin() + (t - 1));
            t--;
        }
    }
}

std::vector<Mindflayer::Variant> Mindflayer::getAffinities() const {
    return affinities_;
}

std::string Mindflayer::variantToString(const Variant& v_variant) {
    std::string v;
    switch(v_variant) {
        case PSIONIC : v = "PSIONIC"; break;
        case TELEPATHIC : v = "TELEPATHIC"; break;
        case ILLUSIONARY : v = "ILLUSIONARY"; break;
    }
    return v;
}