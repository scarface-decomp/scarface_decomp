// bin: xb
// va: 0x00243740
// what: Rotates a direction by the matrix's rotation part (no translation) into another vector.
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
    void TransformDirection(const Vector3& in, Vector3& out) const;
    float m[4][4];
};

void Matrix::TransformDirection(const Vector3& in, Vector3& out) const
{
    float x = in.x * m[0][0] + in.y * m[1][0] + in.z * m[2][0];
    float y = in.x * m[0][1] + in.y * m[1][1] + in.z * m[2][1];
    float z = in.x * m[0][2] + in.y * m[1][2] + in.z * m[2][2];
    out.x = x;
    out.y = y;
    out.z = z;
}
