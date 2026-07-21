#include "codexion.h"

static void routine(t_coder *coder)
{
  compile(coder);
  coder->compile_done++;
  debug(coder);
  refactor(coder);
}

static void coder_thread(t_coder *coder)
{
  t_coder *self;

  if(!coder)
    return;
  self = coder;
  routine(self);

}

void  process(t_all *all)
{
  t_coder *tmp;
  tmp = all->coder;
  if (!all || !tmp)
    return;
  printf("processing...\n");
  while(tmp)
  {
    pthread_create(&tmp->thread, NULL, (void *)coder_thread, tmp);
    tmp = tmp->next;
  }
  tmp = all->coder;
  while (tmp)
  {
    pthread_join(tmp->thread, NULL);
    tmp = tmp->next;
  }
}
