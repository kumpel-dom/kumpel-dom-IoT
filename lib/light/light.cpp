#include <sstream>

#include "action.h"
#include "light.h"
#include "stdbool.h"

typedef struct action light;

using namespace std;
class Light {
 private:
  action* light = (action*)malloc(sizeof(action));

 public:
  Light(char* name, char* state, int pinOut) {
    light->name = name;
    light->state = state;
    light->type = "light";
    light->id = nextid();
    light->pinOut = pinOut;
  }
  int toggle() {
    int state = 0;
    if (light->state == "off") {
      light->state = "on";
      state = 1;
    } else {
      light->state = "off";
      state = 0;
    }
    return state;
  }

  string getSync() {
    stringstream json;
    json << "actionname: " << light->name << ",";
    json << "actionid: " << light->id << ", ";
    json << "type: " << light->type << ", ";
    json << "state: " << light->state << ", ";

    return json.str();
  }
}
