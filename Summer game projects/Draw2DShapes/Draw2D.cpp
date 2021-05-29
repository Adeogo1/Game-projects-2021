//
// Created by a016817k on 25/05/2021.
//

#include "Draw2D.h"

Draw2D::Draw2D() {

}

void Draw2D::DrawScalene() {
    float xPos = 0.15;
    glVertex2f(0.05f - xPos,0.6f);
    glVertex2f(0.85f- xPos, -0.45f);
    glVertex2f(-0.55f- xPos, -0.45f);
}

void Draw2D::Isosceles() {
    glVertex2f(0.0f ,0.9f);
    glVertex2f(0.3f, -0.85f);
    glVertex2f(-0.3f, -0.85f);
}

void Draw2D::Equalateral() {
    glVertex2f(0.0f ,0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
}

void Draw2D::Acute() {
    glVertex2f(-0.25f ,0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
}

void Draw2D::RightAngle() {
    glVertex2f(-0.6f ,0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
}

void Draw2D::Obtuse() {
    glVertex2f(-0.8f ,0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
}

Draw2D::~Draw2D() {

}

void Draw2D::Hexagon() {
    glVertex2f(-0.3f ,0.8f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.6f, -0.0f);
    glVertex2f(0.3f ,-0.8f);
    glVertex2f(-0.3f, -0.8f);
    glVertex2f(-0.6f, -0.0f);

}

void Draw2D::Pentagon() {
    glVertex2f(0.0f ,0.8f);
    glVertex2f(0.45f, 0.25f);
    glVertex2f(0.35f, -0.6f);
    glVertex2f(-0.35f, -0.6f);
    glVertex2f(-0.45f, 0.25f);

}
