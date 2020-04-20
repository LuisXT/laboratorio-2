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

void dibujarEdificio(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double c1, double c2, double c3)
{
       glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
               glColor3f(c1, c2, c3); // sets color to cyan.
               glVertex2f(x1,y1); // esquina inferior izquierda
               glVertex2f(x2,y2); // esquina superior izquierda
               glVertex2f(x3,y3); // esquina inferior derecha
               glVertex2f(x4,y4); // esquina superior derecha
       glEnd();
       glutSwapBuffers();
}

void dibujarVentana(double x9, double y9, double x10, double y10, double x11, double y11, double x12, double y12, double c4,double c5, double c6)
{
       glBegin(GL_QUADS); // draw in triangle strips
               glColor3f(c4, c5, c6); // sets color to verde.
               glVertex2f(x9,y9); // esquina inferior izquierda
               glVertex2f(x10,y10); // esquina inferior derecha
               glVertex2f(x11,y11); // esquina superior izquierda
               glVertex2f(x12,y12); // esquina superior derecha
       glEnd();
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

void arbol (double x20, double y20, double x21, double y21, double x22, double y22, double x23, double y23,     double x24, double y24, double x25, double y25, double x26, double y26,     double x27, double y27, double x28, double y28, double x29, double y29,     double x30, double y30,double x31, double y31,double x32, double y32)
{
        //tronco
    glBegin(GL_QUADS); // draw in triangle strips
           glColor3f(1.0f, 0.2f, 0.0f); // sets color to verde.
           glVertex2f(x20,y20); // esquina inferior izquierda
           glVertex2f(x21,y21); // esquina inferior derecha
           glVertex2f(x22,y22); // esquina superior derecha
           glVertex2f(x23,y23); // esquina superior izquierda
    glEnd();

        //hoja superior
    glBegin(GL_TRIANGLES); // draw in triangle strips
           glColor3f(0.5f, 1.0f, 0.5f); // sets color to verde.
           glVertex2f(x20-5,y22); // esquina inferior izquierda
           glVertex2f(x21+5,y25); // esquina inferior derecha
           glVertex2f((((x21-x20)/2)+ x20),y26); // esquina superior
    glEnd();

        //hoja medio
    glBegin(GL_TRIANGLES); // draw in triangle strips
           glColor3f(0.5f, 1.0f, 0.5f); // sets color to verde.
           glVertex2f(x27,y27); // esquina inferior izquierda
           glVertex2f(x28,y28); // esquina inferior derecha
           glVertex2f(x29,y29); // esquina superior
    glEnd();

        //hoja inferior
    glBegin(GL_TRIANGLES); // draw in triangle strips
           glColor3f(0.5f, 1.0f, 0.5f); // sets color to verde.
           glVertex2f(x30,y30); // esquina inferior izquierda
           glVertex2f(x31,y31); // esquina inferior derecha
           glVertex2f(x32,y32); // esquina superior
    glEnd();
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
    dibujarEdificio(-30.0,-30.0,-5.0,-30.0,-30.0,10.0,-5.0,10.0, 0.5f, 1.0f, 0.5f);
    dibujarEdificio(10.0,-15.0,30.0,-15.0,10.0,20.0,30.0,20.0, 1.0f, 0.0f , 1.0f);

    //Dibujar Ventanas
        //edificio #1
    dibujarVentana(-27.0,0.0,-7.0,0.0,-7.0,8.0,-27.0,8.0,1.0f, 0.0f , 1.0f);
    dibujarVentana(-27.0,-10.0,-7.0,-10.0,-7.0,-2.0,-27.0,-2.0,1.0f, 0.0f, 1.0f);
    dibujarVentana(-27.0,-20.0,-7.0,-20.0,-7.0,-12.0,-27.0,-12.0,1.0f, 0.0f, 1.0f);

        //edificio #2
    dibujarVentana(13.0,12.0,28.0,12.0,28.0,18.0,13.0,18.0,0.5f, 1.0f, 0.5f);
    dibujarVentana(13.0,4.0,28.0,4.0,28.0,10.0,13.0,10.0,0.5f, 1.0f, 0.5f);
    dibujarVentana(13.0,-4.0,28.0,-4.0,28.0,2.0,13.0,2.0,0.5f, 1.0f, 0.5f);


    //dibujar arbol
    arbol(10.0,-25.0,15.0,-25.0,15.0,-20.0,10.0,-20.0,  5.0,-20.0,20.0,-20.0,12.5,-15.0,    5.0,-15.0,20.0,-15.0,12.5,-10.0,    5.0,-10.0,20.0,-10.0,12.5,-5.0);

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

