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
    // LA5, LA4, LA3, LA2, LA1, \
    // LB5, LB4, LB3, LB2, LB1, \
    // LC5, LC4, LC3, LC2, LC1, \
    // LD3, LD2, LD1, \
    // LE3, LE2, LE1, \
    // RA5, RA4, RA3, RA2, RA1, \
    // RB5, RB4, RB3, RB2, RB1, \
    // RC5, RC4, RC3, RC2, RC1, \
    // RD3, RD2, RD1, \
    // RE3, RE2, RE1 \
    {  LA1, LA2, LA3, LA4, LA5, RA1, RA2, RA3, RA4, RA5 }, \
    {  LB1, LB2, LB3, LB4, LB5, RB1, RB2, RB3, RB4, RB5 }, \
    {  LC1, LC2, LC3, LC4, LC5, RC1, RC2, RC3, RC4, RC5 }, \
    {  KC_NO, KC_NO, LD1, LD2, LD3, KC_NO, KC_NO, RD1, RD2, RD3 }, \
    {  KC_NO, KC_NO, LE1, LE2, LE3, KC_NO, KC_NO, RE1, RE2, RE3 } \
 */
#define LAYOUT( \
    LA5, LA4, LA3, LA2, LA1, \
    LB5, LB4, LB3, LB2, LB1, \
    LC5, LC4, LC3, LC2, LC1, \
    LD3, LD2, LD1, \
    LE3, LE2, LE1 \
) { \
    {  LA1, LA2, LA3, LA4, LA5 }, \
    {  LB1, LB2, LB3, LB4, LB5 }, \
    {  LC1, LC2, LC3, LC4, LC5 }, \
    {  KC_NO, KC_NO, LD1, LD2, LD3 }, \
    {  KC_NO, KC_NO, LE1, LE2, LE3 } \
}
