// bin: xb
// va: 0x00242FE0
// what: Sets the matrix's rotation part to a rotation about the z axis by the angle (radians); the rest is left alone.
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
    void SetRotationAboutZ(float angle);
    float m[4][4];
};

void Matrix::SetRotationAboutZ(float angle)
{
    float s = (float)sin(angle);
    float c = (float)cos(angle);
    m[0][0] = c;
    m[0][1] = s;
    m[0][2] = 0.0f;
    m[1][0] = -s;
    m[1][1] = c;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
}
