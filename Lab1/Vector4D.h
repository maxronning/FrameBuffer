//
//  Vector4D.h
//  CS 5721
//
//  Created by Max Ronning on 4/22/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

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
    
    //prints the contents of the vector
    void output() {
        cout << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")" << endl;
    }
    
    // Overloaded scalar division operator
    Vector4D operator /(double scalar) const
    {
        return (Vector4D(x / scalar, y / scalar, z / scalar, w / scalar));
    }
    
};

#endif /* Vector4D_h */
