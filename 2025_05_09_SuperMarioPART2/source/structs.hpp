#pragma once

namespace m4rly {
    typedef struct SObject 
    {
        float x, y;
        float width, height;
        float vertSpeed;
        bool IsFly;
        char cType;
        float horizSpeed;
    } TObject;
}