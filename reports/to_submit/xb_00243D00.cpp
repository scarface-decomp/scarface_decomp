// bin: xb
// va: 0x00243D00
// what: Sets the matrix's rotation part to a rotation about the x axis built from the direction's y and z.
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

    float x, y, z;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:
    void SetRotationAboutXToward(const Vector3& direction);
    float m[4][4];
};

void Matrix::SetRotationAboutXToward(const Vector3& direction)
{
    float scale = 1.0f / (float)sqrt(direction.y * direction.y + direction.z * direction.z);
    float s = scale * direction.y;
    float c = scale * direction.z;
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = c;
    m[1][2] = -s;
    m[2][0] = 0.0f;
    m[2][1] = s;
    m[2][2] = c;
}
