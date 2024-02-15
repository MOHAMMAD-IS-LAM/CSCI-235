#include "Dragon.hpp"
#include "Creature.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"

int main() {

    Dragon Albert;
    Albert.display();
    std::cout << "ELEMENT: " << Albert.getElement() << std::endl;
    std::cout << "HEADS: " << Albert.getNumberOfHeads() << std::endl;
    std::cout << "FLIGHT: " << (Albert.getFlight() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std::endl;

    Dragon Burny("Burney", Creature::UNDEAD, 100, 10, true, Dragon::FIRE, 1, true);

    Burny.display();
    std::cout << "ELEMENT: " << Burny.getElement() << std::endl;
    std::cout << "HEADS: " << Burny.getNumberOfHeads() << std::endl;
    std::cout << "FLIGHT: " << (Burny.getFlight() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std::endl;

    Burny.setElement(Dragon::WATER);
    Burny.setNumberOfHeads(2);
    Burny.setNumberOfHeads(0);
    Burny.setFlight(false);

    Burny.display();
    std::cout << "ELEMENT: " << Burny.getElement() << std::endl;
    std::cout << "HEADS: " << Burny.getNumberOfHeads() << std::endl;
    std::cout << "FLIGHT: " << (Burny.getFlight() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std::endl;

    Ghoul Fedrick;
    Fedrick.display();
    std::cout << "DECAY: " << Fedrick.getDecay() << std::endl;
    std::cout << "FACTION: " << Fedrick.getFaction() << std::endl;
    std::cout << "TRANSFORM: " << (Fedrick.getTransformation() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std:: endl;

    Ghoul Homph("Chomper", Creature::ALIEN, 100, 10, true, 3, Ghoul::FLESHGORGER, true);

    Homph.display();
    std::cout << "DECAY: " << Homph.getDecay() << std::endl;
    std::cout << "FACTION: " << Homph.getFaction() << std::endl;
    std::cout << "TRANSFORM: " << (Homph.getTransformation() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std:: endl;

    Homph.setDecay(2);
    Homph.setDecay(-20);
    Homph.setFaction(Ghoul::SHADOWSTALKER);
    Homph.setTransformation(false);

    Homph.display();
    std::cout << "DECAY: " << Homph.getDecay() << std::endl;
    std::cout << "FACTION: " << Homph.getFaction() << std::endl;
    std::cout << "TRANSFORM: " << (Homph.getTransformation() ? "TRUE" : "FALSE") << std::endl;
    std::cout << std:: endl;

    Mindflayer Steven;

    Steven.display();
    std::cout << "SUMMONING: " << (Steven.getSummoning() ? "TRUE" : "FALSE") << std::endl; 
    for (int i = 0; i < Steven.getProjectiles().size(); i++) {
        std::cout << Steven.getProjectiles()[i].type_ << ": " << Steven.getProjectiles()[i].quantity_ << std::endl;
    }
    std::cout << "AFFINITIES: " << std::endl;
    for (int q = 0; q < Steven.getAffinities().size(); q++) {
        std::cout << Steven.getAffinities()[q] << std::endl;
    }
    std::cout << std::endl;

    Mindflayer Bigbrain("bigbrain", Creature::MYSTICAL, 100, 10, true, {{Mindflayer::PSIONIC, 2}, {Mindflayer::TELEPATHIC, 1}, {Mindflayer::PSIONIC, 1}, {Mindflayer::ILLUSIONARY, 3}}, true, {Mindflayer::PSIONIC, Mindflayer::TELEPATHIC, Mindflayer::PSIONIC, Mindflayer::ILLUSIONARY});

    Bigbrain.display();
    std::cout << "SUMMONING: " << (Bigbrain.getSummoning() ? "TRUE" : "FALSE") << std::endl; 
    for (int i = 0; i < Bigbrain.getProjectiles().size(); i++) {
        std::cout << Steven.variantToString(Bigbrain.getProjectiles()[i].type_) << ": " << Bigbrain.getProjectiles()[i].quantity_ << std::endl;
    }
    std::cout << "AFFINITIES: " << std::endl;
    for (int q = 0; q < Bigbrain.getAffinities().size(); q++) {
        std::cout << Bigbrain.variantToString(Bigbrain.getAffinities()[q]) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}  