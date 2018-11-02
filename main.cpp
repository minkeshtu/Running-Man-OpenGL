#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include "imageloader.h"

#define c 3.14/180
#define PI  3.14
#define TWO_PI  2.0 * PI
#define RAD_TO_DEG  180.0 / PI
GLuint _textureBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow, _textureSky,_textureTower;
float _angle = 0.0;
enum
{	// Constants for different views
	HELICOPTER,FRONT,SIDE,BACK
} viewpoint = BACK;


int MID=570;
int start=0;

char KEY; //Variable that stores key pressed by user

float angle; //Rotation angle for man

float carx=0,cary=570;


//Function that generate a cone
void cone()
{
	float i,x,y,r=10;

	glColor3f(0.2,0.1,0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0,0,20);
	for(i=0;i<=361;i+=2)
	{
		x= r * cos(i*c);
		y= r * sin(i*c);
		glVertex3f(x,y,0);
	}
	glEnd();
}


//Function that generate a cone
void cube(float a ,float b ,float d)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
    glBegin(GL_QUADS);
	
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord3f(0.0,2.0,0.1); glVertex3f(-a, a, a);
	glTexCoord3f(4.0,2.0,0.1); glVertex3f(a, a, a);
	glTexCoord3f(4.0,0.0,0.1); glVertex3f(a, a, -a);
	glTexCoord3f(0.0,0.0,0.1); glVertex3f(-a, a, -a);

	glEnd();
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
	glBegin(GL_QUADS);
	
	// front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord3f(0.0,2.0,0.1); glVertex3f(a, -a, a);
	glTexCoord3f(4.0,2.0,0.1); glVertex3f(a, a, a);
	glTexCoord3f(4.0,0.0,0.1); glVertex3f(-a, a, a);
	glTexCoord3f(0.0,0.0,0.1); glVertex3f(-a, -a, a);

	glEnd();
	glPopMatrix();

	glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
	glBegin(GL_QUADS);
	
	// right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord3f(0.0,2.0,0.1); glVertex3f(a, a, -a);
	glTexCoord3f(4.0,2.0,0.1); glVertex3f(a, a, a);
	glTexCoord3f(4.0,0.0,0.1); glVertex3f(a, -a, a);
	glTexCoord3f(0.0,0.0,0.1); glVertex3f(a, -a, -a);

	glEnd();
    glPopMatrix();

	glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
	glBegin(GL_QUADS);
	
	// left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord3f(0.0,2.0,0.1); glVertex3f(-a, -a, a);
	glTexCoord3f(4.0,2.0,0.1); glVertex3f(-a, a, a);
	glTexCoord3f(4.0,0.0,0.1); glVertex3f(-a, a, -a);
	glTexCoord3f(0.0,0.0,0.1); glVertex3f(-a, -a, -a);

	glEnd();
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
	glBegin(GL_QUADS);
	
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(a, -a, a);
	glVertex3f(-a, -a, a);
	glVertex3f(-a, -a, -a);
	glVertex3f(a, -a, -a);

	glEnd();
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(b,d,-1);
    glRotatef(10,1,0,0);
	glBegin(GL_QUADS);
	
	// back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord3f(0.0,2.0,0.1); glVertex3f(a, a, -a);
	glTexCoord3f(4.0,2.0,0.1); glVertex3f(a, -a, -a);
	glTexCoord3f(4.0,0.0,0.1); glVertex3f(-a, -a, -a);
	glTexCoord3f(0.0,0.0,0.1); glVertex3f(-a, a, -a);

	glEnd();
	glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void cube1(float a)
{
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,a,-a);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,-a,a);
        glEnd();
        glPopMatrix();

		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);	
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(a,-a,-a);
        glEnd();
        glPopMatrix();

		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-a,-a,a);
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,-a,-a);
        glEnd();
		glPopMatrix();


		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(-a,-a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,-a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(a,-a,-a);
        glEnd();

        glPopMatrix();



		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureTower);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,-a,-a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,-a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,a,-a);
        glEnd();

        glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void cube2(float a)
{
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,a,-a);
        glEnd();
        glPopMatrix();
		

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,-a,a);
        glEnd();
        glPopMatrix();

		
		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(a,-a,-a);
        glEnd();
        glPopMatrix();
		

		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-a,-a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(-a,a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,-a,-a);
        glEnd();
        glPopMatrix();


		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,-a,a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(-a,-a,a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,-a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(a,-a,-a);
        glEnd();

        glPopMatrix();


		glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(a,a,-a);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(a,-a,-a);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-a,-a,-a);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-a,a,-a);
        glEnd();

        glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


