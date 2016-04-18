//
//  Homework 3
//
//  Created by Max Ronning on 1/18/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//  Dedicated to Kendelle Perkins

#include <iostream>
#include <math.h>
#include "Vector2D.h"
#include "Vector3D.h"
#include "FrameBuffer.h"
#include "Matrix3x3.h"

int main(int argc, const char * argv[]) {
    
    FrameBuffer a(500, 500);
    a.setAll(50, 50, 50);
    
    a.raytrace();
    
    a.writePPM("omgPLS.ppm");
    
    std::cout << std::endl;
    
    
    return 0;
}
