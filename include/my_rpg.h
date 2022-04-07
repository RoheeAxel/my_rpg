/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header main file
*/

#pragma once

#include <stdbool.h>

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>

#include "struct.h"

#include "defines.h"

// UTILS
int init_sfml(rpg_t *rpg);
float get_time(sfClock *clock);
float get_dt(sfClock *game_clock);
void free_rpg(rpg_t *rpg);
bool do_aabb_mouse(sfMouseMoveEvent mouse, sfSprite *sp);
bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2);

// USER INTERFACE
int create_hud(combat_t *combat);

// COMBAT
combat_t *init_combat(rpg_t *rpg);
void combat_loop(rpg_t *rpg, combat_t *combat);
void combat_on_click(void *btn);
void combat_not_on_hover(void *btn);
void combat_on_hover(void *btn);

//map
sfVector2f to2d(sfVector3f p, rpg_t *game);
void draw_map(rpg_t *rpg);
int **create_map(int heigth, int width);