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
#include "Matrix4x4.h"

int main(int argc, const char * argv[]) {
    
    FrameBuffer a(1000, 1000);
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    a.ortho1();
    a.writePPM("ortho1.ppm");
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    a.ortho2();
    a.writePPM("ortho2.ppm");
    a.setAll(50, 50, 50);
    
    a.setZbuff(-25);
    a.persp1();
    a.writePPM("persp1.ppm");
    a.setAll(50, 50, 50);
    
//    a.persp2();
//    a.writePPM("persp2.ppm");
//    a.setAll(50, 50, 50);
    
    std::cout << std::endl;
    
}
