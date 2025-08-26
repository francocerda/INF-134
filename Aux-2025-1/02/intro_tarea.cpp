#include <iostream>
#include <string>

// Activar la implementación de stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

// Activar la implementación de stb_image_write
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

using namespace std;

int main() {
    // Variables para almacenar información de la imagen
    int width, height, channels;

    // Cargar la imagen (asegúrate de que DawnFM.png esté en el directorio actual)
    unsigned char* data = stbi_load("Images/DawnFM.png", &width, &height, &channels, 0);
    if (!data) {
        cout << "Error al cargar la imagen DawnFM.png" << endl;
        return -1;
    }

    // Mostrar información de la imagen
    cout << "Imagen DawnFM.png cargada exitosamente." << endl;
    cout << "Dimensiones: " << width << " x " << height 
         << " con " << channels << " canales." << endl;

    // Guardar la imagen con un nuevo nombre (para probar la parte de escritura)
    string outputName = "DawnFM_test.png";
    if (stbi_write_png(outputName.c_str(), width, height, channels, data, width * channels)) {
        cout << "Se ha guardado la imagen como " << outputName << endl;
    } else {
        cout << "Error al guardar la imagen." << endl;
    }

    // Liberar la memoria asociada a la imagen
    stbi_image_free(data);

    return 0;
}
