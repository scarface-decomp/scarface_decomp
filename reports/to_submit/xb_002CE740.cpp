// bin: xb
// va: 0x002CE740
// what: Says whether two values differ, by asking the comparison that says whether they are equal.
// tool: Claude Opus 5.5 (symcov hint: EAStringC::operator!=)
// sub_002CE740 (0x002CE740, 18 bytes)

class Class_002CE660
{
public:
    bool sub_002CE660(const Class_002CE660 &other) const;
    bool sub_002CE740(const Class_002CE660 &other) const;
};

// The opposite of the equality test.
bool Class_002CE660::sub_002CE740(const Class_002CE660 &other) const
{
    return !sub_002CE660(other);
}
