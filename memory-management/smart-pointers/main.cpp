
#include "Entity.h"

#include <memory>
#include <iostream>

int main() {
    {
        //very simple, cant copy
        //option: std::unique_ptr<Entity> entity(new Entity());
        //prefered
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->print();
    }

    {
        //note scope doesnt matter
        std::shared_ptr<Entity> e1;
        //note scope matters
        std::weak_ptr<Entity> e2;
        {
            //uses reference counting to keep track
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // number 1
            std::shared_ptr<Entity> secondEntity = std::make_shared<Entity>(); // number 2
            //Dont: std::shared_ptr<Entity> sharedEntity(new Entity())
            //normal way constructs entity and control block together

            //weak pointers copy shared pointers without increasing ref count
            //aka not responsible to keep pointer alive
            e2 = secondEntity;

            std::shared_ptr<Entity> e0 = sharedEntity;
            e1 = e0;

            std::cout << "End of second scope" << std::endl;
        }

        std::cout << "End of first scope" << std::endl;
    }

    return 0;
}