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
    com->ennemy[0] = malloc(sizeof(entity_t));
    com->ennemy[0]->sprite = sfSprite_create();
    com->ennemy[0]->texture = sfTexture_createFromFile(BOSS_PATH, NULL);
    sfSprite_setTexture(com->ennemy[0]->sprite, com->ennemy[0]->texture, sfTrue);
    com->ennemy[0]->pos = (sfVector2f){RES_X / 5, RES_Y / 3};
    sfSprite_setPosition(com->ennemy[0]->sprite, com->ennemy[0]->pos);
    com->ennemy[0]->rect = (sfIntRect){0, 0, BOSS_WIDTH, BOSS_HEIGHT};
    sfSprite_setTextureRect(com->ennemy[0]->sprite, com->ennemy[0]->rect);
    sfSprite_setScale(com->ennemy[0]->sprite, (sfVector2f){2, 2});
    com->ennemy[0]->clock = sfClock_create();
    com->ennemy[0]->life = 1000;
    com->ennemy[0]->max_life = 1000;
    com->ennemy[0]->is_npc = true;
    com->ennemy[0]->stat = malloc(sizeof(stats_t));
    com->ennemy[0]->stat->attack = 10;
    com->ennemy[0]->stat->defense = 10;
    com->ennemy[0]->name = "boss";
    if (init_gauge_bar(com->ennemy[0]))
        return 1;
    return 0;
}

static void create_player_bis(combat_t *com)
{
    com->player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    com->state = RPG_COMBAT_PENDING;
    com->player->is_npc = false;
    com->player->stat = malloc(sizeof(stats_t));
    if (!com->player->stat)
        return;
    com->player->stat->attack = 10, com->player->stat->defense = 10;
    com->player->stat->life = 100, com->player->stat->level = 1;
    com->player->stat->xp = 0, com->player->stat->text_attack = NULL;
    com->player->stat->text_defense = NULL, com->player->stat->text_life = NULL;
    com->player->stat->text_level = NULL;
    com->player->stat->class = RPG_CLASS_WARRIOR;
}

static int create_player(combat_t *com)
{
    com->player->sprite = sfSprite_create();
    com->player->texture = sfTexture_createFromFile(OLBERIC_CL_PATH, NULL);
    if (!com->player->texture)
        sfSprite_setColor(com->player->sprite, sfRed);
    else
        sfSprite_setTexture(com->player->sprite, com->player->texture, sfTrue);
    com->player->pos = (sfVector2f){RES_X / 1.5, RES_Y / 1.7};
    sfSprite_setPosition(com->player->sprite, com->player->pos);
    com->player->rect = (sfIntRect){687, 0, OLBERIC_WIDTH, OLBERIC_HEIGHT};
    sfSprite_setTextureRect(com->player->sprite, com->player->rect);
    sfSprite_setScale(com->player->sprite, (sfVector2f){2.5, 2.5});
    com->player->clock = sfClock_create();
    com->player->rect_left_i = 0;
    com->player->rect_left_w = 0;
    com->player->life = 100;
    com->player->max_life = 100;
    create_player_bis(com);
    if (init_gauge_bar(com->player) || init_slash(com))
        return 1;
    return 0;
}

static int create_transt(transt_t *e)
{
    e->rect = sfRectangleShape_create();
    if (!e->rect)
        return 1;
    sfRectangleShape_setSize(e->rect, (sfVector2f){RES_X, RES_Y});
    sfRectangleShape_setFillColor(e->rect, sfColor_fromRGBA(0, 0, 0, 0));
    e->pos = (sfVector2f){0, 0};
    sfRectangleShape_setPosition(e->rect, e->pos);
    e->clock = sfClock_create();
    return 0;
}

void init_combat(rpg_t *rpg)
{
    rpg->combat = malloc(sizeof(combat_t));

    if (!rpg->combat)
        return;
    rpg->combat->ennemy = malloc(sizeof(entity_t *));
    rpg->combat->player = malloc(sizeof(entity_t));
    rpg->combat->transt = malloc(sizeof(transt_t));
    rpg->combat->curr_ennemy = malloc(sizeof(entity_t));
    if (!rpg->combat->ennemy || !rpg->combat->player || !rpg->combat->transt)
        return;
    create_ennemy(rpg->combat);
    create_player(rpg->combat);
    create_bear(rpg->combat);
    create_wolf(rpg->combat);
    create_hud(rpg->combat);
    create_transt(rpg->combat->transt);
    init_font(rpg);
}
