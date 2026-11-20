// bin: xb
// va: 0x002D37E0
// what: Passes a value stored inside the given record, with an index, on to another function and returns its result.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_002D37E0 (0x002D37E0, 16 bytes)

struct Struct_002D37E0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" int __cdecl sub_002DF470(int handle, int);

// Calls the function with the record's value at +0x08 in place of the record.
int __cdecl sub_002D37E0(Struct_002D37E0 *record, int index)
{
    return sub_002DF470(record->m_Field08, index);
}
