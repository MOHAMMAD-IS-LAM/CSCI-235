#include "Creature.hpp"

int main() {
    Creature Albert;
    Albert.setHitpoints(10);
    Albert.setLevel(5);
    Albert.setTame(true);

    Albert.display();

    Creature Wormy("Wormy", Creature::MYSTICAL, 3, 2);
    Wormy.setTame(true);

    Wormy.display();
    return 0;
}