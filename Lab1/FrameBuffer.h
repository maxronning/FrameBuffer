
//
//  FrameBuffer.h
//  Homework 3
//
//  Created by Max Ronning on 1/21/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#ifndef FRAMEBUFFERH
#define FRAMEBUFFERH

using namespace std;

#include "Vector2D.h"
#include "Vector3D.h"
#include "Circle3D.h"
#include "Matrix4x4.h"
#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

class FrameBuffer {
    
    //Custom struct to hold pixel RGB values
    struct pixColor{
        int r = 0;
        int g = 0;
        int b = 0;
    };
    
    public:
    
    pixColor** my2Dpointer;
    
    FrameBuffer(int width, int height);
    
    virtual ~FrameBuffer() { };
    
    void set(int x, int y, short int red, short int green, short int blue);
    
    void raytrace(Circle3D circles[]);
    
    void zBuffer();
    
    void setZbuff(double z);
    
    void printZbuff();
    
    void ortho1();
    
    void ortho2();
    
    void persp1();
    
    void persp2();
    
    int getWidth() const;
    
    int getHeight() const;
    
    void rasterizeline_implicit( const Vector2D& p0, const Vector2D &p1, const Vector3D& c);
    
    void rasterizeline_parametric( const Vector2D& p0, const Vector2D &p1, const Vector3D& c0, const Vector3D& c1);
    
    void rasterizeTriangle(const Vector4D& p0, const Vector4D &p1, const Vector4D &p2, const Vector3D& c0, const Vector3D& c1, const Vector3D& c2);
    
    void setWidth(int a);
    
    void setHeight(int a);
    
    void setAll(short int red, short int green, short int blue);
    
    double hit(Circle3D c, Vector3D e, Vector3D dist);
    
    void writePPM(const std::string filename) const;
    
    int* bufferData();
    
    private:
    
    int height;
    int width;
    int* data;
    double** zBuff;
};

#endif