// bin: xb
// va: 0x002436D0
// what: Transforms a four-number vector's x, y and z by the matrix as a point (w taken as one) and copies w.
// tool: Claude (from the bytes)

extern "C" double __cdecl sin(double x);
extern "C" double __cdecl cos(double x);
extern "C" double __cdecl sqrt(double x);
#pragma intrinsic(sin, cos, sqrt)

class Matrix;

// A four-number vector.
class Vector4
{
public:
    float x, y, z, w;
};


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
    void sub_002436D0(Vector4& in, Vector4& out) const;
    float m[4][4];
};

void Matrix::sub_002436D0(Vector4& in, Vector4& out) const
{
    float w = in.w;
    in.w = 1.0f;
    float x = in.x * m[0][0] + in.y * m[1][0] + in.z * m[2][0] + in.w * m[3][0];
    float y = in.x * m[0][1] + in.y * m[1][1] + in.z * m[2][1] + in.w * m[3][1];
    float z = in.x * m[0][2] + in.y * m[1][2] + in.z * m[2][2] + in.w * m[3][2];
    out.x = x;
    out.y = y;
    out.z = z;
    out.w = w;
    in.w = w;
}
