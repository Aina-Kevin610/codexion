#include "codexion.h"

void  compile(int time_to_compile)
{
  printf("Compiling...");
  usleep(time_to_compile);
  printf("done!");
}

void  debug(int time_to_debug)
{
  printf("Debuging...");
  usleep(time_to_debug);
  printf("done!");
}

void  refactor(int time_to_refactor)
{
  printf("Rfactoring...");
  usleep(time_to_refactor);
  printf("done!");
}

