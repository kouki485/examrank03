#ifndef GNL_H
#define GNL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
char *get_next_line(int fd);
#endif