//Function to generate a tower
void tower ( float x, float y )
{
	glPushMatrix();
		glTranslatef(x,y,-1);
		glRotatef(90,1,0,0);
		cube1(40);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,30);
		glRotatef(90,1,0,0);
		cube1(30);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,50);
		glRotatef(90,1,0,0);
		cube1(20);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,70);
		glRotatef(90,1,0,0);
		cube1(15);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,90);
		glRotatef(90,1,0,0);
		cube1(10);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,100);
		glRotatef(90,1,0,0);
		cube1(5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,105);
		glRotatef(90,1,0,0);
		cube1(3);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x,y,107);
		glRotatef(90,1,0,0);
		cube1(1);
	glPopMatrix();
}


//Function that generates a Cone
void cone2(float r)
{
	float i,x,y;
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0,0,20);
	for(i=0;i<=361;i+=2)
	{
		x= r * cos(i*c);
		y= r * sin(i*c);
		glVertex3f(x,y,0);
	}
	glEnd();
}


//Function to draw the track
void track(float R1,float R2)
{
	float X,Y,Z;
	int y;
	glBegin(GL_QUAD_STRIP);
	for( y=0;y<=361;y+=1)
	{
		X=R1*cos(c*y);
		Y=R1*sin(c*y);
		Z=-0.5;
		glVertex3f(X,Y,Z);

		X=R2*cos(c*y);
		Y=R2*sin(c*y);
		Z=-0.5;
		glVertex3f(X,Y,Z);
	}
	glEnd();
}


// Function to draw the pavement
void pave(float R1,float R2)
{
	float X,Y,Z;
	int y;
	glBegin(GL_QUAD_STRIP);
	for( y=0;y<=361;y+=1)
	{
		X=R1*cos(c*y);
		Y=R1*sin(c*y);
		Z=-0.5;
		glVertex3f(X,Y,Z);

		X=R2*cos(c*y);
		Y=R2*sin(c*y);
		Z=-0.5;
		glVertex3f(X,Y,Z);
	}
	glEnd();

}


//Function that generates a cylinder
void cylinder(float r,float l)
{
	float x,y,z; int d;
	glBegin(GL_QUAD_STRIP);
	for( d=0;d<=362;d+=1)
	{
		x=r*cos(c*d);
		z=r*sin(c*d);
		y=0;
		glVertex3f(x,y,z);

		y=l;
		glVertex3f(x,y,z);
	}
	glEnd();
}


// Function to draw the Hut
void hut(float a,float b)
{
	glColor3f(0.7,0.2,0.4);
	glPushMatrix();
		glTranslatef(a,b,-1);
		glRotatef(90,1,0,0);
		cylinder(15,40);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(a,b,35);
		cone2(25);
	glPopMatrix();
}


// Function that generates a Tree
void tree(float a,float b)
{	//Tree trunk
	glColor3f(0.9,0.3,0);
	glPushMatrix();
		glTranslatef(a,b,-1);
		glRotatef(90,1,0,0);
		cylinder(3,15);
	glPopMatrix();

	//Cone shaped tree top
	glPushMatrix();
		glTranslatef(a,b,8);
		cone();
	glPopMatrix();

}

// Tree2
void tree2(float a,float b)
{
	//Tree trunk
	glColor3f(1,0.2,0);
	glPushMatrix();
		glTranslatef(a,b,-1);
		glRotatef(90,1,0,0);
		cylinder(6,25);
	glPopMatrix();

	//Sphere shaped tree top
	glColor3f(0,0.4,0);
	glPushMatrix();
		glTranslatef(a,b,45);
		glutSolidSphere(30,10,10);
	glPopMatrix();
}

//Tree 3
void tree3(float a,float b)
{
	//Tree trunk
	glColor3f(1,0.2,0);
	glPushMatrix();
		glTranslatef(a,b,-1);
		glRotatef(90,1,0,0);
		cylinder(2,15);
	glPopMatrix();

	//Sphere shaped tree top
	glColor3f(0.2,1,0.2);
	glPushMatrix();
		glTranslatef(a,b,20);
		glutSolidSphere(10,7,7);
	glPopMatrix();
}


