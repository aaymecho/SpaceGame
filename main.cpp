#include "mbed.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "Speaker.h"

#include "game.h"

#include "MMA8452.h"

#include <ctime>

#include <vector>

//Global Objects
PinDetect buttonFire(p23);
Serial pc(USBTX, USBRX);
uLCD_4DGL uLCD(p9, p10, p11);
MMA8452 acc(p28, p27, 100000);
Speaker speakerObject(p25);
Timer t;
ShipControl shipObject;
ShipGun ShipGunObject;

void pushFire(void);

// main function ------------------------------------------
int main() {
  std::srand(static_cast < unsigned int > (time(0)));
  time_t startTime;
   t.start();
  startTime = time(0); // timer starts
  //uLCD.display_control(LANDSCAPE_R);
  uLCD.cls();
  uLCD.baudrate(3000000);
  uLCD.background_color(BLACK);

  //    // START MESSAGE
  //    uLCD.printf("Invaders inbound!\nDefeat them and\n protect Earth!");
  //    for (int i = 0; i < 25; i++)
  //    {
  //        speakerObject.PlayNote(200+(i*50), 0.05, 0.1);
  //        speakerObject.PlayNote(250+(i*40), 0.05, 0.1);
  //    }
  //    
  //    wait(2.0);
  buttonFire.mode(PullUp);
  buttonFire.attach_deasserted( & pushFire);
  buttonFire.setSampleFrequency();
  wait(.01);

  uLCD.cls();

  //allocation of vectors
  vector < ScreenObjects * > alienObject;
  alienObject.resize(6);
  alienObject[0] = new AlienBob(1);
  alienObject[1] = new AlienMark(2);
  alienObject[2] = new AlienJoe(3);
  alienObject[3] = new AlienMark(4);
  alienObject[4] = new AlienJoe(5);
  alienObject[5] = new AlienAlice(6);

  for (int i = 0; i < 6; i++) {
    alienObject[i] -> draw(uLCD);
  }

  shipObject.draw(uLCD);

  bool finishedGame = false;

  int alienNum = 6;
  bool isHit[6] = {
    false
  };
  while (finishedGame == false) {
    //setup accelerometer
    if (ShipGunObject.getShipGun() == true) {
      ShipGunObject.shootShipGun(shipObject, uLCD);
      speakerObject.PlayNote(500, 0.05, 0.1);
      speakerObject.PlayNote(300, 0.05, 0.1);
    }

    while (ShipGunObject.getShipGun() == true) {
      double x = 0.0l;
      double y = 0.0l;
      double z = 0.0l;
      if (!acc.isXYZReady()) {
        wait(0.01);

      } else {
        acc.readXYZGravity( & x, & y, & z); //referenced using pointers
        if (x < 0.2) {
          shipObject.shiftRight();
        } else if (x > 0.2) {
          shipObject.shiftLeft();
        }
      }
      shipObject.draw(uLCD);
      ShipGunObject.shiftShipGun(uLCD);

      for (int i = 0; i < 6; i++) {
        if (alienNum < 1) {
          finishedGame = true;
          break;
        }

        if (isHit[i] == true) continue;

        isHit[i] = alienObject[i] -> directHit(ShipGunObject);

        if (isHit[i] == true) {
          --alienNum;
          alienObject[i] -> blackScreen(uLCD);
          speakerObject.PlayNote(200, 0.1, 0.1);
          speakerObject.PlayNote(350, 0.1, 0.1);

          uLCD.filled_circle(ShipGunObject.getShipGunX(), ShipGunObject.getShipGunY(), 8, BLACK);
          ShipGunObject.setShipGun(false);
        } else
          alienObject[i] -> update(uLCD);

      }
      wait(0.01);
    }

    while (ShipGunObject.getShipGun() == false) {
      double x = 0.0l;
      double y = 0.0l;
      double z = 0.0l;

      if (!acc.isXYZReady()) {
        wait(0.01);

      } else {
        acc.readXYZGravity( & x, & y, & z); //referenced using pointers
        if (x < 0.2) {
          shipObject.shiftRight();
        } else if (x > 0.2) {
          shipObject.shiftLeft();
        }
      }
      if (alienNum < 1) {
        finishedGame = true;
        break;
      }

      shipObject.draw(uLCD);
      for (int i = 0; i < 6; i++) {
        if (isHit[i] == true) continue;
        alienObject[i] -> update(uLCD);
      }
      wait(0.01);
    }
  }

  //deallocates vector
  for (int i = 0; i < 6; i++) {
    delete[] alienObject[0];
  }

  speakerObject.PlayNote(800, 0.1, 0.1);
  speakerObject.PlayNote(600, 0.1, 0.1);
  speakerObject.PlayNote(400, 0.1, 0.1);
  speakerObject.PlayNote(600, 0.1, 0.1);
  speakerObject.PlayNote(800, 0.1, 0.1);
  uLCD.cls();
  t.stop();
  time_t endTime = t.read();
  uLCD.printf("\n\n\n\n Congratulations!!\n\n Earth Saved!\n\n\n (%dSeconds)", endTime);
  wait(4.0);
  exit(0);
}

void pushFire(void) {
  ShipGunObject.setShipGun(true);
  speakerObject.PlayNote(800, 0.1, 0.1);
}