#include <GL/glut.h>
#include <GL/freeglut_ext.h> 
#include "gl_canvas2d.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>


#include "Bola.h"
#include "window.cpp"

using namespace std;

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY; 


void render() {
   CV::color(1,0,1);
}

void keyboard(int key) {

}

void keyboardUp(int key) {

}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x;
   mouseY = y;
}

int main(void)
{

   CV::init(screenWidth, screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
