/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkCubicMap_DEFINED
#define SkCubicMap_DEFINED

#include "SkPoint.h"

/**
 *  Fast evaluation of a cubic ease-in / ease-out curve. This is defined as a parametric cubic
 *  curve inside the unit square.
 *
 *  pt[0] is implicitly { 0, 0 }
 *  pt[3] is implicitly { 1, 1 }
 *  pts[1,2] are inside the unit square
 */
class SK_API SkCubicMap {
public:
    SkCubicMap(SkPoint p1, SkPoint p2);

    float computeYFromX(float x) const;

    SkPoint computeFromT(float t) const;

private:
    enum Type {
        kLine_Type,     // x == y
        kCubeRoot_Type, // At^3 == x
        kSolver_Type,   // general monotonic cubic solver
    };

    SkPoint fCoeff[3];
    Type    fType;
};

#endif
