// bin: xb
// va: 0x00242FA0
// what: Sets the matrix's rotation part to a rotation about the y axis by the angle (radians); the rest is left alone.
// tool: Claude (from the bytes)

extern "C" double __cdecl sin(double x);
extern "C" double __cdecl cos(double x);
extern "C" double __cdecl sqrt(double x);
#pragma intrinsic(sin, cos, sqrt)

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
    void SetRotationAboutY(float angle);
    float m[4][4];
};

void Matrix::SetRotationAboutY(float angle)
{
    float s = (float)sin(angle);
    float c = (float)cos(angle);
    m[0][0] = c;
    m[0][1] = 0.0f;
    m[0][2] = -s;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[2][0] = s;
    m[2][1] = 0.0f;
    m[2][2] = c;
}
