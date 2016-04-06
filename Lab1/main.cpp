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

    
//    //First Triangle
//    FrameBuffer hw3_1 = FrameBuffer(1000, 1000);
//    hw3_1.setAll(0, 0, 0);
//    
//    Vector2D t1_1(0,0);
//    Vector2D t1_2(hw3_1.getWidth() - 1, 0);
//    Vector2D t1_3(hw3_1.getWidth() - 1, hw3_1.getHeight() - 1);
//    Vector3D c1(1.0,0.0,0.0);
//    
//    //hw3_1.rasterizeTriangle(t1_1, t1_2, t1_3, c1, c1, c1);
//    
//    Vector2D t2_4(hw3_1.getWidth() - 1 , hw3_1.getHeight() - 1);
//    Vector2D t2_5(0, hw3_1.getHeight()-1);
//    Vector2D t2_6(0, 0);
//    Vector3D c2(1.0, 0.0, 0.0);
//    Vector3D c3(0.0, 1.0, 0.0);
//    Vector3D c4(0.0, 0.0, 1.0);
//    
//    //hw3_1.rasterizeTriangle(t2_4, t2_5, t2_6, c2, c3, c4);
//    
//    //hw3_1.writePPM("HW3_1.ppm");
//    
///*--------------------------------------------------------------------------*/
//    
//    //Second Triangle
//    FrameBuffer hw3_2 = FrameBuffer(1000, 1000);
//    hw3_2.setAll(0, 0, 0);
//    
//    Vector2D a(200, 0);
//    Vector2D b(200, 200);
//    Vector2D c(0, 200);
//    Vector3D col1(1.0, 1.0, 0.0);
//    Vector3D col2(0.0, 1.0, 1.0);
//    Vector3D col3(1.0, 0.0, 1.0);
//    
//    //hw3_2.rasterizeTriangle(a, b, c, col1, col2, col3);
//    
//    Vector2D d(200, 0);
//    Vector2D e(hw3_2.getWidth()-1, 200);
//    Vector2D f(200, 200);
//    Vector3D col4(1.0, 0.0, 0.0);
//    Vector3D col5(1.0, 0.0, 0.0);
//    Vector3D col6(0.0, 0.0, 1.0);
//    
//    //hw3_2.rasterizeTriangle(d, e, f, col4, col5, col6);
//    
//    Vector2D g(200, hw3_2.getHeight()-1);
//    Vector2D h(200, 200);
//    Vector2D i(hw3_2.getWidth()-1, 200);
//    Vector3D col7(0.0, 1.0, 0.0);
//    Vector3D col8(0.0, 0.0, 0.0);
//    Vector3D col9(0.0, 0.0, 1.0);
//    
//    //hw3_2.rasterizeTriangle(g, h, i, col7, col8, col9);
//    
//    Vector2D j(200, 200);
//    Vector2D k(200, hw3_2.getHeight()-1);
//    Vector2D l(0, 200);
//    Vector3D col10(0.0, 1.0, 0.0);
//    Vector3D col11(1.0, 1.0, 0.0);
//    Vector3D col12(1.0, 1.0, 1.0);
//    
//    hw3_2.rasterizeTriangle(j, k, l, col10, col11, col12);
//    
//    //hw3_2.writePPM("HW3_2.ppm");
//    
///*--------------------------------------------------------------------------*/
//    
//    FrameBuffer hw3_3(1000,1000);
//    Vector3D white(255, 255, 255);
//
//    Vector3D red(1.0, 0, 0);
//    Vector3D blue(0,0,1);
//    
//    // Square
//    Vector2D p0(0, 0);
//    Vector2D p1(0, 200);
//    Vector2D p2(200, 0);
//    Vector2D p3(200,200);
//    
//    hw3_3.rasterizeTriangle(p0, p1, p2, red, red, blue);
//    hw3_3.rasterizeTriangle(p1, p2, p3, red, blue, blue);
//    
//    hw3_3.rasterizeline_implicit(p0, p1, white);
//    hw3_3.rasterizeline_implicit(p1, p2, white);
//    hw3_3.rasterizeline_implicit(p0, p2, white);
//    hw3_3.rasterizeline_implicit(p1, p3, white);
//    hw3_3.rasterizeline_implicit(p3, p2, white);
//    
//    
//    //Hexagon
//    Vector2D center(500, 500);
//    p0.setVals(400, 700);
//    p1.setVals(600, 700);
//    p2.setVals(700, 500);
//    p3.setVals(600, 300);
//    Vector2D p4(400, 300);
//    Vector2D p5(300, 500);
    
