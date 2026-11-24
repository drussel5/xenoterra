#include <stdbool.h>
#include <stdio.h>
#include <raylib.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PLANTS 20
#define GRID_W 32
#define GRID_H 32

typedef struct {
    const char *name;
    double light_min;   // lowest sunlight (0–1) the species does well in
    double light_max;   // highest sunlight (0–1) the species does well in
    int energy;         // stored energy
    Color color;        // what to draw it as
} Species;

typedef struct {
    const Species *species;
    double energy;
} Plant;

typedef struct {
    bool occupied;
    double light;
    Plant plant;
    // later: float soil_moisture; float nutrients;
} Cell;

static const Species GRASS = {
    .name      = "Grass",
    .light_min = 0.5,
    .light_max = 1.0,
    .color     = (Color){ 80, 200, 80, 255 },   // green
};

static const Species MOSS = {
    .name      = "Moss",
    .light_min = 0.0,
    .light_max = 0.4,
    .color     = (Color){ 40, 110, 70, 255 },   // dark green
};


void printGrid(Cell grid[][GRID_W]) {
    for (int i = 0; i < GRID_H; i++) {
        for (int j = 0; j < GRID_W; j++) {
            if (grid[i][j].occupied) {
                if (grid[i][j].plant.species == &GRASS) {
                    printf("///");// light: %f", grid[i][j].light);
                } else if (grid[i][j].plant.species == &MOSS) {
                    printf("***");// light: %f", grid[i][j].light);
                }
            } else {
                printf("___");// light: %f", grid[i][j].light);
            }
            // printf("%i,", grid[i][j].light);
        }
        printf("%i\n", i);
    }
}

void initializeGrid(Cell grid[][GRID_W]) {
    for (int i = 0; i < GRID_H; i++) {
        for (int j = 0; j < GRID_W; j++) {
            // set light for cells
            if (i < 3) {
                grid[i][j].light = 1.0;
            } else {
                grid[i][j].light = 0.2;
            }
        }
    }
}

// iterate one cycle
void step(Cell grid[][GRID_W]) {
    // dead flora - ran out of energy
    for (int i = 0; i < GRID_H; i++) {
        for (int j = 0; j < GRID_W; j++) {
            // cell unoccupied
            if (!grid[i][j].occupied) {
                continue;
            }

            Cell *cell = &grid[i][j];
            // plant dies without energy
            if (cell->plant.energy <= 0) {
                cell->occupied = false;
                continue;
            }

            // 1 energy to live
            cell->plant.energy -= 1;
            
            // TODO: plant may be ready to reproduce

        }
    }

    // consume one energy to stay alive

    // consume two energy to transition to next life-cycle if ready

    // replace energy
    // - flora will generate energy from a sufficient light source
    // - fauna will look for something to consume
}

int main(void) {
    Cell grid[GRID_H][GRID_W] = {0};
    int randX, randY;
    srand(time(NULL));
    
    initializeGrid(grid);
    for (int i = 0; i < MAX_PLANTS; i++) {
        // seed plants, flora grow where the light condition is met 
        do {
            randX = rand() % (GRID_W);
            randY = rand() % (GRID_H);
        } while (grid[randY][randX].occupied);

        if (GRASS.light_min <= grid[randY][randX].light && grid[randY][randX].light <= GRASS.light_max) {
            grid[randY][randX].occupied = true;
            grid[randY][randX].plant = (Plant){ .species = &GRASS, .energy = 5 };
        } else if (MOSS.light_min <= grid[randY][randX].light && grid[randY][randX].light <= MOSS.light_max) {
            grid[randY][randX].occupied = true;
            grid[randY][randX].plant = (Plant){ .species = &MOSS, .energy = 5};
        }
    }

    while (true) {
        printGrid(grid);
        step(grid);
        sleep(1);
    }

    return 0;
}
