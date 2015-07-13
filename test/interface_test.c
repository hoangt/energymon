#include <stdio.h>
#include <assert.h>

#define EM_DEFAULT
#include "energymon.h"

int main() {
  em_impl impl;
  em_impl_get(&impl);

  char source[100];
  impl.fsource(source);
  printf("Initializing reading from %s\n", source);
  assert(impl.finit(&impl) == 0);
  long long result = impl.fread(&impl);
  assert(result >= 0);
  printf("Got reading: %lld\n", result);
  assert(impl.ffinish(&impl) == 0);
  printf("Finished reading from %s\n", source);

  return 0;
}