Visual Studio 2015 Project for a sample OpenGL app that shows you how to use the gluLookAt function to simulate a camera point of view in OpenGL. 

You would mainly have to know the location (x, y, z) of the camera\eye, the location (x, y, z) of the point to look at, and the coordinates (x, y, z) of the Up vector (rotation of the camera around its origin). 

The parameters that are going to be passed to <em>gluLookAt </em>will vary based on the view:

<img title="Camera Views Table" src="http://alibad.files.wordpress.com/2010/05/cameraviewstable.png" alt="" width="510" height="283" />

The program looks as follows.

<img title="OpenGL Camera Views" src="http://alibad.files.wordpress.com/2010/05/cameraviews.png" alt="" width="510" height="365" />

More details: 

* [OpenGL Free GLUT in Visual C++ 2015](http://open-gl.com/2015/10/08/opengl-freeglut-in-visual-studio-2015/)
* [OpenGL Camera](http://open-gl.com/2010/05/28/glcamera/)
