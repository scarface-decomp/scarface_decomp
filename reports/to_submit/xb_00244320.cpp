// bin: xb
// va: 0x00244320
// what: Says whether all three of the vector's numbers are nearer zero than a small fixed tolerance.
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
    bool sub_00244320() const;
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

bool Vector3::sub_00244320() const
{
    return Magnitude(x) < 0.00001f && Magnitude(y) < 0.00001f && Magnitude(z) < 0.00001f;
}
