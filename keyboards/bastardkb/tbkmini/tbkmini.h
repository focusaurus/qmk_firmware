/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#define LAYOUT_half( \
  a1, a2, a3, a4, a5, a6, \
  b1, b2, b3, b4, b5, b6, \
  c1, c2, c3, c4, c5, c6, \
  a7, b7, c7 \
)\
{\
  { a1, a2, a3, a4, a5, a6, a7 }, \
  { b1, b2, b3, b4, b5, b6, b7 }, \
  { c1, c2, c3, c4, c5, c6, c7 } \
}
