#include "action.h"
#include "light.h"
#include "stdbool.h"

typedef struct action light;

void light(char* name, char* state){
  action *light = (action*) malloc(sizeof(action));
  light->name = name;
  light->state = state;
  light->type = "light";
  light->id = nextid();
}