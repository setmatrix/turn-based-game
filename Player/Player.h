#include "../FData/FBaseData/Base.h"
#include "../FUnitOnBoard/UnitOnBoard.h"
#include <list>

class Player
{
    private:
        int gold;
        std::list<UnitOnBoard> units;
        Base *base;

    public:
        Player()
        {
            this->gold = 2000; 
        }
        Player(int _index, char _baseLetter, int _xCord, 
        int _yCord, bool _isOnBuild = false, char _unitType = 'B', int timeToBuild = -1) : Player()
        {
            base = new Base(_index, _baseLetter, _xCord, _yCord);
        }
        int getGold() {return this->gold;}
        void setGold(int _gold) {this->gold = _gold;}
        ~Player(){}

        std::list<UnitOnBoard> getUnitList()
        {
            return units;
        }
        void addUnit(UnitOnBoard _unit)
        {
            this->units.push_back(_unit);
        }
        Base getBase()
        {
            return *base;
        }
};