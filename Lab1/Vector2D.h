//
//  Vector2D.hpp
//  Homework 3
//
//  Created by Max Ronning on 1/18/16.
//  Copyright © 2016 Max Ronning. All rights reserved.

#ifndef Vector2D_h
#define Vector2D_h

#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>


class Vector2D {
    public:
    
    double x,y;
    
    Vector2D() {};
    
    // Constructor
    Vector2D (double r, double s) {
        x = r;
        y = s;
    }
    
    // Setter for a vector
    Vector2D& setVals(double r, double s) {
        x = r;
        y = s;
        return (*this);
    }
    
    // Overloaded addition operator
    Vector2D operator +(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }
    
    // Overloaded subtraction operator
    Vector2D operator -(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }
    
    // Overloaded scalar multiplication operator
    Vector2D operator *(double scalar) const {
        return (Vector2D(x * scalar, y * scalar));
    }
    
    // Computes and returns the length of a vector
    double magnitude() {
        return sqrt((this->x * this->x) + (this->y * this->y));
    }
    
    // Computes and returns the dot product of two vectors
    double dot(const Vector2D& v) const {
        return (this->x * v.x) + (this->y * v.y);
    }
    
    float *vecfData() {
        float* data2D = new float[2];
        data2D[0] = this->x;
        data2D[1] = this->y;
        return data2D;
    }
    
    // Normalize the vector and return it
    void normalize() {
        float mag = sqrtf(x* x + y * y);
        this->x = x / mag;
        this->y = y / mag;
    }
    
    // Overloaded scalar division operator
    Vector2D operator /(double scalar) const {
        return (Vector2D(x / scalar, y / scalar));
    }
    
};


#endif /* Vector2D_hpp */

