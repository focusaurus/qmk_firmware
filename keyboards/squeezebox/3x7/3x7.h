/* Copyright 2021 Peter Lyons
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
  LD1, \
  LE1, LE2, LE3, LE4, LE5 \
) { \
  { LA1, LA2, LA3, LA4, LA5, LE1, LE5 }, \
  { LB1, LB2, LB3, LB4, LB5, LE2, LE4 }, \
  { LC1, LC2, LC3, LC4, LC5, LD1, LE3 } \
}
