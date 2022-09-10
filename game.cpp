#include "mbed.h"
#include "uLCD_4DGL.h"
#include "game.h"
#include "sprite.h"

ShipControl::ShipControl()
{
    ShipControlX = 64;
    ShipControlY = 110;
}

void ShipControl::draw(uLCD_4DGL & LCD)
{
    LCD.BLIT(ShipControlX, ShipControlY, 19, ALIEN_HEIGHT, ship_sprite);
}

void ShipControl::shiftRight()
{
    if (ShipControlX < 118)
    {
        ShipControlX += 2;
    }
}

void ShipControl::shiftLeft()
{
    if (ShipControlX > 10)
    {
        ShipControlX -= 2;
    }
}

int ShipControl::positionX()
{
    return ShipControlX;
}

int ShipControl::positionY()
{
    return ShipControlY;
}

ShipGun::ShipGun(): singleShipGun(false) {}

void ShipGun::shootShipGun(ShipControl &s1, uLCD_4DGL &LCD)
{
    ShipGunX = s1.positionX() + ALIEN_HEIGHT;
    ShipGunY = s1.positionY() - 4;

    LCD.filled_circle(ShipGunX, ShipGunY, 3, WHITE);
}

void ShipGun::shiftShipGun(uLCD_4DGL & LCD)
{
    if (ShipGunY >= 4 && singleShipGun == true)
    {
        ShipGunY -= 2;
        LCD.filled_circle(ShipGunX, ShipGunY + 2, 3, BLACK);
        LCD.filled_circle(ShipGunX, ShipGunY, 3, WHITE);
        if (ShipGunY < 4)
        {
            LCD.filled_circle(ShipGunX, 2, 6, BLACK);
            singleShipGun = false;
        }
    }
}

void ShipGun::setShipGun(bool b)
{
    singleShipGun = b;
}

bool ShipGun::getShipGun()
{
    return singleShipGun;
}

int ShipGun::getShipGunX()
{
    return ShipGunX;
}

int ShipGun::getShipGunY()
{
    return ShipGunY;
}

//Start of Inheritance-Structure Classes-----------------

void ScreenObjects::changePositionX(int s)
{
    if (PositionX < 110 && direc == true)
    {
        PositionX += s;
        if (PositionX >= 110)
        {
            direc = false;
            PositionX = 109;
        }
    }
    else if (PositionX < 110 && direc == false)
    {
        PositionX -= s;
        if (PositionX <= 10)
        {
            direc = true;
            PositionX = 11;
        }
    }
}

bool ScreenObjects::directHit(ShipGun & b1)
{
    int bPositionX = b1.getShipGunX();
    int bPositionY = b1.getShipGunY();

    hit = ((bPositionX >= (PositionX - 7)) && (bPositionX <= (PositionX + 7)) && (bPositionY >= (PositionY - 5)) && (bPositionY <= (PositionY + 5)));
    return hit;
}

//Start of 
void ScreenObjects::blackScreen(uLCD_4DGL & LCD)
{
    LCD.BLIT(PositionX, PositionY, ALIEN_WIDTH, ALIEN_HEIGHT, blacksprite);
}

void ScreenObjects::setPositionX(int x)
{
    PositionX = x;
}

void ScreenObjects::setPositionY(int y)
{
    PositionY = y;
}

void ScreenObjects::setDirec(bool d)
{
    direc = d;
}

int ScreenObjects::positionX()
{
    return PositionX;
}

int ScreenObjects::positionY()
{
    return PositionY;
}

AlienBob::AlienBob(int n)
{
    setPositionX(18 + rand() % 110);
    setPositionY((10 + 10 *(n - 1)) + rand() % 2);
    setDirec(true);
}

void AlienBob::draw(uLCD_4DGL & LCD)
{
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
}

void AlienBob::update(uLCD_4DGL & LCD)
{
    changePositionX(1);
    int res = positionX() % 2;
    switch (res)
    {
        case (0):
            {
                LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobDown_sprite);
                break;
            }

        case (1):
            {
                LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
                break;
            }
    }
}

AlienAlice::AlienAlice(int n)
{
    setPositionX(18 + rand() % 110);
    setPositionY((10 + 10 *(n - 1)) + rand() % 2);
    setDirec(true);
}

void AlienAlice::draw(uLCD_4DGL & LCD)
{
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, alienAlice_sprite);
}

void AlienAlice::update(uLCD_4DGL & LCD)
{
    changePositionX(2);
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, alienAlice_sprite);
}

AlienJoe::AlienJoe(int n)
{
    setPositionX(18 + rand() % 110);
    setPositionY((10 + 10 *(n - 1)) + rand() % 2);
    setDirec(true);
}

void AlienJoe::draw(uLCD_4DGL & LCD)
{
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, AlienJoe_sprite);
}

void AlienJoe::update(uLCD_4DGL & LCD)
{
    changePositionX(2);
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, AlienJoe_sprite);
}

AlienMark::AlienMark(int n)
{
    setPositionX(18 + rand() % 110);
    setPositionY((10 + 10 *(n - 1)) + rand() % 2);
    setDirec(true);
}

void AlienMark::draw(uLCD_4DGL & LCD)
{
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, AlienMark_sprite);
}

void AlienMark::update(uLCD_4DGL & LCD)
{
    changePositionX(2);
    LCD.BLIT(positionX(), positionY(), ALIEN_WIDTH, ALIEN_HEIGHT, AlienMark_sprite);
}