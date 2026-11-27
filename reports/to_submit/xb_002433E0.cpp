// bin: xb
// va: 0x002433E0
// what: Transposes the matrix: swaps each number above the diagonal with the one below it.
// tool: Claude (from the bytes)

extern "C" double __cdecl sin(double x);
extern "C" double __cdecl cos(double x);
extern "C" double __cdecl sqrt(double x);
#pragma intrinsic(sin, cos, sqrt)

class Matrix;

// A three-number vector.
class Vector3
{
public:

    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:
    void sub_002433E0();
    float m[4][4];
};

void Matrix::sub_002433E0()
{
    float t01 = m[0][1];
    float t02 = m[0][2];
    float t03 = m[0][3];
    float t12 = m[1][2];
    float t13 = m[1][3];
    float t23 = m[2][3];
    m[0][1] = m[1][0];
    m[0][2] = m[2][0];
    m[0][3] = m[3][0];
    m[1][0] = t01;
    m[1][2] = m[2][1];
    m[1][3] = m[3][1];
    m[2][0] = t02;
    m[2][1] = t12;
    m[2][3] = m[3][2];
    m[3][0] = t03;
    m[3][1] = t13;
    m[3][2] = t23;
}
