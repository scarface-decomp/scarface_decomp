// bin: xb
// va: 0x002442A0
// what: Says whether this vector equals another to within the tolerance in each of x, y and z.
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
    bool sub_002442A0(const Vector3& other, float tolerance) const;
    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:

    float m[4][4];
};

// A float's magnitude, by clearing its sign bit.
__forceinline float Magnitude(float value)
{
    *(unsigned int*)&value &= 0x7FFFFFFF;
    return value;
}

bool Vector3::sub_002442A0(const Vector3& other, float tolerance) const
{
    return Magnitude(x - other.x) <= tolerance && Magnitude(y - other.y) <= tolerance && Magnitude(z - other.z) <= tolerance;
}
