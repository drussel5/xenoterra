#include <stdio.h>
#include <raylib.h>

#define MAX_PLANTS 4
#define GRID_W 32
#define GRID_H 32

typedef struct {
    const char *name;
    float light_min;   /* lowest sunlight (0–1) the species does well in */
    float light_max;   /* highest sunlight (0–1) the species does well in */
    Color color;       /* what to draw it as */
} Species;

typedef struct {
    int x, y;
    const Species *species;
    float energy;
} Plant;

typedef struct {
    bool occupied;
    Plant plant;
    /* later: float soil_moisture; float nutrients; */
} Cell;

static const Species GRASS = {
    .name      = "Grass",
    .light_min = 0.5f,
    .light_max = 1.0f,
    .color     = (Color){ 80, 200, 80, 255 },   /* green */
};

static const Species MOSS = {
    .name      = "Moss",
    .light_min = 0.0f,
    .light_max = 0.4f,
    .color     = (Color){ 40, 110, 70, 255 },   /* dark green */
};

int main() {
    Cell *grid[GRID_H][GRID_W] = {0};

    // TODO: seed the plants
    for (int i = 0; i < 32; i++) {

    }


    printf("Hello xenoterra!\n");
    return 0;
}