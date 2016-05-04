//
//  Vector4D.h
//  CS 5721
//
//  Created by Max Ronning on 4/22/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//
#include <iostream>
#ifndef Vector4D_h
#define Vector4D_h

class Vector4D {
    
    public:
    
    double x, y, z, w;
    
    Vector4D(){} // Empty Constructor
    
    //Constructor
    Vector4D(double q, double r, double s, double t){
        x = q;
        y = r;
        z = s;
        w = t;
    }
    
    //Setter for vector values
    Vector4D& set(double q, double r, double s, double t) {
        x = q;
        y = r;
        z = s;
        w = t;
        return (*this);
    }
    
    // Overloaded subtraction operator
    Vector4D operator -(const Vector4D& v) const {
        return Vector4D(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    
//    Vector3D cross(const Vector3D& v) const {
//        return (Vector3D((this->y * v.z - this->z * v.y),
//                         (this->z * v.x - this->x * v.z),
//                         (this->x * v.y - this->y * v.x),
//                         (this->)));
//    }
    
    //prints the contents of the vector
    void output() {
        cout << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")\n";
    }
    
    // Overloaded scalar division operator
    Vector4D operator /(double scalar) const {
        return (Vector4D(x / scalar, y / scalar, z / scalar, w / scalar));
    }
    
};

#endif /* Vector4D_h */
