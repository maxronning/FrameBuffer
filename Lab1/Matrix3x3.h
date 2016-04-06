//
//  Matrix3x3.h
//  Lab1
//
//  Created by Max Ronning on 4/1/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#ifndef Matrix3x3_h
#define Matrix3x3_h
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>


class Matrix3x3 {

    public:
    
    // Constructor
    Matrix3x3 (double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)  {
        
        v11 = a11;
        v12 = a12;
        v13 = a13;
        v21 = a21;
        v22 = a22;
        v23 = a23;
        v31 = a31;
        v32 = a32;
        v33 = a33;
        
    }//end Constructor
    
    friend double det(const Matrix3x3& mat) {
        return ((mat.v11 * mat.v22 * mat.v33) + (mat.v12 * mat.v23 * mat.v31) + (mat.v13 * mat.v21 * mat.v32) - (mat.v31 * mat.v22 * mat.v13) - (mat.v32 * mat.v23 * mat.v11) - (mat.v33 * mat.v21 * mat.v12));
    }
    
    private:
    
    double v11, v12, v13, v21, v22, v23, v31, v32, v33;
};


#endif /* Matrix3x3_h */