//Function to draw a circle
void circle(float R)
{
	float X,Y,Z;int i;

	glBegin(GL_POLYGON);
	for(i=0;i<=360;i++)
	{
		X=R*cos(c*i);
		Z=R*sin(c*i);
		Y=0;
		glVertex3f(X,Y,Z);
	}
	glEnd();
}


//Function to draw a quadrilateral
void rect(float p[],float q[],float r[],float s[])
{
	glBegin(GL_POLYGON);
		glVertex3fv(p);
		glVertex3fv(q);
		glVertex3fv(r);
		glVertex3fv(s);
	glEnd();
}


//Function to draw a man
void man()
{
glColor3f(0.8,0.4,0.2);

	//Legs
	glPushMatrix();
		glTranslatef(3,-3.5,1.5);
		glRotatef(270,1,0,0);
		cylinder(0.4,3);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3,-6.5,1.5);
		glRotatef(270,1,0,0);
		cylinder(0.4,3);
	glPopMatrix();

	//Hands
	glPushMatrix();
		glTranslatef(3,-3.5,2.5);
		glRotatef(90,0,0,-1);
		cylinder(0.4,3);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3,-6.5,2.5);
		glRotatef(90,0,0,-1);
		cylinder(0.4,3);
	glPopMatrix();
glColor3f(0.5,0.2,0.8);

	//Head
	glPushMatrix();
		glTranslatef(3,-5,4);
		glutSolidSphere (1.0, 20, 16);
	glPopMatrix();

	//Body
	glPushMatrix();
		glTranslatef(3,-5,1);
		glRotatef(90,1,0,0);
		cylinder(1,2);
	glPopMatrix();
 }

 
// Function to draw to House
void house(float a,float b)
{
    glPushMatrix();
    glTranslatef(a,b,-1);
    glRotatef(90,1,0,0);
    cylinder(15,40);
    cube2(40.0);
    glPopMatrix();
}


//House-top
void housetop1(float a,float b)
{

    glPushMatrix();
    glTranslatef(a-20,b-20,41);
    glRotatef(90,1,0,0);
    cube2(15);
    glPopMatrix();
}


//Function generating scenery using functions track( ),tree( ),tree2( )
void scenery()
{
	float x,y; int p;
	//Background
	glColor3f(0.4,0.9,0.9);
	glPushMatrix();
		glRotatef(90,1,0,0);
		cylinder(1000,1000);
	glPopMatrix();

	//Ground
	glColor3f(0.7,0.7,0.2);
	glPushMatrix();
	glTranslatef(0,0,-1.1);
	glRotatef(90,1,0,0);
		circle(1100);
	glPopMatrix();


	glEnable(GL_TEXTURE_2D);

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureGrass);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(1450,0,-1);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(0,1450,-1);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(-1450,0,-1);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(0,-1450,-1);
        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);


	// Tower
    for(p=150;p<=510;p+=60)
	{
	    glClearColor(0,0,0,0);
		x=900*cos(c*p);
		y=900*sin(c*p);
		tower(x,y);
    }

    //........
     for(p=150;p<=510;p+=60)
	{
	    glClearColor(0,0,0,0);
		x=400*cos(c*p);
		y=400*sin(c*p);
		tower(x,y);
	}

    //Track
    glColor3f(0.5,0.5,0.5);
	track(597,543);

	glColor3f(0.6,0.4,0.2);
	pave(600,597);
	glColor3f(0.6,0.4,0.2);
	pave(543,540);

    for(p=0;p<=360;p+=60)
	{
		x=800*cos(c*p);
		y=800*sin(c*p);
		house(x,y);
		housetop1(x,y);
    }

	//Cone shaped trees
	for(p=0;p<=360;p+=30)
	{
		x=700*cos(c*p);
		y=700*sin(c*p);
		tree(x,y);
    }

	//Sphere shaped trees
	for( p=100;p<=460;p+=30)
	{
		x=800*cos(c*p);
		y=800*sin(c*p);
		tree2(x,y);
	}

	for( p=100;p<=460;p+=30)
	{
		x=500*cos(c*p);
		y=500*sin(c*p);
		tree3(x,y);
	}
	for(p=0;p<=360;p+=30)
	{
		x=400*cos(c*p);
		y=400*sin(c*p);
		tree(x,y);
            }
}


//Function to draw triangles
void tri(float a[],float b[],float z[])
{
	glBegin(GL_TRIANGLES);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(z);
	glEnd();
}


