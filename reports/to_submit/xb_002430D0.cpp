// bin: xb
// va: 0x002430D0
// what: Sets the rotation part of the matrix from three angles, about x, y and z (the other of the two orders it has).
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
    void SetRotationFromAnglesOtherOrder(float x, float y, float z);
    float m[4][4];
};

void Matrix::SetRotationFromAnglesOtherOrder(float x, float y, float z)
{
    float sx = (float)sin(x);
    float cx = (float)cos(x);
    float sy = (float)sin(y);
    float cy = (float)cos(y);
    float sz = (float)sin(z);
    float cz = (float)cos(z);
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    float cycz = cy * cz;
    m[0][0] = sysz * sx + cycz;
    m[0][1] = cx * sz;
    m[0][2] = cysz * sx - sycz;
    m[1][0] = sycz * sx - cysz;
    m[1][1] = cx * cz;
    m[1][2] = cycz * sx + sysz;
    m[2][0] = cx * sy;
    m[2][1] = -sx;
    m[2][2] = cx * cy;
}
