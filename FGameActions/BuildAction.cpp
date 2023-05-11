#include <string>

//Includes all headers from units

void createUnit(Player* actualPlayer, AUnit *unit)
{
    if (actualPlayer->getGold() >= unit->getCost())
    {
        actualPlayer->setGold(actualPlayer->getGold() - unit->getCost());
        actualPlayer->getBaseData()->addUnitToCreate(*unit);
    }
}

void BuildAction(Player* actualPlayer, std::string *words)
{
    //First, check if id is equal to player and base isn't in building state
    if (actualPlayer->getBaseData()->getIndex() == stoi(words[0]) && !actualPlayer->getBaseData()->isBuilding())
    {
        char* array = new char[words[2].length() + 1];

        strcpy(array, words[2].c_str());

        //Create a appropriately unit from char
        //Susbstracting gold from player by cost of unit.
        switch(array[0])
        {
            case 'K':
            {
                Knight *k = new Knight();
                createUnit(actualPlayer, (AUnit*) k);
                delete k;
                delete array;
                return;
            }
            case 'S':
            {
                Swordsman *s = new Swordsman();
                createUnit(actualPlayer, (AUnit*) s);
                delete s;
                delete array;
                return;
            }                       
            case 'A':
            {
                Archer *a = new Archer();
                createUnit(actualPlayer, (AUnit*) a);
                delete a;
                delete array;
                return;
            }
            case 'P':
            {
                Pikeman *p = new Pikeman();
                createUnit(actualPlayer, (AUnit*) p);
                delete p;
                delete array;
                return;
            }
            case 'C':
            {
                Catapult *c = new Catapult();
                createUnit(actualPlayer, (AUnit*) c);
                delete c;
                delete array;
                return;
            }
            case 'R':
            {
                Ram *r = new Ram();
                createUnit(actualPlayer, (AUnit*) r);
                delete r;
                delete array;
                return;
            }
            case 'W':
            {
                Worker *w = new Worker();
                createUnit(actualPlayer, (AUnit*) w);
                delete w;
                delete array;
                return;
            }
            default:
            {
                std::cout << "Unit doesn't exist" << std::endl;
                delete array;
                return;
            }
        }
        delete array;
        return;
    }
    return;
}