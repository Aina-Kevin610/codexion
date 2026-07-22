#include "codexion.h"

int is_simulation_finished(t_all *all)
{
  t_coder *tmp;

  tmp = all->coder;
  pthread_mutex_lock(&all->lock);
  while(tmp)
  {
    if(tmp->compile_done < all->arguments->nb_compiles)
    {
      pthread_mutex_unlock(&all->lock);
      all->stop = 0;
      return (0);
    }
    tmp = tmp->next;
  }
  all->stop = 1;
  pthread_mutex_unlock(&all->lock);
  return (1);
}
