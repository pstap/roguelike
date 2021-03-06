#ifndef GEOM_H
#define GEOM_H

/*
 * geometry.h
 * Basic structs/functions for handling geometry/the grid
 *
 */

#include <stdint.h>

struct point
{
	uint32_t x;
	uint32_t y;
};

typedef struct point point_t;

#endif
