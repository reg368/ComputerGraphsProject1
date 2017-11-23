#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H
#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
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
  public:
	Model_OBJ();
    float* calculateNormal(float* coord1,float* coord2,float* coord3 );
    int Load(string filearray[],int arrsize);	// Loads the model
	void Draw(int i);					// Draws the model on the screen
	void Release();				// Release the model

	float* normals;							// Stores the normals
    float* Faces_Triangles;					// Stores the triangles
	float* vertexBuffer;					// Stores the points which make the object
	long TotalConnectedPoints;				// Stores the total number of connected verteces
	long TotalConnectedTriangles;			// Stores the total number of connected triangles

	std::vector<float*> v_normals;
	std::vector<float*> v_Faces_Triangles;
	std::vector<float*> v_vertexBuffer;
	std::vector<long> v_TotalConnectedPoints;
	std::vector<long> v_TotalConnectedTriangles;

};



#endif // MODEL_OBJ_H
