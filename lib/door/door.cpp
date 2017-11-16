#include <sstream>
#include "action.h"
#include "door.hpp"
#include "stdbool.h"
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9

typedef struct action door;

using namespace std;
class Door {
 private:
  action* door = (action*)malloc(sizeof(action));

 public:
  door(char* name, char* state, int pinOut) {
    door->name = name;
    door->state = state;
    door->type = "door";
    door->id = nextid();
    door->pinOut = pinOut;

    Serial.begin(9600);	
    SPI.begin();
    mfrc522.PCD_Init();
  }

  String rfid(){  
  if (! mfrc522.PICC_IsNewCardPresent()){
    return "";
  }
  // Select one of the cards
  if (! mfrc522.PICC_ReadCardSerial()){
    return "";
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  for (byte i = 0; i < mfrc522.uid.size; i++){
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  // formata o MAC address como caixa alta
  conteudo.toUpperCase();
  // Salva apenas o MAC address na string
  String idCard = conteudo.substring(1);
  return idCard;
  
}

  int toggle() {
    int state = 0;
    if (door->state == "open") {
      door->state = "close";
      state = 1;
    } else {
      door->state = "";
      state = 0;
    }
    return state;
  }

  string getSync(bool comma) {
    stringstream json;
    json << "{";
    json << "actionname: " << door->name << ",";
    json << "actionid: " << door->id << ", ";
    json << "type: " << door->type << ", ";
    json << "state: " << door->state << ", ";
    json << "}";
    if (comma) {
      json << ",";
    }
    return json.str();
  }
}