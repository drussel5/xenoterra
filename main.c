#include <stdio.h>
#include <raylib.h>

typedef struct {
    const char *name;
    float light_min;   /* lowest sunlight (0–1) the species does well in */
    float light_max;   /* highest sunlight (0–1) the species does well in */
    Color color;       /* what to draw it as */
} Species;

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

    printf("Hello xenoterra!\n");
    return 0;
}