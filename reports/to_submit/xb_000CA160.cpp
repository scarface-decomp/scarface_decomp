// bin: xb
// va: 0x000CA160
// what: Builds an object from two three-number vectors, such as the two ends of a line.
// tool: Claude Opus 5.5 (symcov hint: Photon::CLineSegment::CLineSegment)
// sub_000CA160 (0x000CA160, 52 bytes)

struct Struct_000CA160
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_000CA160
{
public:
    Class_000CA160 *sub_000CA160(const Struct_000CA160 &first, const Struct_000CA160 &second);

    Struct_000CA160 m_Field00; // +0x00
    Struct_000CA160 m_Field0C; // +0x0C
};

// Copies both vectors in and returns the object.
Class_000CA160 *Class_000CA160::sub_000CA160(const Struct_000CA160 &first, const Struct_000CA160 &second)
{
    m_Field00 = first;
    m_Field0C = second;
    return this;
}
