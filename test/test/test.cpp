#include "stdafx.h"
// simplemouse.cpp
// by Glenn G. Chappell
// September 2003
//
// For CS 381
// Simple Mouse Demo
//
// Draws a red box at the mouse position
// whenever the left mouse button is down.

#include <iostream>
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <stdlib.h>  // Some versions of MS-Vis C++ have broken <cstdlib>
//using std::exit;
#include <GL/glut.h> // GLUT stuff, includes OpenGL headers as well
#include <vector>

using namespace std;

//point structure
typedef struct{
	int x;
	int y;
} point;

vector<point> line;


// Global variables
// Window/viewport
const int startwinsize = 400; // Starting window width & height, in pixels
int winw, winh;               // Window width & height, in pixels, saved by reshape



// Mouse
bool mouseleftdown = false;   // True if mouse LEFT button is down.
                              // Saved by mouse.
int mousex, mousey;           // Mouse x,y coords, in GLUT format (pixels from upper-left corner).
                              // Only guaranteed to be valid if a mouse button is down.
                              // Saved by mouse, motion.

// Keyboard
const int ESCKEY = 27;        // ASCII value of escape character

// Other
const double pointsize = 4;  // Size of point


// printbitmap
// Prints the given string at the given raster position
//  using GLUT bitmap fonts.
// You probably don't want any rotations in the model/view
//  transformation when calling this function.
void printbitmap(const string msg, double x, double y)
{
   glRasterPos2d(x, y);
   for (string::const_iterator ii = msg.begin();
        ii != msg.end();
        ++ii)
   {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);
   }
}


// display
// The GLUT display function
void display()
{
   //glClear(GL_COLOR_BUFFER_BIT);

   
   if (mouseleftdown)
   {
      // Convert mouse position to OpenGL's coordinate system
      //double oglx = double(mousex)/winw;
      //double ogly = 1-double(mousey)/winh;

      // Draw the box
      glColor3d(0.0, 1.0, 0.1);
      glPointSize(pointsize);
	  glBegin(GL_LINE_STRIP);
	  for(int i=0;i<line.size();++i) {
		  double oglx=double(line[i].x)/winw;
		  double ogly=1-double(line[i].y)/winh;
		  glVertex2d(oglx,ogly);
	  }
      glEnd();
   }

   glutSwapBuffers();
}


// mouse
// The GLUT mouse function
void mouse(int button, int state, int x, int y)
{
	// Save the mouse position
   /*mousex = x;
   mousey = y;*/

	point p;
	p.x=x;
	p.y=y;
	line.push_back(p);


   // Save the left button state
   if (button == GLUT_LEFT_BUTTON)
   {
      mouseleftdown = (state == GLUT_DOWN);
      glutPostRedisplay();  // Left button has changed; redisplay!
   }

   
}


// motion
// The GLUT motion function
void motion(int x, int y)
{
	point p;
	p.x=x;
	p.y=y;
	line.push_back(p);
   // We only do anything if the left button is down
   if (mouseleftdown)
      glutPostRedisplay();

   // Save the mouse position
   mousex = x;
   mousey = y;
}


// idle
// The GLUT idle function
void idle()
{
   // Print OpenGL errors, if there are any (for debugging)
   if (GLenum err = glGetError())
   {
      cerr << "OpenGL ERROR: " << gluErrorString(err) << endl;
   }
}


// keyboard
// The GLUT keyboard function
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case ESCKEY:  // ESC: Quit
      exit(0);
      break;
   }
}


// reshape
// The GLUT reshape function
void reshape(int w, int h)
{
   // Set the viewport to be the entire drawing area of the window
   glViewport(0, 0, w, h);

   // Save the window size
   winw = w;
   winh = h;

   // Set up the projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 1.0, 0.0, 1.0);

   glMatrixMode(GL_MODELVIEW);  // Always go back to model/view mode
}


// init
// Initializes GL states
// Called by main after window creation
void init()
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
}


int main(int argc, char ** argv)
{
   // Initialize OpenGL/GLUT
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

   // Make a window
   glutInitWindowSize(startwinsize, startwinsize);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("CS 381 - Simple Mouse Demo");

   // Initialize GL states & register callbacks
   init();
   glutDisplayFunc(display);
   glutIdleFunc(idle);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);

   // Do something
   glutMainLoop();

   return 0;
}

