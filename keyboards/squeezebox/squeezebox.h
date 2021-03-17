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
    RA5, RA4, RA3, RA2, RA1, \
    RB5, RB4, RB3, RB2, RB1, \
    RC5, RC4, RC3, RC2, RC1, \
    RTA3, RTA2, RTA1, \
    RTB3, RTB2, RTB1 \
) { \
    { RTB1, RTB2, RTB3 }, \
    { RTA1, RTA2, RTA3 }, \
    { RC1, RC2, RC3, RC4, RC5 }, \
    { RB1, RB2, RB3, RB4, RB5 }, \
    { RA1, RA2, RA3, RA4, RA5 }\
}
