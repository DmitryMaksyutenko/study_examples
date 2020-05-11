#define _DEFAULT_SOURCE

#include <sys/types.h>
#include <grp.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


int initGroups(const char *user, gid_t group) {
  if (user == NULL) return -1;

  struct group *grp = getgrnam(user);
  if (grp == NULL) return -1;

  gid_t list[2];
  list[0] = grp->gr_gid;
  list[1] = group;
  setgroups(2, list); // sudo requiered.

  return 0;
}

int main() {

  if(initGroups("tty", 2) != 0)
    printf("initGroups failed!\n");

  gid_t *g = malloc(16 * sizeof(gid_t));
  getgroups(16, g);

  for (int i = 0; i < 16; i++)
    printf("%i\n", g[i]);

  free(g);

  exit(EXIT_SUCCESS);
}
