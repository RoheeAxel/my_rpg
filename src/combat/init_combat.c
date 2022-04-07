/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** combat main file
*/

#include <stdlib.h>

#include "my_rpg.h"

static int create_ennemy(combat_t *com)
{
    com->ennemy->texture = sfTexture_createFromFile(BOSS_PATH, NULL);
    if (!com->ennemy->texture)
        return 1;
    com->ennemy->sprite = sfSprite_create();
    sfSprite_setTexture(com->ennemy->sprite, com->ennemy->texture, sfTrue);
    com->ennemy->pos = (sfVector2f){RES_X / 5, RES_Y / 3};
    sfSprite_setPosition(com->ennemy->sprite, com->ennemy->pos);
    com->ennemy->rect = (sfIntRect){0, 0, BOSS_WIDTH, BOSS_HEIGHT};
    sfSprite_setTextureRect(com->ennemy->sprite, com->ennemy->rect);
    sfSprite_setScale(com->ennemy->sprite, (sfVector2f){2, 2});
    com->ennemy->clock = sfClock_create();
    return 0;
}

static int create_player(combat_t *com)
{
    com->player->texture = sfTexture_createFromFile(OLBERIC_PATH, NULL);
    if (!com->player->texture)
        return 1;
    com->player->sprite = sfSprite_create();
    sfSprite_setTexture(com->player->sprite, com->player->texture, sfTrue);
    com->player->pos = (sfVector2f){RES_X / 1.5, RES_Y / 1.7};
    sfSprite_setPosition(com->player->sprite, com->player->pos);
    com->player->rect = (sfIntRect){687, 0, OLBERIC_WIDTH, OLBERIC_HEIGHT};
    sfSprite_setTextureRect(com->player->sprite, com->player->rect);
    sfSprite_setScale(com->player->sprite, (sfVector2f){2.5, 2.5});
    com->player->clock = sfClock_create();
    com->player->rect_left_i = 0;
    com->player->rect_left_w = 0;
    com->player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    com->state = RPG_COMBAT_CHOOSE;
    return 0;
}

combat_t *init_combat(rpg_t *rpg)
{
    combat_t *combat = malloc(sizeof(combat_t));

    if (!combat)
        return NULL;
    combat->ennemy = malloc(sizeof(entity_t));
    combat->player = malloc(sizeof(entity_t));
    if (!combat->ennemy || !combat->player)
        return NULL;
    if (create_ennemy(combat) || create_player(combat) || create_hud(combat))
        return NULL;
    return combat;
}