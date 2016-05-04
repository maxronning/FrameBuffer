//
//  FrameBuffer.cpp
//  Homework 3
//
//  Created by Max Ronning on 1/21/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(int width, int height) {
    setWidth(width);
    setHeight(height);
    std::cout << "(" << getWidth() << "," << getHeight() << ")\n";
    my2Dpointer = new pixColor*[width];
    zBuff = new double*[width];
    for(int i = 0; i < width; i++) {
        my2Dpointer[i] = new pixColor[height];
        zBuff[i] = new double[height];
    }
};

void FrameBuffer::setZbuff(double z) {
    for (int j = 0; j < getHeight(); j++) {
        for (int i = 0; i < getWidth(); i++) {
            zBuff[i][j] = z;
        }
    }
}

void FrameBuffer::printZbuff() {
    for (int y = getHeight() - 1; y >= 0; y--) {
        cout << "\n";
        
        for (int x = 0; x < getWidth(); x++) {
            cout << zBuff[x][y] << " ";
        }
    }
}

void FrameBuffer::set(int x, int y, short int red, short int green, short int blue) {
    if (x == getWidth()) {x -= 1;}
    if (y == getHeight()) {y -= 1;}
    
    my2Dpointer[x][y].r = red;
    my2Dpointer[x][y].g = green;
    my2Dpointer[x][y].b = blue;
    
    
};

int FrameBuffer::getWidth() const  {
    return width;
};

int FrameBuffer::getHeight() const  {
    return height;
};

void FrameBuffer::rasterizeline_implicit(const Vector2D& p0, const Vector2D &p1, const Vector3D& c) {
    
    if (p0.x > p1.x) {
        rasterizeline_implicit(p1, p0, c);
    }
    
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    
    
    //Control for when line is vertical
    if (dx == 0) {
        int yDiff = std:: abs(p0.y - p1.y);
        if (p0.y > p1.y) {
            for (int y = p1.y; y <= yDiff +p1.y; y++){
            set(p0.x, y, c.x, c.y, c.z);
            }
        }
        else {
            for (int y = p0.y; y <= yDiff + p0.y; y++){
                set(p0.x, y, c.x, c.y, c.z);
            }
        }
    }
    else if (dy == 0) { //Control for when slope is horizontal
        int xDiff = std:: abs(p0.x - p1.x);
        if (p0.x > p1.x) {
            for (int x = p1.x; x <= xDiff + p1.x; x++){
                set(x, p0.y, c.x, c.y, c.z);
            }
        }
        else {
            for (int x = p0.x; x <= xDiff + p0.x; x++){
                set(x, p0.y, c.x, c.y, c.z);
            }
        }
    }
    else { //Control when slope is anything other and 1 or 0
       for (int x = p0.x; x <= p1.x; x++){
           int y = p0.y + dy * (x - p0.x) / dx;
           set(x, y, c.x, c.y, c.z);
       }
    }
};

