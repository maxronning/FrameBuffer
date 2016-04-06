//
//  FrameBuffer.cpp
//  Homework 3
//
//  Created by Max Ronning on 1/21/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(int width, int height) {
    setWidth(width);
    setHeight(height);
    std::cout << "(" << getWidth() << "," << getHeight() << ")\n";
    my2Dpointer = new pixColor*[width];
    
    for(int i = 0; i < width; i++) {
        my2Dpointer[i] = new pixColor[height];
    }
};

void FrameBuffer::set(int x, int y, short int red, short int green, short int blue) {
    if (x == getWidth()) {x -= 1;}
    if (y == getHeight()) {y -= 1;}
    
    my2Dpointer[x][y].r = red;
    my2Dpointer[x][y].g = green;
    my2Dpointer[x][y].b = blue;
};

int FrameBuffer::getWidth() const  {
    return w;
};

int FrameBuffer::getHeight() const  {
    return h;
};

void FrameBuffer::rasterizeline_implicit(const Vector2D& p0, const Vector2D &p1, const Vector3D& c) {
    
    if (p0.x > p1.x) {
        rasterizeline_implicit(p1, p0, c);
    }
    
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    
    
    //Control for when line is vertical
    if (dx == 0) {
        int yDiff = std:: abs(p0.y - p1.y);
        if (p0.y > p1.y) {
            for (int y = p1.y; y <= yDiff +p1.y; y++){
            set(p0.x, y, c.x, c.y, c.z);
            }
        }
        else {
            for (int y = p0.y; y <= yDiff + p0.y; y++){
                set(p0.x, y, c.x, c.y, c.z);
            }
        }
    }
    else if (dy == 0) { //Control for when slope is horizontal
        int xDiff = std:: abs(p0.x - p1.x);
        if (p0.x > p1.x) {
            for (int x = p1.x; x <= xDiff + p1.x; x++){
                set(x, p0.y, c.x, c.y, c.z);
            }
        }
        else {
            for (int x = p0.x; x <= xDiff + p0.x; x++){
                set(x, p0.y, c.x, c.y, c.z);
            }
        }
    }
    else { //Control when slope is anything other and 1 or 0
       for (int x = p0.x; x <= p1.x; x++){
           int y = p0.y + dy * (x - p0.x) / dx;
           set(x, y, c.x, c.y, c.z);
       }
    }
};

