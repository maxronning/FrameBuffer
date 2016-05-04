//
//  triangle.h
//  CS 5721
//
//  Created by Max Ronning on 5/2/16.
//  Copyright © 2016 Max Ronning. All rights reserved.
//

#ifndef tri_h
#define tri_h

#include "Vector4D.h"
#include "Vector3D.h"

class tri {
public:
    
    Vector4D p0, p1, p2;
    Vector3D c0, c1, c2;
    
    tri() { }
    
    ~tri() { }
    
    tri(const Vector4D r, const Vector4D s, const Vector4D t, const Vector3D l, const Vector3D m, const Vector3D n) {
        this->p0.set(r.x, r.y, r.z, r.w);
        this->p1.set(s.x, s.y, s.z, s.w);
        this->p2.set(t.x, t.y, t.z, t.w);
        
        this->c0.setVals(l.x, l.y, l.z);
        this->c1.setVals(m.x, m.y, m.z);
        this->c2.setVals(n.x, n.y, n.z);
    }

};


#endif /* tri_h */