void FrameBuffer::rasterizeline_parametric( const Vector2D& p0, const Vector2D &p1, const Vector3D& c0, const Vector3D& c1) {
    
    Vector3D deltaC(c0.x * 255, c0.y * 255, c0.z * 255);
    
    double deltaR = c1.x - c0.x;
    double deltaG = c1.y - c0.y;
    double deltaB = c1.z - c0.z;
    
    int deltaX = p1.x - p0.x;
    int deltaY = p1.y - p0.y;
    double distance = (double) std::sqrt( (deltaX * deltaX) + (deltaY * deltaY) );
    
    deltaR = (deltaR / distance) * 255;
    deltaG = (deltaG / distance) * 255;
    deltaB = (deltaB / distance) * 255;
    
    Vector3D c(deltaR, deltaG, deltaB);

    
    if (p0.x > p1.x) {
        rasterizeline_parametric(p1, p0, c1, c0);
    }
    
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    
    //Control for when line is vertical
    if (dx == 0) {
        int yDiff = std:: abs(p0.y - p1.y);
        if (p0.y > p1.y) {
            for (int y = p1.y; y <= yDiff +p1.y; y++) {
                set(p0.x, y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
        else {
            for (int y = p0.y; y <= yDiff + p0.y; y++) {
                set(p0.x, y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
                
            }
        }
    }
    else if (dy == 0) { //Control for when slope is horizontal
        int xDiff = std:: abs(p0.x - p1.x);
        if (p0.x > p1.x) {
            for (int x = p1.x; x <= xDiff + p1.x; x++) {
                set(x, p0.y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
        else {
            for (int x = p0.x; x <= xDiff + p0.x; x++) {
                set(x, p0.y, deltaC.x, deltaC.y, deltaC.z);
                deltaC = deltaC + c;
            }
        }
    }
    else { //Control when slope is anything other and 1 or 0
        for (int x = p0.x; x <= p1.x; x++) {
            int y = p0.y + dy * (x - p0.x) / dx;
            set(x, y, deltaC.x, deltaC.y, deltaC.z);
            deltaC = deltaC + c;
            
        }
    }
};

void FrameBuffer::rasterizeTriangle(const Vector4D &p0, const Vector4D &p1, const Vector4D &p2,
                                    const Vector3D& c0, const Vector3D& c1, const Vector3D& c2) {
    
    double alpha, beta, gamma, f_A, f_B, f_G, z;
    
    int orderY[3] = {(int) p0.y, (int) p1.y, (int) p2.y};
    std::sort(std::begin(orderY),std::end(orderY));
    
    int orderX[3] = {(int) p0.x, (int) p1.x, (int) p2.x};
    std::sort(std::begin(orderX),std::end(orderX));
    
    int yMin = orderY[0];
    int yMax = orderY[2];
    
    int xMin = orderX[0];
    int xMax = orderX[2];
    
    Vector3D l(-1.0,1.0, 1.0); //light location vector
//    Vector4D norm = (p1 - p0).cross((p2 - p0));
    
    f_A = (p1.y - p2.y) * p0.x + (p2.x - p1.x) * p0.y + (p1.x * p2.y) - (p2.x * p1.y);
    f_B = (p2.y - p0.y) * p1.x + (p0.x - p2.x) * p1.y + (p2.x * p0.y) - (p0.x * p2.y);
    f_G = (p0.y - p1.y) * p2.x + (p1.x - p0.x) * p2.y + (p0.x * p1.y) - (p1.x * p0.y);
    
    for (int y = yMin; y <= yMax; y++) {
        for (int x = xMin; x <= xMax; x++) {
            
            alpha = ((p1.y - p2.y) * x + (p2.x - p1.x) * y + (p1.x * p2.y) - (p2.x * p1.y)) / f_A;
            beta  = ((p2.y - p0.y) * x + (p0.x - p2.x) * y + (p2.x * p0.y) - (p0.x * p2.y)) / f_B;
            gamma = ((p0.y - p1.y) * x + (p1.x - p0.x) * y + (p0.x * p1.y) - (p1.x * p0.y)) / f_G;
            z = alpha * p0.z + beta * p1.z + gamma * p2.z;
            
            if (alpha >= 0 && beta >= 0 && gamma >= 0) {
                if (  (alpha > 0 || (f_A * ((p1.y - p2.y) * -1 + (p2.x - p1.x) * -1 + (p1.x * p2.y) - (p2.x * p1.y)) > 0)) &&
                      (beta > 0 || (f_B * ((p2.y - p0.y) * -1 + (p0.x - p2.x) * -1 + (p2.x * p0.y) - (p0.x * p2.y)) > 0)) &&
                      (gamma > 0 || (f_G * (p0.y - p1.y) * -1 + (p1.x - p0.x) * -1 + (p0.x * p1.y) - (p1.x * p0.y)) > 0)) {
                    
                    if ( z > zBuff[x][y]) { // NOTE z values are negative!
                        zBuff[x][y] = z;
                        
                        Vector3D color1(0.0, 0.0, 0.0);
                        Vector3D color2(0.0, 0.0, 0.0);
                        Vector3D color3(0.0, 0.0, 0.0);
                        Vector3D finalColor(0.0, 0.0, 0.0);
                        
                        color1 = c0 * alpha;
                        color2 = c1 * beta;
                        color3 = c2 * gamma;
                        finalColor = (c0 * alpha) + (c1 * beta) + (c2 * gamma);
                        finalColor = finalColor * 255;
                        
                        set(x, y, finalColor.x, finalColor.y, finalColor.z);
                    }
                }
            }
        }
    }
};

void FrameBuffer::setWidth(int a)  {
    width = a;
};

void FrameBuffer::setHeight(int a) {
    height = a;
};

void FrameBuffer::setAll(short int red, short int green, short int blue) {
    for (int j = 0; j < getHeight(); j++) {
        for (int i = 0; i < getWidth(); i++) {
            my2Dpointer[i][j].r = red;
            my2Dpointer[i][j].g = green;
            my2Dpointer[i][j].b = blue;
        }
    }
};

double FrameBuffer::hit(Circle3D c, Vector3D e, Vector3D dist) {
    
    double dp = dist.dot(e - c.location());
    
    //Computes if current ray intersects object
    double t = ( (-1)*dp - sqrt( pow(dp, 2) - dist.dot(dist)*((e - c.location()).dot(e - c.location()) - pow(c.getRad(), 2)))) / (dist.dot(dist));
    
    return t;
};

void FrameBuffer::ortho1(tri arr[]) {
   
    for (int k = 0; k < 2; k++) {
    
        //viewing area
        double l = -10.0;
        double r =  10.0;
        double b = -10.0;
        double t =  10.0;
        double n =  -5.0;
        double f = -25.0;
        
        //Matrices used for transformations
        Matrix4x4 mOrtho, mVP, M;
        
        mOrtho.makeOrtho(r, l, b, t, n, f);
        
        mVP.makeVP(this->getWidth(), this->getHeight());
        mOrtho.output();
        mVP.output();
        //create transform matrix
        M = mVP * mOrtho;
        M.output();
        arr[k].p0 = M * arr[k].p0;
        arr[k].p1 = M * arr[k].p1;
        arr[k].p2 = M * arr[k].p2;
        
        rasterizeTriangle(arr[k].p0, arr[k].p1, arr[k].p2, arr[k].c0, arr[k].c1, arr[k].c2);
    }
}

void FrameBuffer::ortho2(tri arr[]) {
    
    for (int k = 0; k < 2; k++) {
    
        //viewing area
        double l = -10.0;
        double r =  10.0;
        double b = -10.0;
        double t =  10.0;
        double n =  -5.0;
        double f = -25.0;
        
        Matrix4x4 mOrtho, mVP, mCam, M, e;
        
        //Vectors for the camera transformation matrix
        Vector3D eye(1.0, 1.0, 10.0), gaze(0.0, 0.0, -1.0), viewUp(0.1, 1.0, 0.0);
        Vector3D u, v, w;
        
        //UVW basis for camera
        w = gaze.normalize() * -1;
        u = (viewUp.cross(w)).normalize();
        v = w.cross(u);
        
        mCam.set(u.x, u.y, u.z, 0,
                 v.x, v.y, v.z, 0,
                 w.x, w.y, w.z, 0,
                 0, 0, 0, 0);
        
        e.set(1, 0, 0, (-1)*eye.x,
              0, 1, 0, (-1)*eye.y,
              0, 0, 1, (-1)*eye.z,
              0, 0, 0, 1);
        
        mCam = mCam * e;
        mCam.output();
        mOrtho.makeOrtho(r, l, b, t, n, f);
        mVP.makeVP(this->getWidth(), this->getHeight());
        
        //create matrix to
        M = mVP * mOrtho * mCam;
        M.output();
        arr[k].p0 = M * arr[k].p0;
        arr[k].p1 = M * arr[k].p1;
        arr[k].p2 = M * arr[k].p2;
        
        rasterizeTriangle(arr[k].p0, arr[k].p1, arr[k].p2, arr[k].c0, arr[k].c1, arr[k].c2);
        
    }
}

void FrameBuffer::persp1(tri arr[]){
    
    //viewing area
    double l = -10.0;
    double r =  10.0;
    double b = -10.0;
    double t =  10.0;
    double n =  -5.0;
    double f = -25.0;
    
    for (int k = 0; k < 2; k++) {
    
        Matrix4x4 mOrtho, mPersp, mVP, mCam, M, e, P;
        
        //Triangle points and colors
//        Vector4D p0(-3, 0, -5, 1), p1(1, 5, -5, 1), p2(-2, -1, -5, 1);
//        Vector3D c0(1.0, 1.0, 1.0), c1(1.0, 0, 1.0), c2(1.0,1.0,0.0);
        
        //Vectors for the camera transformation matrix
        Vector3D eye(0.0, 0.0, 0.0), gaze(0.0, 0.0, -1.0), viewUp(0.0, 1.0, 0.0);
        Vector3D u, v, w;
        
        //UVW basis for camera
        w = gaze.normalize() * -1;
        u = (viewUp.cross(w)).normalize();
        v = w.cross(u);
        
        //setting the camera matrix
        mCam.set(u.x, u.y, u.z, 0,
                 v.x, v.y, v.z, 0,
                 w.x, w.y, w.z, 0,
                 0, 0, 0, 1);
        
        //setting the eye matrix
        e.set(1, 0, 0, (-1)*eye.x,
              0, 1, 0, (-1)*eye.y,
              0, 0, 1, (-1)*eye.z,
              0, 0, 0, 1);

        mCam = mCam * e;

        P.set(n, 0, 0, 0, 0, n, 0, 0, 0, 0, n+f, (-1)*f*n, 0, 0, 1, 0);
        
        mOrtho.makeOrtho(r, l, b, t, n, f);
        mPersp = mOrtho*P;
        mVP.makeVP(this->getWidth(), this->getHeight());

        //create matrix to
        M = mVP * mPersp * mCam;
        
        arr[k].p0 = M * arr[k].p0;
        arr[k].p1 = M * arr[k].p1;
        arr[k].p2 = M * arr[k].p2;
        
        rasterizeTriangle( (arr[k].p0 / arr[k].p0.w), (arr[k].p1 / arr[k].p1.w), (arr[k].p2 / arr[k].p2.w), arr[k].c0, arr[k].c1, arr[k].c2);
    }
}

void FrameBuffer::persp2(tri arr[]) {
    
    //viewing area
    double l = -10.0;
    double r =  10.0;
    double b = -10.0;
    double t =  10.0;
    double n =  -5.0;
    double f = -25.0;
    
    for (int k = 0; k < 2; k++) {
        
        Matrix4x4 mOrtho, mPersp, mVP, mCam, M, e, P;
        
        //Triangle points and colors
        //        Vector4D p0(-3, 0, -5, 1), p1(1, 5, -5, 1), p2(-2, -1, -5, 1);
        //        Vector3D c0(1.0, 1.0, 1.0), c1(1.0, 0, 1.0), c2(1.0,1.0,0.0);
        
        //Vectors for the camera transformation matrix
        Vector3D eye(0.0, 0.0, 0.0), gaze(0.0, 0.0, -1.0), viewUp(0.1, 1.0, 0.0);
        Vector3D u, v, w;
        
        //UVW basis for camera
        w = gaze.normalize() * -1;
        u = (viewUp.cross(w)).normalize();
        v = w.cross(u);
        
        //setting the camera matrix
        mCam.set(u.x, u.y, u.z, 0,
                 v.x, v.y, v.z, 0,
                 w.x, w.y, w.z, 0,
                 0, 0, 0, 1);
        
        //setting the eye matrix
        e.set(1, 0, 0, (-1)*eye.x,
              0, 1, 0, (-1)*eye.y,
              0, 0, 1, (-1)*eye.z,
              0, 0, 0, 1);
        
        mCam = mCam * e;
        
        P.set(n, 0, 0, 0, 0, n, 0, 0, 0, 0, n+f, (-1)*f*n, 0, 0, 1, 0);
        
        mOrtho.makeOrtho(r, l, b, t, n, f);
        mPersp = mOrtho*P;
        mVP.makeVP(this->getWidth(), this->getHeight());
        
        //create matrix to
        M = mVP * mPersp * mCam;
        
        arr[k].p0 = M * arr[k].p0;
        arr[k].p1 = M * arr[k].p1;
        arr[k].p2 = M * arr[k].p2;
        
        rasterizeTriangle( (arr[k].p0 / arr[k].p0.w), (arr[k].p1 / arr[k].p1.w), (arr[k].p2 / arr[k].p2.w), arr[k].c0, arr[k].c1, arr[k].c2);
    }
    
};

void FrameBuffer::creative(tri arr[]) {
    
    //viewing area
    double l = -10.0;
    double r =  10.0;
    double b = -10.0;
    double t =  10.0;
    double n =  -5.0;
    double f = -25.0;
    
    for (int k = 0; k < 4; k++) {
        
        Matrix4x4 mOrtho, mPersp, mVP, mCam, M, e, P;
        
        //Vectors for the camera transformation matrix
        Vector3D eye(0.0, 0.0, 0.0), gaze(0.0, 0.0, -1.0), viewUp(0.0, 1.0, 0.0);
        Vector3D u, v, w;
        
        //UVW basis for camera
        w = gaze.normalize() * -1;
        u = (viewUp.cross(w)).normalize();
        v = w.cross(u);
        
        //setting the camera matrix
        mCam.set(u.x, u.y, u.z, 0,
                 v.x, v.y, v.z, 0,
                 w.x, w.y, w.z, 0,
                 0, 0, 0, 1);
        
        //setting the eye matrix
        e.set(1, 0, 0, (-1)*eye.x,
              0, 1, 0, (-1)*eye.y,
              0, 0, 1, (-1)*eye.z,
              0, 0, 0, 1);
        
        mCam = mCam * e;
        
        P.set(n, 0, 0, 0, 0, n, 0, 0, 0, 0, n+f, (-1)*f*n, 0, 0, 1, 0);
        
        mOrtho.makeOrtho(r, l, b, t, n, f);
        mPersp = mOrtho*P;
        mVP.makeVP(this->getWidth(), this->getHeight());
        
        //create matrix to
        M = mVP * mPersp * mCam;
        
        arr[k].p0 = M * arr[k].p0;
        arr[k].p1 = M * arr[k].p1;
        arr[k].p2 = M * arr[k].p2;
        
        rasterizeTriangle( (arr[k].p0 / arr[k].p0.w), (arr[k].p1 / arr[k].p1.w), (arr[k].p2 / arr[k].p2.w), arr[k].c0, arr[k].c1, arr[k].c2);
    }
    
};


void FrameBuffer::raytrace(Circle3D circles[]) { //Implements orthographic ray tracing
    
    //Bounds of viewing window
    double left = -1.0;
    double right = 1.0;
    double bottom = -1.0;
    double top = 1.0;
    double near = 0.0;
    double far = 10.0;
        
    for (int k = 0; k <= 1; k++ ) {
        for (int j = 0; j < getHeight(); j++) { // Framebuffer loops to create ray tracing window
            for (int i = 0; i < getWidth(); i++) {
            
                //Create ray tracing grid (with arbitrary units)
                double u = (left + (right - left)*(i + 0.5)) / getWidth();
                double v = (bottom + (top - bottom)*(j + 0.5)) / getHeight();
                
                Vector3D d(u, v, -5.0); //Distance vector
                Vector3D e(0.0, 0.0, 5.0); //location of viewing 'eye'
            
                double t = hit(circles[k], e, d);
                
                Vector3D l(-1.0,0.5, 1.0); //light location vector
                Vector3D lColor(0.0, 0.0, 1.0);
                Vector3D ray = e + d * t; //ray vector
                Vector3D norm = (ray - circles[k].location())/circles[k].getRad();
                
                Vector3D d_eye(0, 0, 1.0);
                Vector3D preH = d_eye+l;
                Vector3D h = preH.normalize();
                
                Vector3D I_a(1.0, 1.0, 1.0); //Ambient light intensity
                Vector3D k_a(1.0, 1.0, 1.0); //Ambient light color
                Vector3D k_d(1.0, 1.0, 1.0);
                
                if (k == 1) k_d.setVals(0.0, 1.0, 0.0);
                
                double k_s = 0.9; //Specular color of the surface
                
                Vector3D L(0.0, 0.0, 0.0);
                
                if (norm.dot(l) > 0 && norm.dot(h)) {
                    L = k_a.cross(I_a) + k_d * (norm.dot(l));
                    
                    L = L + lColor * k_s * pow(norm.dot(h), 10); //max = non negative dot product
                    
                    if (L.x > 1.0) L.setVals(1.0, L.y, L.z);
                    if (L.y > 1.0) L.setVals(L.x, 1.0, L.z);
                    if (L.z > 1.0) L.setVals(L.x, L.y, 1.0);
                
                }
            
                //If ray intersects object, set pixel to yellow
                if (t >= near && t <= far) {
                    set(i, j, lColor.x * L.x * 255, lColor.y * L.y * 255, lColor.z * L.z * 255);
                }
            }
        }
    }
};

void FrameBuffer::writePPM(const std::string filename) const {
    
    std::ofstream os;
    os.open(filename.c_str(), std::ofstream::out);
    os << "P3\r\n# " << filename << "\r\n" << getWidth() << " " << getHeight() << " 255""\n";
    
    for (int y = getHeight() - 1; y >= 0; y--) {
        os << "\n";
    
        for (int x = 0; x < getWidth(); x++) {
            os << my2Dpointer[x][y].r << " "
                << my2Dpointer[x][y].g << " "
                 << my2Dpointer[x][y].b << " ";
        }
    }
    os.close();
};

int* FrameBuffer::bufferData() {
    int entries = getHeight() * getWidth() * 3;
    int* buffData = new int[entries];
    int k = 0;
    
    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            buffData[k] = my2Dpointer[x][y].r;
            k++;
            buffData[k] = my2Dpointer[x][y].g;
            k++;
            buffData[k] = my2Dpointer[x][y].b;
            k++;
        }
    }
    
    return buffData;
};