void FrameBuffer::rasterizeline_parametric( const Vector2D& p0, const Vector2D &p1, const Vector3D& c0, const Vector3D& c1) {
    
    Vector3D deltaC(c0.x * 255, c0.y * 255, c0.z * 255);
    
    double deltaR = c1.x - c0.x;
    double deltaG = c1.y - c0.y;
    double deltaB = c1.z - c0.z;
    
    int deltaX = p1.x - p0.x;
    int deltaY = p1.y - p0.y;
    double distance = (double) std::sqrt( (deltaX * deltaX) + (deltaY * deltaY) );
    
    deltaR = (deltaR / distance) * 255;
    deltaG = (deltaG / distance) * 255;
    deltaB = (deltaB / distance) * 255;
    
    Vector3D c(deltaR, deltaG, deltaB);

    
    if (p0.x > p1.x) {
        rasterizeline_parametric(p1, p0, c1, c0);
    }
    
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    
    //Control for when line is vertical
    if (dx == 0) {
        int yDiff = std:: abs(p0.y - p1.y);
        if (p0.y > p1.y) {
            for (int y = p1.y; y <= yDiff +p1.y; y++) {
                set(p0.x, y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
        else {
            for (int y = p0.y; y <= yDiff + p0.y; y++) {
                set(p0.x, y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
                
            }
        }
    }
    else if (dy == 0) { //Control for when slope is horizontal
        int xDiff = std:: abs(p0.x - p1.x);
        if (p0.x > p1.x) {
            for (int x = p1.x; x <= xDiff + p1.x; x++) {
                set(x, p0.y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
        else {
            for (int x = p0.x; x <= xDiff + p0.x; x++) {
                set(x, p0.y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
    }
    else { //Control when slope is anything other and 1 or 0
        for (int x = p0.x; x <= p1.x; x++) {
            int y = p0.y + dy * (x - p0.x) / dx;
            set(x, y, deltaC.x, deltaC.y, deltaC.z);
            deltaC = deltaC + c;
            
        }
    }
};

void FrameBuffer::rasterizeTriangle(const Vector2D &p0, const Vector2D &p1, const Vector2D &p2,
                                    const Vector3D& c0, const Vector3D& c1, const Vector3D& c2) {
    
    double alpha, beta, gamma, f_A, f_B, f_G;
    
    int orderY[3] = {(int) p0.y, (int) p1.y, (int) p2.y};
    std::sort(std::begin(orderY),std::end(orderY));
    
    int orderX[3] = {(int) p0.x, (int) p1.x, (int) p2.x};
    std::sort(std::begin(orderX),std::end(orderX));
    
    int yMin = orderY[0];
    int yMax = orderY[2];
    
    int xMin = orderX[0];
    int xMax = orderX[2];
    
    f_A = (p1.y - p2.y) * p0.x + (p2.x - p1.x) * p0.y + (p1.x * p2.y) - (p2.x * p1.y);
    f_B = (p2.y - p0.y) * p1.x + (p0.x - p2.x) * p1.y + (p2.x * p0.y) - (p0.x * p2.y);
    f_G = (p0.y - p1.y) * p2.x + (p1.x - p0.x) * p2.y + (p0.x * p1.y) - (p1.x * p0.y);
    
    for (int y = yMin; y <= yMax; y++) {
        for (int x = xMin; x <= xMax; x++) {
            
            alpha = ((p1.y - p2.y) * x + (p2.x - p1.x) * y + (p1.x * p2.y) - (p2.x * p1.y)) / f_A;
            beta  = ((p2.y - p0.y) * x + (p0.x - p2.x) * y + (p2.x * p0.y) - (p0.x * p2.y)) / f_B;
            gamma = ((p0.y - p1.y) * x + (p1.x - p0.x) * y + (p0.x * p1.y) - (p1.x * p0.y)) / f_G;

            if (alpha >= 0 && beta >= 0 && gamma >= 0) {
                if (  (alpha > 0 || (f_A * ((p1.y - p2.y) * -1 + (p2.x - p1.x) * -1 + (p1.x * p2.y) - (p2.x * p1.y)) > 0)) &&
                      (beta > 0 || (f_B * ((p2.y - p0.y) * -1 + (p0.x - p2.x) * -1 + (p2.x * p0.y) - (p0.x * p2.y)) > 0)) &&
                      (gamma > 0 || (f_G * (p0.y - p1.y) * -1 + (p1.x - p0.x) * -1 + (p0.x * p1.y) - (p1.x * p0.y)) > 0)) {
                    
                    Vector3D color1(0.0, 0.0, 0.0);
                    Vector3D color2(0.0, 0.0, 0.0);
                    Vector3D color3(0.0, 0.0, 0.0);
                    Vector3D finalColor(0.0, 0.0, 0.0);
                    
                    color1 = c0 * alpha;
                    color2 = c1 * beta;
                    color3 = c2 * gamma;
                    finalColor = (c0 * alpha) + (c1 * beta) + (c2 * gamma);
                    finalColor = finalColor * 255;
                    
                    set(x, y, finalColor.x, finalColor.y, finalColor.z);
                }
            }
        }
    }

    
};

void FrameBuffer::setWidth(int a)  {
    w = a;
};

void FrameBuffer::setHeight(int a) {
    h = a;
};

void FrameBuffer::setAll(short int red, short int green, short int blue) {
    for (int j = 0; j < getHeight(); j++) {
        for (int i = 0; i < getWidth(); i++) {
            my2Dpointer[i][j].r = red;
            my2Dpointer[i][j].g = green;
            my2Dpointer[i][j].b = blue;
        }
    }
};


void FrameBuffer::raytrace() { //Implements orthographic ray tracing
    
    //Bounds of viewing window
    double left = -0.5;
    double right = 0.5;
    double bottom = -0.5;
    double top = 0.5;
    
    Vector3D d(0,0,-1); //Distance vector
    double t = 0; //Point of intersection
    
    for (int j = 0; j < getHeight(); j++) { // Framebuffer loops to create ray tracing window
        for (int i = 0; i < getWidth(); i++) {
            
            //Create ray tracing grid (with arbitrary units)
            double u = (left + (right - left)*(i + 0.5)) / getWidth();
            double v = (bottom + (top - bottom)*(j + 0.5)) / getHeight();
            
            Vector3D e(u, v, 0); //Starting vector of ray at (u,v)
            
            //Vector3D ray = e + d * t;
            
            Circle3D c(Vector3D(0.5, 0.5, -1), .25); // Declaring circle object in center of framebuffer
            double dp = d.dot(e - c.location());
            
            //Computes if current ray intersects object
            t = ( (-1)*dp - sqrt( pow(dp, 2) - d.dot(d)*((e - c.location()).dot(e - c.location()) - pow(c.getRad(), 2)))) / (d.dot(d));
            
            //If ray intersects object, set pixel to yello
            if (t >= 0 && t<=1) {
                set(i, j, 255, 255, 0);
            }
        }
    }
};

void FrameBuffer::writePPM(const std::string filename) const {
    
    std::ofstream os;
    os.open(filename.c_str(), std::ofstream::out);
    os << "P3\r\n# " << filename << "\r\n" << getWidth() << " " << getHeight() << " 255""\n";
    
    for (int y = getHeight() - 1; y >= 0; y--) {
        os << "\n";
    
        for (int x = 0; x < getWidth(); x++) {
            os << my2Dpointer[x][y].r << " "
                << my2Dpointer[x][y].g << " "
                 << my2Dpointer[x][y].b << " ";
        }
    }
    os.close();
};

int* FrameBuffer::bufferData() {
    int entries = getHeight() * getWidth() * 3;
    int* buffData = new int[entries];
    int k = 0;
    
    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            buffData[k] = my2Dpointer[x][y].r;
            k++;
            buffData[k] = my2Dpointer[x][y].g;
            k++;
            buffData[k] = my2Dpointer[x][y].b;
            k++;
        }
    }
    
    return buffData;
};