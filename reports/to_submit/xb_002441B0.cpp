// bin: xb
// va: 0x002441B0
// what: Makes this vector the given vector scaled to length one.
// tool: Claude (from the bytes)

extern "C" double __cdecl sin(double x);
extern "C" double __cdecl cos(double x);
extern "C" double __cdecl sqrt(double x);
#pragma intrinsic(sin, cos, sqrt)

// A three-number vector.
class Vector3
{
public:
    void SetNormalised(const Vector3& v);
    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:

    float m[4][4];
};

void Vector3::SetNormalised(const Vector3& v)
{
    float scale = 1.0f / (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    x = scale * v.x;
    y = scale * v.y;
    z = scale * v.z;
}
