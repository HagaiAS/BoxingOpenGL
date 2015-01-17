#pragma once
#include "Globals.h"
#include "RgbImage.h"

// The textures id and files
GLuint worldTextures[NUM_OF_WORLD_TEXTURES];
GLuint boxer1Textures[NUM_OF_BODY_TEXTURES];
GLuint boxer2Textures[NUM_OF_BODY_TEXTURES];
GLuint crowdTextures[NUM_OF_BODY_TEXTURES];

char* worldTextureFiles[NUM_OF_WORLD_TEXTURES] = { "./wallTile.bmp",
"./floorTile.bmp" };
char* rockyTextureFiles[NUM_OF_BODY_TEXTURES] = { "./rockyHead.bmp",
"./rockyBody.bmp",
"./rockyHand.bmp",
"./-.bmp",
"./rockySkin.bmp",
"./rockyShorts.bmp" };
char* clubberTextureFiles[NUM_OF_BODY_TEXTURES] = { "./clubberHead.bmp",
"./clubberBody.bmp",
"./clubberHand.bmp",
"./-.bmp",
"./clubberSkin.bmp",
"./clubberShorts.bmp" };
char* crowdTextureFiles[NUM_OF_BODY_TEXTURES] = { "./-.bmp",
"./-.bmp",
"./-.bmp",
"./-.bmp",
"./-.bmp",
"./-.bmp" };


//------------------------------------------------
//                TEXTURES FUNCTIONS
//------------------------------------------------


// This method read a texture map from a BMP bitmap file and insert the id into the textures list
void loadTextureFromFile(char *filename, GLuint* textures, GLuint index)
{
	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	// Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... )

	// Create The Texture
	glGenTextures(1, &textures[index]);
	glBindTexture(GL_TEXTURE_2D, textures[index]);

	// Set textures parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Typical Texture Generation Using Data From The Bitmap
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		theTexMap.GetNumCols(),
		theTexMap.GetNumRows(),
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		theTexMap.ImageData());
}

// This method load the textures from all files and updates the id of each texture
void readTextures(char** fileNames, GLuint* textures)
{
	for (int currTexture = 0; currTexture < NUM_OF_BODY_TEXTURES; currTexture++)
	{
		loadTextureFromFile(fileNames[currTexture], textures, currTexture);
	}
}



