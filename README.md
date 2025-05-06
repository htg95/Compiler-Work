BENCHMARK PROFILING:
(i)	ssymm
	Goal: The goal of this benchmark is to perform symmetric matrix multiplication. A symmetric matrix is a square matrix which is equivalent to its transpose. The elements are symmetric to the diagonal of the matrix.
	Non-tiled algorithm: A and B are symmetric matrices being multiplied. The algorithm is a direct implementation of the matrix multiply algorithm with a complexity of n3.
	Tiled algorithm: The three outer loops setup the boundaries of the polyhedral model in x,y and z direction respectively. The inner three loops design the tiled matrix multiply operation inside the polyhedron. It is imperative to note that size of each of these tiles is fixed according to the requirements in the software. 
	Advantages to normal matrix multiply: These are easy to convert to linear equations and therefore, are faster to multiply than normal matrix multiply when tiled.
(ii)	  matmul
	Goal: Here a normal matrix multiply between two matrices. 
	Non-tiled algorithm: A and B are symmetric matrices being multiplied. The algorithm is a direct implementation of the matrix multiply algorithm with a complexity of n3.
	Tiled algorithm: The three outer loops setup the boundaries of the polyhedral model in x,y and z direction respectively. The inner three loops design the tiled matrix multiply operation inside the polyhedron. It is imperative to note that size of each of these tiles is fixed according to the requirements in the software.
(iii)	lu: Explained in notes
(iv)	mvt
	Goal: Vectorising a matrix 
	Non-tiled algorithm: The matrix is made into row or a column major matrix in one pass. The complexity of such an algorithm in n2.
	Tiled algorithm: The two outer loops are the vector boundaries and inner two loops is the actual vectorization operation. As vector is a 1D array there are only x and y axis for the resulting polyhedron. The actual matrix is split into N/(no of software rows per matrix) to perform vectorization operation.
(v)	covcol
	Goal: Calculating matrix co-variance. Co-variance constructs a square matrix that gives the covariance between each pair of elements of a given random matrix or vector.
	Non-tiled algorithm: The initial transaction involves determining mean of the column vectors of a given input matrix. The next step is to center the column vectors to perform co-variance operation and finally, co-variance is found by mathematical operation. 
	Tiled algorithm: The tiling portion is in the co-variance calculation. Here the matrix is divided into upper and lower triangle polyhedron and each of the upper and lower triangle bounds are defined in the outer loops. The inner two loops is for calculating the co-variance matrix. The size of a tile is pre-defined as per software.

(vi)	dsyrk
	Goal: Normal matrix addition and multiplication operation.
	Non-tiled algorithm: Similar to matmul
	Tiled algorithm: Similar to matmul
