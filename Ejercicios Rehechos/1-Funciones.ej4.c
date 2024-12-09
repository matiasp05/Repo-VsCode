/*
Se realiza una encuesta para estimar el grado de aceptación de los productos x e y en
el mercado. A cada encuestado se le pregunta si consume el producto x y si consume el
producto y. La respuesta puede ser sí o no.
Se pide calcular e informar el porcentaje de consumidores de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*/

#include <stdio.h>

int main(void) {
    int n, consume_x, consume_y;
    int consumidores_x = 0, consumidores_y = 0;
    int consumidores_x_solo = 0, consumidores_y_solo = 0;
    int consumidores_ambos = 0, consumidores_ninguno = 0;

    printf("Ingrese la cantidad de encuestados: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Encuestado %d\n", i + 1);
        printf("Consume el producto X? (1 = Si, 0 = No): ");
        scanf("%d", &consume_x);
        printf("Consume el producto Y? (1 = Si, 0 = No): ");
        scanf("%d", &consume_y);

        if (consume_x && consume_y) {
            consumidores_ambos++;
        } else if (consume_x) {
            consumidores_x_solo++;
        } else if (consume_y) {
            consumidores_y_solo++;
        } else {
            consumidores_ninguno++;
        }

        if (consume_x) consumidores_x++;
        if (consume_y) consumidores_y++;
    }

    printf("\nResultados:\n");
    printf("a) Porcentaje de consumidores de producto X: %.2f%%\n", (float)consumidores_x / n * 100);
    printf("b) Porcentaje de consumidores de producto Y: %.2f%%\n", (float)consumidores_y / n * 100);
    printf("c) Porcentaje de consumidores de producto X solamente: %.2f%%\n", (float)consumidores_x_solo / n * 100);
    printf("d) Porcentaje de consumidores de producto Y solamente: %.2f%%\n", (float)consumidores_y_solo / n * 100);
    printf("e) Porcentaje de consumidores de ambos productos: %.2f%%\n", (float)consumidores_ambos / n * 100);
    printf("f) Porcentaje de consumidores de ninguno de los productos: %.2f%%\n", (float)consumidores_ninguno / n * 100);

    return 0;
}