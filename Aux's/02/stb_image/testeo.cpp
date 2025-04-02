#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

// Importacion de librerias. Los archivos correspondientes deben estar en el mismo directorio que el .cpp.
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>
#include <string> 

using namespace std;

// Struct que almacena la data de una imagen
struct Imagen{
    unsigned char* data;
    int width, height, channels;
};

// Abrir imagen desde memoria local
Imagen* load(const char* filename) {
    Imagen* img = new Imagen();
    img->data = stbi_load(filename, &img->width, &img->height, &img->channels, 0);
    return img;
}

// Guardar imagen en memoria local
void save(Imagen* img, const char* filename) {
    stbi_write_png(filename, img->width, img->height, img->channels, img->data, img->width * img->channels);
    cout << "Imagen guardada:  " << filename << "\n";
}

// Pregunta 5: Objetivo, poner la imagen en modo espejo.


void operacion_1(Imagen*img) { 
    for (int y=0; y < img->height; y++) {
        for (int x=0; x < (img->width)/2; x++){
            for (int c=0 ; c < img->channels ; c++){  
                
                int izq = (y * img->width + x) * img->channels + c;
                
                int der = (y * img->width + (img->width - 1 - x)) * img->channels + c;

                unsigned char temporal = img->data[izq];
                img->data[izq] = img->data[der];
                img->data[der] = temporal;
            }
        }
    }
}



int main() {
    //Cargamos la imagen

    Imagen* img = load("Pikachu2.png");
    
    operacion_1(img);
    // Almacenamos el resultado
    save(img, "output.png");
    
    
    

}