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
    LA5, LA4, LA3, LA2, LA1, RA5, RA4, RA3, RA2, RA1, \
    LB5, LB4, LB3, LB2, LB1, RB5, RB4, RB3, RB2, RB1, \
    LC5, LC4, LC3, LC2, LC1, RC5, RC4, RC3, RC2, RC1, \
    LTA3, LTA2, LTA1, RTA3, RTA2, RTA1, \
    LTB3, LTB2, LTB1, RTB3, RTB2, RTB1 \
) { \
    { LA5, LA4, LA3, LA2, LA1, RA1, RA2, RA3, RA4, RA5 }, \
    { LB5, LB4, LB3, LB2, LB1, RB1, RB2, RB3, RB4, RB5 }, \
    { LC5, LC4, LC3, LC2, LC1, RC1, RC2, RC3, RC4, RC5 }, \
    { LTA3, LTA2, LTA1, KC_NO, KC_NO, KC_NO, KC_NO, RTA1, RTA2, RTA3 }, \
    { LTB3, LTB2, LTB1, KC_NO, KC_NO, KC_NO, KC_NO, RTB1, RTB2, RTB3 } \
}
