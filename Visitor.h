#ifndef VISITOR_H
#define VISITOR_H

class Visitor {
    public:
        double taxCollected;
        virtual void visit(class Citizen* citizen) = 0;
        virtual void visit(class Building* building) = 0;
};

#endif
