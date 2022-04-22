/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** world structs
*/

#pragma once

typedef struct render {
    sfVector2f *point;
    sfVertexArray *triangle;
} render_t;

typedef struct camera {
    float x;
    float y;
    float r;
    render_t *render;
} camera_t;

typedef struct world {
    int **height_map;
    int **texture_map;
    sfClock *water_clock;
    int **object_map;
} world_t;

typedef struct perlin {
    float tmp;
    float s;
    float t;
    float u;
    float v;
    float Cx;
    float Cy;
    float Li1;
    float Li2;
    int gi0;
    int gi1;
    int gi2;
    int gi3;
} perlin_t;
