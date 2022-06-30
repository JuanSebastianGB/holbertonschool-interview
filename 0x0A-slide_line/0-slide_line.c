#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
  size_t i;
  int temp;

  if (direction == SLIDE_LEFT)
  {
    for (i = 0; i < size - 1; i++)
    {
      temp = line[i];
      line[i] = line[i + 1];
      line[i + 1] = temp;
    }
  }
  else
  {
    for (i = size - 1; i > 0; i--)
    {
      temp = line[i];
      line[i] = line[i - 1];
      line[i - 1] = temp;
    }
  }

  return (EXIT_SUCCESS);
}
