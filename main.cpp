#include <windows.h>
#include <GL/glut.h>
#include <Math.h>
#define Pi 3.1415926535897932384626433832795

void iniciarProyeccion()
{
    glClearColor(1.0,0.5,0.25,0.0); //LO PINTA DE NARANJA
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}

//dibujarEdificio(-30.0,-30.0,-5.0,-30.0,-30.0,10.0,-5.0,10.0, 0.5f, 1.0f, 0.5f);
//(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double c1, double c2, double c3)

//dibujarVentana(-27.0,0.0,-7.0,0.0,-7.0,8.0,-27.0,8.0,1.0f, 0.0f , 1.0f);
void dibujarVentana(double x, double y, double Size = 1)
{
       glBegin(GL_QUADS); // draw in triangle strips
               glColor3f(1, 1, 1); // sets color to verde.
               glVertex2f((x - (8*Size)),(y)); // esquina inferior izquierda
               glVertex2f((x + (8*Size)),(y)); // esquina inferior derecha
               glVertex2f((x + (8*Size)),(y + (5*Size))); // esquina superior izquierda
               glVertex2f((x - (8*Size)),(y + (5*Size))); // esquina superior derecha
       glEnd();
       glutSwapBuffers();
}

void dibujarEdificio(double x, double y, double Size = 1)
{
       glBegin(GL_QUADS); // draw in triangle strips
               glColor3f(0.3,0.3,0.3); // sets color to cyan.
               glVertex2f((x - (10*Size)),(y)); // esquina inferior izquierda
               glVertex2f((x + (10*Size)),(y)); // esquina inferior derecha
               glVertex2f((x + (10*Size)),(y + (30*Size))); // esquina superior izquierda
               glVertex2f((x - (10*Size)),(y + (30*Size))); // esquina superior derecha
       glEnd();

       dibujarVentana(x,(y + (10*Size)),Size);
       dibujarVentana(x,(y + (16*Size)),Size);
       dibujarVentana(x,(y + (22*Size)),Size);
       glutSwapBuffers();
}




void dibujarPasto(double x5, double y5, double x6, double y6, double x7, double y7, double x8, double y8)
{
       glBegin(GL_QUADS); // draw in triangle strips
               glColor3f(0.0f, 0.5f, 0.0f); // sets color to verde.
               glVertex2f(x5,y5); // esquina inferior izquierda
               glVertex2f(x6,y6); // esquina inferior derecha
               glVertex2f(x7,y7); // esquina superior izquierda
               glVertex2f(x8,y8); // esquina superior derecha
       glEnd();
       glutSwapBuffers();
}

//Metodo para dibujar las Nubes
void drawClouds (double x1, double y1, double Size = 1)
{
    //parte central de la nube
    glPushMatrix();
    glTranslated(x1,y1,(1 * Size));
    glColor3f(1,1,1);
    glutSolidSphere((1 * Size),60,60);
    glPopMatrix();
    //parte izquierda de la nube
    glPushMatrix();
    glTranslated((x1 - Size),y1,(1 * Size));
    glColor3f(1,1,1);
    glutSolidSphere((1 * Size),60,60);
    glPopMatrix();
    //parte derecha de la nube
    glPushMatrix();
    glTranslated((x1 + Size),y1,(1 * Size));
    glColor3f(1,1,1);
    glutSolidSphere((1 * Size),60,60);
    glPopMatrix();
}

void Sol (double x, double y)
{
    glPushMatrix();
    glTranslated(x,y,50);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(50,100,100);
    glutWireSphere(50,100,100);
    glPopMatrix();
}

void triangulo(double x,double y, double Size){
    glBegin(GL_TRIANGLES); // draw in triangle strips
           glColor3f(0.5f, 1.0f, 0.5f); // sets color to verde.
           glVertex2f((x - (10*Size)),y); // esquina inferior izquierda
           glVertex2f((x + (10*Size)),y); // esquina inferior derecha
           glVertex2f(x,(y + (5*Size))); // esquina superior
    glEnd();
}

void arbol (double x, double y, double Size = 1)
{       // 0,0
        //tronco
    glBegin(GL_QUADS); // draw in triangle strips
           glColor3f(1.0f, 0.2f, 0.0f); // sets color to verde.
           glVertex2f(x - (2.5 * Size),(y)); // esquina inferior izquierda
           glVertex2f((x + (2.5 * Size)),(y)); // esquina inferior derecha
           glVertex2f((x + (2.5 * Size)),(y + (5 * Size))); // esquina superior derecha
           glVertex2f((x - (2.5 * Size)),(y + (5 * Size))); // esquina superior izquierda
    glEnd();

    triangulo(x, (y+(4*Size)),Size);
    triangulo(x, (y+(8*Size)),Size);
    triangulo(x, (y+(12*Size)),Size);
    glutSwapBuffers();
}


//Metodo que hace las llamadas a los metodos de dibujo
void draw (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Sol
    Sol(5,0);

    //dibujar pasto
    dibujarPasto(-40.0,-40.0,40.0,-40.0,40.0,0.0,-40.0,0.0);

    //Dibujar Edificios
    dibujarEdificio(0,-10,0.5);
    dibujarEdificio(-20,-20,1);
    //Dibujar Ventanas
        //edificio #1



    //dibujar arbol
    arbol(0,-30,0.4);
    arbol(10,-30,0.8);
    arbol(20,-30);

    //Clouds
    drawClouds(-30,30,3);
    drawClouds(-20,25,2);
    drawClouds(-10,33,0.5);
    drawClouds(15,30,4);
    drawClouds(25,26,6);
    drawClouds(0,20,1);



    glFlush();

}

//Metodo Main por donde el programa comienza a ejecutarse.
int main (int argc, char* argv [])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow ("CASA");
    iniciarProyeccion();
    glutDisplayFunc(draw);
    glutMainLoop();

}

