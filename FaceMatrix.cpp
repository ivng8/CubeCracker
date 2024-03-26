#include <iostream>
#include <array>
#include <string>
#include Colors.h

// Uses a 3x3 matrix to represent a face of the cube
class FaceMatrix {
private:
    static const int rows = 3;
    static const int cols = 3;
    Colors matrix[rows][cols];

public:
    // Constructor for a face
    // face: color of the face
    FaceMatrix(Colors face) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j += 1) {
                matrix[i][j] = face;
            }
        }
    }

    void switchColors(Colors from[], bool horiz, int index) {
        if (horiz) {
            for (int i = 0; i < 3; i++) {
                matrix[index][i] = from[index][i];
            }
        } else {
            for (int i = 0; i < 3; i++) {
                matrix[i][index] = from[index][i];
            }
        }
    }

    std::array<Color, 3> getLine(std::string direction, int index) {
        std::array<Color, 3> line;
        if (direction == "row") {
            for (int i = 0; i < 3; i++) {
                line[i] = matrix[index][i];
            }
        } else {
            for (int j = 0; j < 3; j++) {
                line[j] = matrix[j][index];
            }
        }
        return line;
    }

    bool isFaceSolved() {
        Color ans = matrix[1][1];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(matrix[i][j].equals(ans))) {
                    return false
                }
            }
        }
        return true;
    }
}