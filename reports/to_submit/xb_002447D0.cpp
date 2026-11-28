// bin: xb
// va: 0x002447D0
// what: Works out the offset in terms of the three axes (turned round on the axes the flags pick), then adds the point.
// tool: Claude Opus 5.5 (from the bytes)

// A three-number vector.
struct Vector3
{
    float x, y, z;
};

// Three axes with a point and an offset; which class this is part of is not known yet.
class Class_00244750
{
public:
    void sub_00244750(Vector3* out, unsigned char flags) const;
    void sub_002447D0(Vector3* out, unsigned char flags) const;

    Vector3 origin;         // +0x00
    Vector3 axis[3];        // +0x0C, +0x18, +0x24
    Vector3 offset;         // +0x30
};

void Class_00244750::sub_00244750(Vector3* out, unsigned char flags) const
{
    float x = offset.x;
    float y, z;
    if (flags & 4)
    {
        x = -x;
        y = -offset.y;
        z = -offset.z;
    }
    else
    {
        y = offset.y;
        z = offset.z;
    }
    if (flags & 2)
        y = -y;
    if (flags & 1)
        z = -z;
    out->x = x * axis[0].x + y * axis[1].x + z * axis[2].x;
    out->y = x * axis[0].y + y * axis[1].y + z * axis[2].y;
    out->z = x * axis[0].z + y * axis[1].z + z * axis[2].z;
}

void Class_00244750::sub_002447D0(Vector3* out, unsigned char flags) const
{
    sub_00244750(out, flags);
    out->x += origin.x;
    out->y += origin.y;
    out->z += origin.z;
}
