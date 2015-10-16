Code for http://mycodelog.com/2010/05/21/array3d/

<h3>Java 3D Array</h3>
In Java, creating a 3-dimensional array is as simple as saying: int[][][] array3D = new int[x][y][z]; 

You can then access the elements of the 3-dimensional array at array3D[i][j][k].

<h3>C# 3D Array</h3>
In C#, the concept is almost the same as in Java. However, C# makes the distinction between jagged and multi-dimensional arrays. Elements of a multi-dimensional array are stored in a contiguous block in memory while elements of a jagged array are not. Java arrays are actually jagged arrays, while C# supports both and allows you to choose which one you want based on the syntax of your code. Note that multi-dimensional arrays are better (in most cases) than jagged arrays, and that is considered a minus point for Java.

<h3>C++ 3D Array</h3>
To create a multi-dimensional array in C++, we should change perspective a little bit and think of creating arrays that point to other arrays, which point to other arrays, and so on. For example, to create a 2x3x4 array in C++, we should imagine the implementation as follows:

<img class="alignnone size-full wp-image-505" title="Jagged 3D Array - C++" src="http://alibad.files.wordpress.com/2010/05/array3d-jagged.jpg" alt="" width="369" height="590" />

<h3>C 3D Array</h3>
Implementing multi-dimensional arrays in C is very similar to C++, except that we use <em>malloc</em>()\<em>free</em>()  <em>stdlib </em>methods instead of the <em>new</em>\<em>delete </em>keywords. The memory representation below is the same, but we are going to focus in this section on making the elements of the 3 dimensional array contiguous.

<img  title="3 Dimensional Array - Non-Jagged" src="http://alibad.files.wordpress.com/2010/05/array3d-nonjagged.jpg" alt="" width="379" height="500" />