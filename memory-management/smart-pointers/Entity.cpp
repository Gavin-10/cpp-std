#include "Entity.h"

#include <iostream>

int Entity::count{0};

Entity::Entity() {
    Entity::count++;
    std::cout << "Entity Created: " << Entity::count << " Entities" << std::endl;
}

Entity::~Entity() {
    Entity::count--;
    std::cout << "Entity Destroyed: " << Entity::count << " Entitiees" << std::endl;
}

void Entity::print() const {
    std::cout << "Printing" << std::endl;
}