// bin: xb
// va: 0x00244250
// what: Rotates this vector by a matrix's rotation part (no translation).
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
    void Rotate(const Matrix& matrix);
    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:
    void sub_00243740(const Vector3& in, Vector3& out) const;    // rotates a direction (0x243740)
    float m[4][4];
};

void Vector3::Rotate(const Matrix& matrix)
{
    Vector3 result;
    matrix.sub_00243740(*this, result);
    *this = result;
}
