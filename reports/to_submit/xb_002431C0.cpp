// bin: xb
// va: 0x002431C0
// what: Sets the matrix's rotation part to a uniform scale; the rest is left alone.
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
    void SetUniformScale(float scale);
    float m[4][4];
};

void Matrix::SetUniformScale(float scale)
{
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[0][0] = scale;
    m[1][1] = scale;
    m[2][2] = scale;
}
