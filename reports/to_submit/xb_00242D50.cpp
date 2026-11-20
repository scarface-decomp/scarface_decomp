// bin: xb
// va: 0x00242D50
// what: Says whether this 4-byte record's unsigned key is smaller than another's; the sort at 0x0007F600 orders its records with it.
// tool: Claude Opus 5.5

// This part of the program was built with frame pointers.
#pragma optimize("y", off)

// A 4-byte record ordered by an unsigned key (sub_0007F3D0, the insertion sort under sub_0007F600, calls this).
class Class_0007F600
{
public:
    bool operator<(const Class_0007F600 &other) const;

    unsigned int m_Key;
};

bool Class_0007F600::operator<(const Class_0007F600 &other) const
{
    return m_Key < other.m_Key;
}
