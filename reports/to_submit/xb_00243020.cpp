// bin: xb
// va: 0x00243020
// what: Sets the rotation part of the matrix from three angles, about x, y and z (one of the two orders it has).
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
    void SetRotationFromAngles(float x, float y, float z);
    float m[4][4];
};

void Matrix::SetRotationFromAngles(float x, float y, float z)
{
    float sx = (float)sin(x);
    float cx = (float)cos(x);
    float sy = (float)sin(y);
    float cy = (float)cos(y);
    float sz = (float)sin(z);
    float cz = (float)cos(z);
    float cxcz = cx * cz;
    float sxsz = sx * sz;
    float sxcz = sx * cz;
    float cxsz = cx * sz;
    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[1][0] = sxcz * sy - cxsz;
    m[1][1] = sxsz * sy + cxcz;
    m[1][2] = sx * cy;
    m[2][0] = cxcz * sy + sxsz;
    m[2][1] = cxsz * sy - sxcz;
    m[2][2] = cx * cy;
}
