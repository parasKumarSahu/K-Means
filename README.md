# K-Means
C program to find clusters in a gray-scale pgm image using K-means algorithm and generate images containing different clusters. Library function used only for reading and writing images.

Instructions to compile: 

gcc ComputeKMeans.c -o p

Run: 

./p InputImage.pgm 3 OutputFileName

Output: 
3 pgm images OutputFileName1.pgm, OutputFileName2.pgm and OutputFileName3.pgm containg 3 major clusters of the input pgm image.
Similarly any number of cluster images can be formed by changing 3 with other numbers.
