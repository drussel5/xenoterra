#include <stdbool.h>
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

void printGrid(Cell grid[][GRID_W]) {
    for (int i = 0; i < GRID_H; i++) {
        for (int j = 0; j < GRID_W; j++) {
            if (grid[i][j].occupied) {
                if (grid[i][j].plant.species == &GRASS) {
                    printf("///");
                } else if (grid[i][j].plant.species == &MOSS) {
                    printf("***");
                }
            } else {
                printf("___");
            }
        }
        printf("\n");
    }
}

int main(void) {
    Cell grid[GRID_H][GRID_W] = {0};
  
    for (int i = 0; i < MAX_PLANTS; i++) {
        // seed plants half moss and half grass
        if (i % 2 == 0) {
            grid[i][i].occupied = true;
            grid[i][i].plant = (Plant){ .species = &GRASS, .energy = 10.0f };
        } else {
            grid[i][i].occupied = true;
            grid[i][i].plant = (Plant){ .species = &MOSS, .energy = 10.0f };
        }
    }

    printf("xenoterra - start\n");
    printGrid(grid);
    printf("xenoterra - end\n");

    return 0;
}