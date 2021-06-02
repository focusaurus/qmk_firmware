#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
*
* The first section contains all of the arguments representing the physical
* layout of the board and position of the keys.
*
* The second converts the arguments into a two-dimensional array which
* represents the switch matrix.
*/

#define LAYOUT( \
  LA1, LA2, LA3, LA4, LA5, \
  LB1, LB2, LB3, LB4, LB5, \
  LC1, LC2, LC3, LC4, LC5, \
  LD1, LD2, LD3, \
  LE1, LE2, LE3, \
  RA5, RA4, RA3, RA2, RA1, \
  RB5, RB4, RB3, RB2, RB1, \
  RC5, RC4, RC3, RC2, RC1, \
  RD3, RD2, RD1, \
  RE3, RE2, RE1 \
) { \
  { LA1, LA2, LA3, LA4, LA5, LD1, LE3 }, \
  { LB1, LB2, LB3, LB4, LB5, LD2, LE2 }, \
  { LC1, LC2, LC3, LC4, LC5, LD3, LE1 }, \
  { RA1, RA2, RA3, RA4, RA5, RD1, RE3 }, \
  { RB1, RB2, RB3, RB4, RB5, RD2, RE2 }, \
  { RC1, RC2, RC3, RC4, RC5, RD3, RE1 } \
}
