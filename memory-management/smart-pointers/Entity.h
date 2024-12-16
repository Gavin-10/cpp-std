#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
    public:
        Entity();
        ~Entity();
    
    public:
        void print() const;

    private:
        static int count;
};

#endif