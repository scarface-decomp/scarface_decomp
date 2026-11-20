// bin: xb
// va: 0x000B8790
// what: Says whether the first record's first float value (its X) is smaller than the second's, an ordering used for sorting.
// tool: Claude Opus 5.5

// A record whose first member is a float position; the rest of it is not known yet.
struct Class_000B8790
{
    float m_Field00;
};

// Orders records by their leading float.
bool sub_000B8790(const Class_000B8790 &left, const Class_000B8790 &right)
{
    return left.m_Field00 < right.m_Field00;
}
