#include "codexion.h"

void  compile(t_coder *coder)
{
  printf("Compiling...\n");
  sleep(1);
  printf("%d", coder->dongle_hold);
  printf("done\n");
}

void  debug(t_coder *coder)
{
  printf("Debuging...\n");
  usleep(2+coder->dongle_hold);
  printf("done!\n");
}

void  refactor(t_coder *coder)
{
  printf("Refactoring...\n");
  usleep(2+coder->dongle_hold);
  printf("done!\n");
}

