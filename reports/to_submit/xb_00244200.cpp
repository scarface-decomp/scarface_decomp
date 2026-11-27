// bin: xb
// va: 0x00244200
// what: Transforms this vector by a matrix as a point (rotation part and translation).
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
    void Transform(const Matrix& matrix);
    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:
    void sub_002435D0(const Vector3& in, Vector3& out) const;    // transforms a point (0x2435D0)
    float m[4][4];
};

void Vector3::Transform(const Matrix& matrix)
{
    Vector3 result;
    matrix.sub_002435D0(*this, result);
    *this = result;
}
