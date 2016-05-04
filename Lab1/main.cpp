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
    
    Vector4D p0(5, 5, 1, 0), p1(10, 14, 1, 0), p2(15, 5, -5, 0);
    Vector4D p3(5, 6, -1, 0), p4(11, 14, -1, 0), p5(15, 6, -1, 0);
    Vector3D c0(1.0, 1.0, 1.0), c1(1.0, 0, 1.0), c2(1.0,1.0,0.0);
    
    
    FrameBuffer a(500, 500);
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    tri t1(p0,p1,p2,c0,c1,c2);
    tri t2(p3,p4,p5,c1,c2,c1);
    tri arr[] = {t1, t2};
    
    a.ortho1(arr);
    a.writePPM("ortho1.ppm");
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    tri t3(p0,p1,p2,c0,c1,c2);
    tri t4(p3,p4,p5,c1,c2,c1);
    tri arr2[] = {t3, t4};
    
    a.ortho2(arr2);
    a.writePPM("ortho2.ppm");
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    
    Vector4D q(-3, 0, -5, 1), r(3, 4, -5, 1), s(-2, -2, -5, 1);
    Vector3D t(1.0, 1.0, 1.0), u(1.0, 0, 1.0), v(1.0,1.0,0.0);
    Vector4D w(-2, 1, -4, 1), x(2, 2, -8, 1), y(-2, -1, -4, 1);
    Vector3D f(1.0, 1.0, 1.0), f1(1.0, 0.5, 1.0), f2(0.0,1.0,0.5);
    
    tri t5(q,r,s,t,u,v);
    tri t6(w,x,y,f,f1,f2);
    tri arr3[] = {t5,t6};
    tri arr4[] = {t5,t6};
    
    a.persp1(arr3);
    a.writePPM("persp1.ppm");
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    a.persp2(arr4);
    a.writePPM("persp2.ppm");
    a.setAll(50, 50, 50);
    a.setZbuff(-25);
    
    
    Vector4D pc(-6, 0, -5, 1), pc1(2, 10, -5, 1), pc2(-4, -2, -5, 1);
    Vector3D c00(1.0, 1.0, 1.0), c10(1.0, 0, 1.0), c20(1.0,1.0,0.0);
    
    tri first(pc,pc1,pc2,c00,c10,c20);
    
    Vector4D pc3(-2, 14, -7, 1), pc4(-4, 10, -7, 1), pc5(3, -1.5, -3, 1);
    Vector3D c30(0.0, 1.0, 1.0), c40(0.2, 0.0, 1.0), c50(0.3,0.9,0.2);
    
    tri second(pc3,pc4,pc5,c30,c40,c50);
    
    Vector4D pc6(10, 0, -7, 1), pc7(8, 4, -7, 1), pc8(-4, 1.7, -3, 1);
    Vector3D c60(1.0, 0.5, 1.0), c70(1.0, 0.0, 0.2), c80(0.0 ,0.3,1.0);
    
    tri third(pc6,pc7,pc8,c60,c70,c80);
    
    tri create[] = {first, second, third};
    
    
    a.creative(create);
    a.writePPM("creative.ppm");
    
    
    std::cout << std::endl;
    
}
