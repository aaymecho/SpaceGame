class ShipControl
{
    private:
        int ShipControlX, ShipControlY;
    public:
        ShipControl();
    void draw(uLCD_4DGL &);
    void shiftRight();
    void shiftLeft();
    int positionX();
    int positionY();
};

class ShipGun
{
    private:
        int ShipGunX, ShipGunY;
    bool singleShipGun;
    public:
        ShipGun();
    void shootShipGun(ShipControl &, uLCD_4DGL &);
    void shiftShipGun(uLCD_4DGL &);
    void setShipGun(bool);
    bool getShipGun();
    int getShipGunX();
    int getShipGunY();
};

//Start of Inheritance-Structure Classes-----------------
class ScreenObjects
{
    private:
        int PositionX, PositionY;
        bool direc, hit;
    public:
        virtual void draw(uLCD_4DGL &) = 0;
        virtual void update(uLCD_4DGL &) = 0;
        bool directHit(ShipGun &);
        void blackScreen(uLCD_4DGL &);
        void changePositionX(int);
        void setPositionX(int);
        void setPositionY(int);
        void setDirec(bool);
        int positionX();
        int positionY();
};

class SpaceShip: public ScreenObjects 
{
    public:
        void modifyMovement();
        void draw(uLCD_4DGL &);
        void update(uLCD_4DGL &);
};

class Bullet: public ScreenObjects
{
    public:
        void modifyMovement();
        void draw(uLCD_4DGL &);
        void update(uLCD_4DGL &);
};

class AlienBob: public ScreenObjects
{
    public: AlienBob(int);
    void draw(uLCD_4DGL &);
    void update(uLCD_4DGL &);
};

class AlienAlice: public ScreenObjects
{
    public: AlienAlice(int);
    void draw(uLCD_4DGL &);
    void update(uLCD_4DGL &);
};

class AlienJoe: public ScreenObjects
{
    public: AlienJoe(int);
    void draw(uLCD_4DGL &);
    void update(uLCD_4DGL &);
};

class AlienMark: public ScreenObjects
{
    public: AlienMark(int);
    void draw(uLCD_4DGL &);
    void update(uLCD_4DGL &);
};