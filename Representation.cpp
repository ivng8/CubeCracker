#include <iostream>
#include <array>
#include <strings>
#include Colors.h

// Represents the entire cube
// 0: Front, 1: Top, 2: Back, 3: Right, 4: Left, 5: Bottom
class Representation {
private:
    FaceMatrix cube[6];

public:
    // Constructure for Representation
    Representation() {
        cube[0] = FaceMatrix(Colors.GREEN);
        cube[1] = FaceMatrix(Colors.YELLOW);
        cube[2] = FaceMatrix(Colors.BLUE);
        cube[3] = FaceMatrix(Colors.ORANGE);
        cube[4] = FaceMatrix(Colors.RED);
        cube[5] = FaceMatrix(Colors.WHITE);
    }

    // 0 -> 1    1 -> 2    2 -> 5    5 -> 0
    // rotates right face clockwise Green -> Yellow -> Blue -> White -> Green
    void r() {
        Colors saved[3] = cube[1].getLine("col", 3).reverse();
        Colors input[3] = cube[0].getLine("col", 3);
        cube[1].switchColors(input, false, 3);
        input = saved;
        saved = cube[2].getLine("col", 1).reverse();
        cube[2].switchColors(input, false, 1);
        input = saved;
        saved = cube[5].getLine("col", 1);
        cube[5].switchColors(input, false, 1);
        cube[0].switchColors(saved, false, 3);
    }

    // 0 -> 5    5 -> 2    2 -> 1    1 -> 0
    // rotates left face clockwise Green -> White -> Blue -> Yellow -> Green
    void l() {
        Colors saved[3] = cube[5].getLine("col", 3).reverse();
        Colors input[3] = cube[0].getLine("col", 1);
        cube[5].switchColors(input, false, 3);
        input = saved;
        saved = cube[2].getLine("col", 3).reverse();
        cube[2].switchColors(input, false, 3);
        input = saved;
        saved = cube[1].getLine("col", 1);
        cube[1].switchColors(input, false, 1);
        cube[0].switchColors(saved, false, 1);
    }

    // 1 -> 4    4 -> 5    5 -> 3    3 -> 1
    // rotates back face clockwise Yellow -> Red -> White -> Orange -> Yellow
    void b() {
        Colors saved[3] = cube[4].getLine("col", 1).reverse();
        Colors input[3] = cube[1].getLine("row", 1).reverse();
        cube[4].switchColors(input, false, 1);
        input = saved;
        saved = cube[5].getLine("row", 3);
        cube[5].switchColors(input, true, 3);
        input = saved;
        saved = cube[3].getLine("col", 3);
        cube[3].switchColors(input, false, 1);
        cube[1].switchColors(saved, true, 1);
    }

    // 1 -> 3    3 -> 5    5 -> 4    4 -> 1
    // rotates front face clockwise Yellow -> Orange -> White -> Red -> Yellow
    void f() {
        Colors saved[3] = cube[3].getLine("col", 1);
        Colors input[3] = cube[1].getLine("row", 3);
        cube[3].switchColors(input, false, 1);
        input = saved;
        saved = cube[5].getLine("row", 1).reverse();
        cube[5].switchColors(input, true, 1);
        input = saved;
        saved = cube[4].getLine("col", 3).reverse();
        cube[4].switchColors(input, false, 3);
        cube[1].switchColors(saved, true, 3);
    }

    // 0 -> 4    4 -> 2    2 -> 3    3 -> 0
    // rotates up face clockwise Green -> Red -> Blue -> Orange -> Green
    void u() {
        Colors saved[3] = cube[4].getLine("row", 1);
        Colors input[3] = cube[0].getLine("row", 1);
        cube[4].switchColors(input, true, 1);
        input = saved;
        saved = cube[2].getLine("row", 1);
        cube[2].switchColors(input, true, 1);
        input = saved;
        saved = cube[3].getLine("row", 1);
        cube[3].switchColors(input, true, 1);
        cube[0].switchColors(saved, true, 1);
    }

    // 0 -> 3    3 -> 2    2 -> 4    4 -> 0
    // rotates down face clockwise Green -> Orange -> Blue -> Red -> Green
    void d() {
        Colors saved[3] = cube[3].getLine("row", 3);
        Colors input[3] = cube[0].getLine("row", 3);
        cube[3].switchColors(input, true, 3);
        input = saved;
        saved = cube[2].getLine("row", 3);
        cube[2].switchColors(input, true, 3);
        input = saved;
        saved = cube[4].getLine("row", 3);
        cube[4].switchColors(input, true, 3);
        cube[0].switchColors(saved, true, 3);
    }

    void rc() {
        r();
        r();
        r();
    }

    void lc() {
        l();
        l();
        l();
    }

    void dc() {
        d();
        d();
        d();
    }

    void fc() {
        f();
        f();
        f();
    }

    void uc() {
        u();
        u();
        u();
    }

    void bc() {
        b();
        b();
        b();
    }

    bool isCubeSolved() {
        for (int i = 0; i < 6; i++) {
            if (!(cube[i].isFaceSolved)) {
                return false;
            }
        }
        return true;
    }

    string godsNumber(string acc) {
        if (isCubeSolved()) {
            return acc;
        } else {
            string combos[12];
            r();
            combos[0] = godsNumber("r ");
            rc();
            l();
            combos[1] = godsNumber("l ");
            lc();
            u();
            combos[2] = godsNumber("u ");
            uc();
            d();
            combos[3] = godsNumber("d ");
            dc();
            f();
            combos[4] = godsNumber("f ");
            fc();
            b();
            combos[5] = godsNumber("b ");
            bc();
            rc();
            combos[6] = godsNumber("R ");
            r();
            lc();
            combos[7] = godsNumber("L ");
            l();
            uc();
            combos[8] = godsNumber("U ");
            u();
            dc();
            combos[9] = godsNumber("D ");
            d();
            bc();
            combos[10] = godsNumber("B ");
            b();
            fc();
            combos[11] = godsNumber("F ");
            f();
            string ans = combos[0];
            for (int i = 1; i < 12; i++) {
                if (ans.length() > combos[i].length()) {
                    ans = combos[i];
                }
            }
            return ans;
        }
    }
}