//
// Created by a016817k on 22/05/2021.
//

#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
    GLUTCallbacks::Init(this);
    m_rotation = 0.0f;
    LR = UD = FD = 0.0f;
    //camera
    camera = new Camera();
    camera->eye.X = 0;camera->eye.Y = 0;camera->eye.Z = 10.0f;
    camera->center.X = 0;camera->center.Y = 0;camera->center.Z = 0;
    camera->up.X = 0;camera->up.Y = 1.0f;camera->up.Z = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("dsdsd");
    glutDisplayFunc(GLUTCallbacks::Display);
    glutTimerFunc(REFERESHRATE,GLUTCallbacks::Timer,REFERESHRATE);
    //Input
    glutKeyboardFunc(GLUTCallbacks::Keyboard);
    glutKeyboardUpFunc(GLUTCallbacks::KeyboardUp);
    glutSpecialFunc(GLUTCallbacks::Special);
    glutSpecialUpFunc(GLUTCallbacks::SpecialUp);
    glutMouseFunc(GLUTCallbacks::Mouse);
    glutMotionFunc(GLUTCallbacks::Motion);
    glutPassiveMotionFunc(GLUTCallbacks::PassiveMotion);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, 800, 800);
    gluPerspective(45, 1, 0.1, 1000);//you can leave yours at 0 i changed mine to 0.1
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
}

HelloGL::~HelloGL() {


}

void HelloGL::Display() {
    //glClearColor(1.0f,1.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(LR,UD,FD);
    char test[] = "Idk how to go about doing this";
    Vector3 v = {0,0,0};
    Vector3 newv = {LR,UD,FD};
    v = v+newv;
    Color c = {1,1,0};
    DrawString(test, &v, &c);
    glRotatef(m_rotation, 1.0f,0.0f,-0.0f);
   // glutSolidCube(0.5);
    glBegin(GL_POLYGON);
    //shapes->Hexagon();

    glEnd();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}

void HelloGL::Update() {
    glLoadIdentity();
    gluLookAt(camera->eye.X,camera->eye.Y,camera->eye.Z,
    camera->center.X,camera->center.Y,camera->center.Z,
    camera->up.X,camera->up.Y,camera->up.Z);
    glutPostRedisplay();
    /*m_rotation += 0.5;
    if (m_rotation >= 360){
        m_rotation = 0.0f;
    }*/
    //cout << "LR " << LR << endl << "UD " << UD << endl << "FD" << FD << endl;
}

#pragma region UI
void HelloGL::DrawString(const char *text, Vector3 *pos, Color *color) {
    glTranslatef(pos->X,pos->Y,pos->Z);
    glRasterPos2f(0.0f, 0.0f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)text);
}
#pragma endregion
#pragma region input

void HelloGL::Keyboard(unsigned char key, int x, int y) {
    if(key == 'd'){
        LR += 0.5F;
    }
    else if(key == 'a'){
        LR -= 0.5F;
    }
    if(key == 'u'){
        UD += 0.5F;
    }
    else if(key == 'l'){
        UD -= 0.5F;
    }
    if(key == 'w'){
        FD += 0.5F;
    }
    else if(key == 's'){
        FD -= 0.5F;
    }
}

void HelloGL::KeyboardUp(unsigned char key, int x, int y) {

}

void HelloGL::Special(int key, int x, int y) {

}

void HelloGL::SpecialUp(int key, int x, int y) {

}

void HelloGL::Mouse(int button, int state, int x, int y) {

}

void HelloGL::Motion(int x, int y) {

}

void HelloGL::PassiveMotion(int x, int y) {

}




#pragma endregion


