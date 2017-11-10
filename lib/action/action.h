#ifndef LIGHT_H_
#define LIGHT_H_


typedef struct {
  char* name;
  char* state;
  char* type;
  unsigned int id;
  unsigned int pinOut;
} action;

int nextid ( ) {
  static int last = 0;
  return ++last;
}

#endif