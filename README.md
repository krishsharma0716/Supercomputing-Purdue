# Supercomputing-Purdue Onboarding Docs & Notes 
  Writing a program to do something in C or C++
  Monte Carlo Approximation for PI
  Python script to run the program on different cores
  Slurm job submission
  Maybe? Navigating Dashboard, viewing files linux commands (cd ls etc)

# Understanding the Task
Start by making c++ file and header file. 
Define a square with a side length of 2, and inscribe a circle (or quadrant) of radius 1 inside it.
The area of the square is 4, and the area of the circle is \(\pi \). 
The ratio of their areas is \(\pi / 4\). 
Scatter thousands of random points (or "darts") uniformly across the square. 
Count the fraction of points that land inside the circle. Multiply that fraction by 4 to get an approximation of \(\pi \)

# Making Neccesary File
Main file, montecarlo code file (includes number of points to generate as input, will be explained later why in parallelization), header file (include explanation later when refining OB. 

#  Monte Carlo File: Setting Boundaries
The goal here is to define boundaries for our shapes to determine 2 things: The points we randomly generate are inside of our defined square, and the points we generate can be checked if they are in our circle. 

Let's begin by defining the system we will be working with: a square and circle

How do we do that in code? Lets think about it. When we draw a square on a grind paper, we always find the points of our corners we want and connect them using lines. Similarly, in code we define our shapes using their boundaries.
For a square this means making a 2d array with 4 rows and 2 coloumns for 4 corners and 2 axes (x and y)
Doing it this way allows us to define a max and min for our x and y which will be used for our random number generator later and completes our first goal: the points will be generated in the square

One goal left: Checking if our points are in our circle of radius 1. 
This is tricky since not well defined boundaries that we can just throw an if less than statement at. Our only boundary is our Radius which comes in handy here. 
Since our circle is inscribed inside our square and both are centered at (0,0) we can simply check the distance from the center of the circle to our point to be tested and check if that is less than our radius! 
Distance formula (For a distance D): sqrt((h-x)^2+(k-y)^2) = D 
Square both sides to remove the computationaly intensive square root --> (h-x)^2+(k-y)^2 = D^2
Since centered at 0,0, we can get rid of h and y and the negatives on the x and y since they are being squared: x^2 + y^2 = D^2 
Since D is our distance, we just have to check if x and y turn out to be less than R. So, plug in R for D to obtain
x^2 + y^2 <= D^2 

Nice, you just turned something in the physical world to the digital world. This is a core component in our club as we build projects tackling real world problems that may not translate cleanly into code. We have to leverage the math and science tools we have to make it possible. Don't be afraid if you don't know how to conjure this on the spot, that's the point of this club-- to teach and guide you how to tackle these problems. 