//    hw3_3.rasterizeTriangle(center, p0, p1, blue, red, red);
//    hw3_3.rasterizeTriangle(center, p1, p2, blue, red, red);
//    hw3_3.rasterizeTriangle(center, p2, p3, blue, red, red);
//    hw3_3.rasterizeTriangle(center, p3, p4, blue, red, red);
//    hw3_3.rasterizeTriangle(center, p4, p5, blue, red, red);
//    hw3_3.rasterizeTriangle(center, p5, p0, blue, red, red);
//    
//    hw3_3.rasterizeline_implicit(center, p0, white);
//    hw3_3.rasterizeline_implicit(center, p1, white);
//    hw3_3.rasterizeline_implicit(center, p2, white);
//    hw3_3.rasterizeline_implicit(center, p3, white);
//    hw3_3.rasterizeline_implicit(center, p4, white);
//    hw3_3.rasterizeline_implicit(center, p5, white);
//    
//    hw3_3.rasterizeline_implicit(p0, p1, white);
//    hw3_3.rasterizeline_implicit(p1, p2, white);
//    hw3_3.rasterizeline_implicit(p2, p3, white);
//    hw3_3.rasterizeline_implicit(p3, p4, white);
//    hw3_3.rasterizeline_implicit(p4, p5, white);
//    hw3_3.rasterizeline_implicit(p5, p0, white);
    
//    //Pentagon
//    p0.setVals(hw3_3.getWidth() - 100, hw3_3.getHeight());
//    p1.setVals(hw3_3.getWidth(), hw3_3.getHeight()-100);
//    p2.setVals(hw3_3.getWidth()-200, hw3_3.getHeight()-100);
//    p3.setVals(hw3_3.getWidth()-200, hw3_3.getHeight()-300);
//    p4.setVals(hw3_3.getWidth(), hw3_3.getHeight()-300);
    
//    hw3_3.rasterizeTriangle(p0, p1, p2, blue, red, red);
//    hw3_3.rasterizeTriangle(p2, p1, p3, blue, red, red);
//    hw3_3.rasterizeTriangle(p3, p4, p1, blue, red, red);
//    
//    hw3_3.rasterizeline_implicit(p0, p1, white);
//    hw3_3.rasterizeline_implicit(p1, p2, white);
//    hw3_3.rasterizeline_implicit(p0, p2, white);
//    hw3_3.rasterizeline_implicit(p1, p3, white);
//    hw3_3.rasterizeline_implicit(p3, p2, white);
//    hw3_3.rasterizeline_implicit(p3, p4, white);
//    hw3_3.rasterizeline_implicit(p4, p1, white);
//    
//    hw3_3.writePPM("HW3_3.ppm");
    
/*--------------------------------------------------------------------------*/
    
    //Creative
    
//    FrameBuffer hw3_4(1000,1000);
//    
//    center.setVals(542, 486);
//    p0.setVals(475, 675);
//    p1.setVals(776, 606);
//    p2.setVals(746, 280);
//    p3.setVals(536, 98);
//    p4.setVals(246, 250);
//    p5.setVals(220, 585);
//    
//    Vector3D left1(0.11, 0.20, 0.24);
//    Vector3D left2(0.11, 0.20, 0.24);
//    Vector3D left3(0.09, 0.18, 0.40);
//    
//    hw3_4.rasterizeTriangle(center, p0, p1, blue, red, red);
//    hw3_4.rasterizeTriangle(center, p1, p2, blue, red, red);
//    hw3_4.rasterizeTriangle(center, p2, p3, blue, red, blue);
//    hw3_4.rasterizeTriangle(center, p3, p4, left3, left2, left1);
//    hw3_4.rasterizeTriangle(center, p4, p5, left3, left1, left2);
//    hw3_4.rasterizeTriangle(center, p5, p0, blue, red, red);
    
    //hw3_4.writePPM("HW3_4.ppm");
    
    //std::cout << std::endl << det(test) << std::endl;
    
    FrameBuffer a(1000, 1000);
    
    a.raytrace();
    
    a.writePPM("omgPLS.ppm");
    
    std::cout << std::endl;
    
    
    return 0;
}
