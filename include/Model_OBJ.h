#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H
#if defined(__WIN32__)
#include <windows.h>
#endif
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#define KEY_ESCAPE 27

using namespace std;

/************************************************************************
  Window
 ************************************************************************/

typedef struct {
    int width;
    int height;
    char* title;

    float field_of_view_angle;
    float z_near;
    float z_far;
} glutWindow;



/***************************************************************************
  OBJ Loading
 ***************************************************************************/

class Model_OBJ
{
  private:
    float _x,_y,_z;
    float _a;

  public:
    string info;
    Model_OBJ();
    float* calculateNormal(float* coord1,float* coord2,float* coord3 );
    int Load(char *filename);       // Loads the model
    void Draw();                    // Draws the model on the screen
    void Release();                 // Release the model
    void Convert();
    int SimplifyLoad(char *filename, float ratio);       // Loads the model fom Simplify Module, ratio 0.0 ~ 1.0

    
    void set_xyz(float x, float y, float z){
        _x = x*1.0f;
        _y = y*1.0f;
        _z = z*1.0f;
    };
    void set_a(float a){ 
        if(a > 360) a-= 360;
        _a = a*1.0f;
    };

    float get_x(){ return _x;};
    float get_y(){ return _y;};
    float get_z(){ return _z;};
    float get_a(){ return _a;};

    float* normals;                         // Stores the normals
    float* Faces_Triangles;                 // Stores the triangles
    float* vertexBuffer;                    // Stores the points which make the object
    long TotalConnectedPoints;              // Stores the total number of connected verteces
    long TotalConnectedTriangles;           // Stores the total number of connected triangles



};



#endif // MODEL_OBJ_H
