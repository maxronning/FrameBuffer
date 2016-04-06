//
//  Vector2D.hpp
//  Homework 3
//
//  Created by Max Ronning on 1/18/16.
//  Copyright © 2016 Max Ronning. All rights reserved.

#ifndef Vector3D_h
#define Vector3D_h

#include <stdio.h>
#include <math.h>
#include <iostream>


class Vector3D {
public:
    
    double x,y,z;
    
    Vector3D() {};
    
    // Constructor
    Vector3D (double r, double s, double t) {
        x = r;
        y = s;
        z = t;
    }
    
    // Setter for a vector
    Vector3D& setVals(double r, double s, double t) {
        x = r;
        y = s;
        z = t;
        return (*this);
    }
    
    // Overloaded addition operator
    Vector3D operator +(const Vector3D& v) const
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }
    
    // Overloaded subtraction operator
    Vector3D operator -(const Vector3D& v) const
    {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }
    
    // Overloaded scalar multiplication operator
    Vector3D operator *(double scalar) const
    {
        return (Vector3D(x * scalar, y * scalar, z * scalar));
    }
    
    // Computes and returns the length of a vector
    double magnitude() {
        return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
    }
    
    // Computes and returns the dot product of two vectors
    double dot(const Vector3D& v) const {
        return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
    }
    
    // Computes and returns the cross product of two vectors
    Vector3D cross(const Vector3D& v) const {
        return (Vector3D((this->y * v.z - this->z * v.y),
                            (this->z * v.x - this->x * v.z),
                                (this->x * v.y - this->y * v.x)));
    }
    
    // Normalize the vector and return it
    void normalize()
    {
        float mag = sqrtf(x* x + y * y + z * z);
        this->x = x / mag;
        this->y = y / mag;
        this->z = z / mag;
    }
    
    // Overloaded scalar division operator
    Vector3D operator /(double scalar) const
    {
        return (Vector3D(x / scalar, y / scalar, z / scalar));
    }
    
    
    
};


#endif /* Vector2D_hpp */

