// bin: xb
// va: 0x00243B30
// what: Sets the matrix to the product of two matrices (computed into a copy, so either may be this one).
// tool: Claude Opus 5.5 (from the bytes)

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
    void SetProduct(const Matrix& a, const Matrix& b);
    float m[4][4];
};

void Matrix::SetProduct(const Matrix& a, const Matrix& b)
{
    Matrix t;
    int i = 4;
    while (i--)
    {
        int j = 4;
        while (j--)
        {
            float s = a.m[i][0] * b.m[0][j];
            s += a.m[i][1] * b.m[1][j];
            s += a.m[i][2] * b.m[2][j];
            s += a.m[i][3] * b.m[3][j];
            t.m[i][j] = s;
        }
    }
    *this = t;
}
