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
    
    FrameBuffer a(1000, 1000);
    a.setAll(100, 100, 100);
    
    a.raytrace();
    
    a.writePPM("omgPLS.ppm");
    
    std::cout << std::endl;
    
    
    return 0;
}
