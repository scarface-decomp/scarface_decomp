// bin: xb
// va: 0x000C4360
// what: Says whether the first record's second float value (its Y) is smaller than the second's, an ordering used for sorting.
// tool: Claude Opus 5.5

// A record whose second member is a float position; the rest of it is not known yet.
struct Class_000C4360
{
    float m_Field00;
    float m_Field04;
};

// Orders records by their second float.
bool sub_000C4360(const Class_000C4360 &left, const Class_000C4360 &right)
{
    return left.m_Field04 < right.m_Field04;
}
