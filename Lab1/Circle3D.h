//
//  Circle3D.h
//  Lab1
//
//  Created by Max Ronning on 4/6/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#ifndef Circle3D_h
#define Circle3D_h

class Circle3D {
    public:
    
    Circle3D(const Vector3D& c, double radius) {
        x = c.x;
        y = c.y;
        z = c.z;
        r = radius;
    }
    
    Vector3D location() {
        return Vector3D(this->x, this->y, this->z);
    }
    
    double getRad() {
        return this->r;
    }
    
    private:
    double x, y, z, r;
};

#endif /* Circle3D_h */
