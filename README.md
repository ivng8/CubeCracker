# CubeCracker

CubeCracker is a C++ project aimed at generating a portrayal of a Rubik’s Cube using standard template libraries (STLs), while ensuring that the representation remains consistent regardless of turning. The project incorporates principles of group theory to make the data representation isomorphic to the structure of a cube and to ensure that transformations of the cube remain homomorphic, allowing for a bijective object design.

## Key Features

### Colors: An enum class defining the six colors of a Rubik’s Cube.
### Facematrix: A 3x3 matrix representing a face of the cube.
### Representation: A 6xfacematrix representing the entire cube.
### Algorithm: Implements a proof of God’s number by employing a dynamic programming and breadth-first search (BFS)-based algorithm. This algorithm outputs the minimum sequence of moves required to solve a cube from any configuration.
