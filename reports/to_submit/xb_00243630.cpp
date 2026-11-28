// bin: xb
// va: 0x00243630
// what: Multiplies a four-number vector by the matrix and writes the result.
// tool: Claude Opus 5.5 (from the bytes, with the examiner's roles)

// A four-number vector.
struct Vector4
{
    float x, y, z, w;
};

// A 4x4 matrix stored by rows; row 3 is the translation.
class Matrix
{
public:
    void Transform(const Vector4& v, Vector4* out) const;
    float m[4][4];
};

void Matrix::Transform(const Vector4& v, Vector4* out) const
{
    float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0];
    float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1];
    float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2];
    float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3];
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
}
