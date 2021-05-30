//
// Created by a016817k on 22/05/2021.
//

#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
    GLUTCallbacks::Init(this);
    m_rotation = 0.0f;
    LR = UD = FD = 0.0f;
    square = {-0.5f,0.5f,0.7f,0.7f};
    //camera

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
    //gluPerspective(45, 1, 0.1, 1000);//you can leave yours at 0 i changed mine to 0.1
    //glOrtho(1,1,1,1,1,-1);
    glMatrixMode(GL_MODELVIEW);

    glutMainLoop();
}

HelloGL::~HelloGL() {


}

void HelloGL::Display() {
    glClearColor(1.0f,1.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix();
    glRotatef(m_rotation,1.0f,1.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor4f(0.8f,0.2f,0.5f,1.0f);
    //shapes->RightAngle();
#pragma region square
    glVertex2f(square.x, square.y);
    glVertex2f(square.x + (square.width), square.y);
    glVertex2f(square.x + (square.width), square.y+ (square.height));
    glVertex2f(square.x , square.y+ (square.height));
#pragma endregion

    glVertex2i(100,100);
    glVertex2i(500,100);
    glVertex2i(100,500);
    glVertex2i(500,500);



    glEnd();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}

void HelloGL::Update() {
    glLoadIdentity();
    //gluLookAt(camera->eye.X,camera->eye.Y,camera->eye.Z,
    //camera->center.X,camera->center.Y,camera->center.Z,
    //camera->up.X,camera->up.Y,camera->up.Z);
    glutPostRedisplay();

    //m_rotation += 0.5;
    if (m_rotation >= 360){
        m_rotation = 0.0f;
    }
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
        m_rotation += 0.5F;
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
cout << 'x' << x << endl;cout << 'y' << y << endl;
}

void HelloGL::DisplayCode() {

}


#pragma endregion


