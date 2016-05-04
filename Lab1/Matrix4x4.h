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



class Matrix4x4 {
    
public:
    
    Matrix4x4 () {};
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
        m44 = a44;
        
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
    
    
    // creates the scale matrix
    void makeScale( Vector3D& v) {
        this->setAll(0);
        this->m11 = v.x;
        this->m22 = v.y;
        this->m33 = v.z;
        this->m44 = 1;
    }
    
    // creates the orthographic viewing matrix
    void makeOrtho(double r, double l, double b, double t, double n, double f) {
        this->setAll(0);
        this->m11 = 2/(r-l);
        this->m14 = (-1)*((r+l)/(r-l));
        this->m22 = 2/(t-b);
        this->m24 = (-1)*((t+b)/(t-b));
        this->m33 = 2/(n-f);
        this->m34 = (-1)*((n+f)/(n-f));
        this->m44 = 1;
    }
    
    void makeVP(double nx, double ny) {
        this->setAll(0);
        this->m11 = nx/2;
        this->m14 = (nx-1)/2;
        this->m22 = ny/2;
        this->m24 = (ny-1)/2;
        this->m33 = 1;
        this->m44 = 1;
    }
    
    /*
     s
     void makeTranslate( Vector3D& );  // sets the matrix to the translation matrix
     void makeScale( Vector3D& ); // creates the scale matrix
     void makeOrtho( ... ); // creates the orthographic viewing matrix
     void makePerspective( ... ); //creates the perspective viewing matrix
     
     */
    
    // Sets all values in a matrix to value p
    void setAll(double p) {
        this->m11 = p;
        this->m12 = p;
        this->m13 = p;
        this->m14 = p;
        this->m21 = p;
        this->m22 = p;
        this->m23 = p;
        this->m24 = p;
        this->m31 = p;
        this->m32 = p;
        this->m33 = p;
        this->m34 = p;
        this->m41 = p;
        this->m42 = p;
        this->m43 = p;
        this->m44 = p;
    }
    
    // Overloaded scalar multiplication operator
    // * NOTE : this is a place for huge optimization
    Matrix4x4 operator *(Matrix4x4& t) const
    {
        double p11 = (this->m11 * t.m11) + (this->m12 * t.m21) + (this->m13 * t.m31) + (this->m14 * t.m41);
        double p12 = (this->m11 * t.m12) + (this->m12 * t.m22) + (this->m13 * t.m32) + (this->m14 * t.m42);
        double p13 = (this->m11 * t.m13) + (this->m12 * t.m23) + (this->m13 * t.m33) + (this->m14 * t.m43);
        double p14 = (this->m11 * t.m14) + (this->m12 * t.m24) + (this->m13 * t.m34) + (this->m14 * t.m44);
        
        double p21 = (this->m21 * t.m11) + (this->m22 * t.m21) + (this->m23 * t.m31) + (this->m24 * t.m41);
        double p22 = (this->m21 * t.m12) + (this->m22 * t.m22) + (this->m23 * t.m32) + (this->m24 * t.m42);
        double p23 = (this->m21 * t.m13) + (this->m22 * t.m23) + (this->m23 * t.m33) + (this->m24 * t.m43);
        double p24 = (this->m21 * t.m14) + (this->m22 * t.m24) + (this->m23 * t.m34) + (this->m24 * t.m44);
        
        double p31 = (this->m31 * t.m11) + (this->m32 * t.m21) + (this->m33 * t.m31) + (this->m34 * t.m41);
        double p32 = (this->m31 * t.m12) + (this->m32 * t.m22) + (this->m33 * t.m32) + (this->m34 * t.m42);
        double p33 = (this->m31 * t.m13) + (this->m32 * t.m23) + (this->m33 * t.m33) + (this->m34 * t.m43);
        double p34 = (this->m31 * t.m14) + (this->m32 * t.m24) + (this->m33 * t.m34) + (this->m34 * t.m44);
        
        double p41 = (this->m41 * t.m11) + (this->m42 * t.m21) + (this->m43 * t.m31) + (this->m44 * t.m41);
        double p42 = (this->m41 * t.m12) + (this->m42 * t.m22) + (this->m43 * t.m32) + (this->m44 * t.m42);
        double p43 = (this->m41 * t.m13) + (this->m42 * t.m23) + (this->m43 * t.m33) + (this->m44 * t.m43);
        double p44 = (this->m41 * t.m14) + (this->m42 * t.m24) + (this->m43 * t.m34) + (this->m44 * t.m44);
        
        return (Matrix4x4(p11, p12, p13, p14,
                          p21, p22, p23, p24,
                          p31, p32, p33, p34,
                          p41, p42, p43, p44));
    }
    
    // Overloaded operator for matrix - vector multiplication
    Vector4D operator *(Vector4D& v) {
        
        return Vector4D((this->m11 * v.x) + (this->m12 * v.y) + (this->m13 * v.z) + (this->m14 * v.w),
                        (this->m21 * v.x) + (this->m22 * v.y) + (this->m23 * v.z) + (this->m24 * v.w),
                        (this->m31 * v.x) + (this->m32 * v.y) + (this->m33 * v.z) + (this->m34 * v.w),
                        (this->m41 * v.x) + (this->m42 * v.y) + (this->m43 * v.z) + (this->m44 * v.w));
    }
    
    // output the contents of a matrix
    void output(){
        cout << "| " << m11 << " " << m12 << " " << m13 << " " << m14 << " |" << endl;
        cout << "| " << m21 << " " << m22 << " " << m23 << " " << m24 << " |" << endl;
        cout << "| " << m31 << " " << m32 << " " << m33 << " " << m34 << " |" << endl;
        cout << "| " << m41 << " " << m42 << " " << m43 << " " << m44 << " |" << endl << endl;
        
    }
    
    private:
    
    double m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    
};


#endif /* Matrix4x4_h */
