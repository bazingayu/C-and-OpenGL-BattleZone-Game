#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <iostream>
#include "Texture.h"
#include "GL/freeglut.h"
#include "IncludeS.h"

#define PI 3.14159
#define RAND_COORD(x)  ((float)rand()/RAND_MAX * (x))

class Terrain
{
private:
	//terrain data
	float terrain[mapX * mapZ][3];         //heightfield terrain data (0-255)
	GLuint indexArray[mapX * mapZ *2];     //vertex array
	float colorArray[mapX * mapZ][3];     //color array
	float texcoordArray[mapX * mapZ][2];  //texcoord array
public:
	
	Texture sandTexture;
	Texture treeTexture;
	
	Terrain();
	~Terrain();
	
	void loadTexture(char *filename, Texture &texture);
	void initializeTerrain(char *sandFileName, char *treeFileName);   //initialize vertex array
	float GetHeight(float x, float z);
	
	void drawSand();
	void drawTree();
	void drawTerrain();
};

#endif