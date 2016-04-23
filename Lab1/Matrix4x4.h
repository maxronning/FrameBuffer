//
//  Matrix4x4.h
//  Lab1
//
//  Created by Max Ronning on 4/1/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#ifndef Matrix4x4_h
#define Matrix4x4_h
#include "Vector3D.h"
#include "Vector4D.h"
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>


class Matrix4x4 {
    
public:
    
    // Constructor
    Matrix4x4 (double a11, double a12, double a13, double a14,
               double a21, double a22, double a23, double a24,
               double a31, double a32, double a33, double a34,
               double a41, double a42, double a43, double a44)  {
        
        m11 = a11;
        m12 = a12;
        m13 = a13;
        m14 = a14;
        m21 = a21;
        m22 = a22;
        m23 = a23;
        m24 = a24;
        m31 = a31;
        m32 = a32;
        m33 = a33;
        m34 = a34;
        m41 = a41;
        m42 = a42;
        m43 = a43;
        v44 = a44;
        
    }
    
    // sets the 16 values in the matrix
    void set(double a11, double a12, double a13, double a14,
             double a21, double a22, double a23, double a24,
             double a31, double a32, double a33, double a34,
             double a41, double a42, double a43, double a44) {
        
        this->m11 = a11;
        this->m12 = a12;
        this->m13 = a13;
        this->m14 = a14;
        this->m21 = a21;
        this->m22 = a22;
        this->m23 = a23;
        this->m24 = a24;
        this->m31 = a31;
        this->m32 = a32;
        this->m33 = a33;
        this->m34 = a34;
        this->m41 = a41;
        this->m42 = a42;
        this->m43 = a43;
        this->m44 = a44;
    }
    
    // sets the matrix to the translation matrix
    void makeTranslate( Vector3D& v) {
        this->m11 = 1;
        this->m12 = 0;
        this->m13 = 0;
        this->m14 = v.x;
        this->m21 = 0;
        this->m22 = 1;
        this->m23 = 0;
        this->m24 = v.y;
        this->m31 = 0;
        this->m32 = 0;
        this->m33 = 1;
        this->m34 = v.z;
        this->m41 = 0;
        this->m42 = 0;
        this->m43 = 0;
        this->m44 = 1;
    }
    
    
    /*
     
     void makeTranslate( Vector3D& );  // sets the matrix to the translation matrix
     void makeScale( Vector3D& ); // creates the scale matrix
     void makeOrtho( ... ); // creates the orthographic viewing matrix
     void makePerspective( ... ); //creates the perspective viewing matrix
     
     
     */
    
    
    
    private:
    
    double m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    
};


#endif /* Matrix4x4_h */
