 #ifndef ITEM_H_
#define ITEM_H_

class Item {
public:
    // too lazy to make subclasses
    const static int CONSUM = 0; // (consumable) items can be used but not moved (Keyword USE)
    const static int ENEMY = 1; // items will turn into DEF after fought (Keyword FIGHT)
    const static int BOSS = 2; // items will disappear after fought (Keyword FIGHT)
    const static int DEF = 3; // (default) items can be stored in inventory (Keyword GRAB)
    Item(int type, char name[], int boost, int strength);
    ~Item();
    int getType();
    char* getName();
    void switchType(); // switch to alternative type
    int getBoost();
    int getStrength();

private:
    int type;
    char* name;
    int boost; // for consumables
    int strength; // for fightables
    
};

#endif
