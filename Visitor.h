#ifndef VISITOR_H
#define VISITOR_H

class Visitor {
    public:
        double taxCollected;
        virtual void visit(class Citizen* citizen) = 0;
        virtual void visit(class Building* building) = 0;
        virtual void citySatisfaction(class Citizen* citizen){};
        virtual void citySatisfaction(class Building* building){};
        virtual void transportSatisfaction(class Citizen* citizen){};
        virtual void buildingSatisfaction(class Citizen* citizen){};
};

#endif
