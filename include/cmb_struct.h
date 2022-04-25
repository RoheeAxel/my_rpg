/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** combat structs
*/

#pragma once

typedef enum combat_player_state {
    RPG_COMBAT_PLAYER_IDLE,
    RPG_COMBAT_PLAYER_ATTACK,
    RPG_COMBAT_PLAYER_ATTACKED,
    RPG_COMBAT_PLAYER_PROTECT,
    RPG_COMBAT_PLAYER_DEATH
} e_combat_player_state;

typedef enum combat_state {
    RPG_COMBAT_PENDING,
    RPG_COMBAT_ATTACKING,
    RPG_COMBAT_DEATH,
    RPG_COMBAT_ENNEMY
} e_combat_state;

typedef struct gauge_bar {
    sfRectangleShape *rect;
    sfRectangleShape *rect_grey;
    sfColor color;
    sfColor grey_color;
    sfVector2f pos;
    sfVector2f size;
} gauge_bar_t;

typedef struct stats {
    int level;
    int attack;
    int defense;
} stats_t;

typedef struct entity {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    gauge_bar_t *bar;
    bool is_npc;
    int rect_left_i;
    int rect_left_w;
    int life;
    stats_t *stat;
    e_combat_player_state cmb_state;
} entity_t;

typedef struct sfx {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sfx_t;

typedef struct hud {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    bool is_active;
} hud_t;

typedef struct combat {
    hud_t *hud;
    hud_t *slash;
    entity_t *ennemy;
    entity_t *player;
    sfx_t *sfx;
    e_combat_state state;
} combat_t;