//Function to start/stop the game on mouse right/left respectively 
void onMouseclick(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON)
        start=1;
    if(button==GLUT_RIGHT_BUTTON)
        start=0;

}


//Keyboard Callback Function
void keys(unsigned char key,int x,int y)
{
	KEY=key;
}


//Function  that generates a particular view of scene depending on view selected by //user
void view()
{
	float pos[]={1000,1000,2000,1};//Position of the light source

	switch(viewpoint)
	{

			case HELICOPTER:

			glLightfv(GL_LIGHT0, GL_POSITION, pos);
			gluLookAt(200,0,700,0,0,0,0,0,1);

			scenery();
			glPushMatrix();
				glTranslatef(carx,cary,0);
				glRotatef(angle*RAD_TO_DEG,0,0,-1);
				man();
			glPopMatrix();

			break;


			case SIDE:

			gluLookAt(-20.0,-20.0,15,0.0,0.0,2.0,0.0, 0.0,1.0);
            man();
			glPushMatrix();
				glRotatef(angle*RAD_TO_DEG, 0.0,0.0,1.0);
				glTranslatef(-carx,-cary,0);
				glLightfv(GL_LIGHT0, GL_POSITION, pos);
				scenery();
			glPopMatrix();

			break;

			case FRONT:

			gluLookAt(15.0,5.0,20,0.0,0.0,4.0,0.0,0.0,1.0);
			man();
			glPushMatrix();
				glRotatef(angle*RAD_TO_DEG, 0.0,0.0,1.0);
				glTranslatef(-carx,-cary,0);
				glLightfv(GL_LIGHT0, GL_POSITION, pos);
				scenery();
			glPopMatrix();

			break;

			case BACK:

			gluLookAt(-12.0,6.0,13,15.0,6.0,2.0,0.0,0.0,1.0);
            man();
			glPushMatrix();
				glRotatef(RAD_TO_DEG * angle, 0.0, 0.0, 1.0);
				glTranslatef(-carx,-cary,0);
				glLightfv(GL_LIGHT0, GL_POSITION, pos);
				scenery();
			glPopMatrix();

			break;

	}

}



int k=0;
//Idle Callback Function
void idle()
{

	if(start==1)
	{
		angle+=0.005+k;
		if(angle==TWO_PI)
		{
			angle-=TWO_PI;
		}

		carx=MID*sin(angle);
		cary=MID*cos(angle);

		switch(KEY)
		{
		case 'H':
		case 'h':viewpoint=HELICOPTER;break;

		case 'S':
		case 's':viewpoint=SIDE;break;

		case 'F':
		case 'f':viewpoint=FRONT;break;

		case 'B':
		case 'b':viewpoint=BACK;break;

		case 'U' :
        case 'u' :
            {
                k=k+0.005;
            }
        case 'J' :
        case 'j' :
            k=k-0.005;

		}
		glutPostRedisplay();
	}
}

GLuint loadTexture(Image* image) {

	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


//Initialization
void init()
{
	GLfloat amb[]={1,1,1,1},diff[]={1,1,1,1},spec[]={1,1,1,1};

	Image* image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\bricks.bmp");
	_textureBrick = loadTexture(image);
	image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\door.bmp");
	_textureDoor = loadTexture(image);
	image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\grass.bmp");
	_textureGrass = loadTexture(image);
	image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\roof.bmp");
	_textureRoof = loadTexture(image);
	image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\window.bmp");
	_textureTower = loadTexture(image);
	image = loadBMP("C:\\Users\\minkesh asati\\Documents\\study\\sem6\\Graphics\\opengl project\\sky.bmp");
	_textureSky = loadTexture(image);
	delete image;

    glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
    glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}


//Display Callback Function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	view();
	glutSwapBuffers();

}


//Reshape Function
void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(100, (GLfloat) w/(GLfloat) h, 1, 2000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


//Main Function
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

	printf("\t\t**********RUNNING MAN ON A TRACK***********\n");
	printf("\n\tPRESS OR CLICK\n");
	printf("\n\tClick Left Mouse Button:To Start or Continue\n");
	printf("\n\tClick Right Mouse Button:To Stop\n");
	printf("\n\tH or h :Helicopter View\n");
	printf("\n\tB or b :Back View\n");
	printf("\n\tS or s :Side View\n");
	printf("\n\tF or f :Front View\n");

	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Computer Graphics");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keys);
	glutMouseFunc(onMouseclick);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
