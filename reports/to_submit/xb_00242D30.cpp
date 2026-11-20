// bin: xb
// va: 0x00242D30
// what: Says whether two 4-byte handles hold the same value (an equality operator).
// tool: Claude Opus 5.5

// This part of the program was built with frame pointers.
#pragma optimize("y", off)

// A 4-byte handle compared by value; what it refers to is not known yet.
class Class_00242D30
{
public:
    bool operator==(const Class_00242D30 &other) const;

    void *m_Field00;
};

bool Class_00242D30::operator==(const Class_00242D30 &other) const
{
    return m_Field00 == other.m_Field00;
}
