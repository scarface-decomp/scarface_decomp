// bin: xb
// va: 0x002D37A0
// what: Passes a value stored inside the given record, with a number, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_002D37A0 (0x002D37A0, 16 bytes)

struct Struct_002D37A0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" int __cdecl sub_002DF360(int handle, float);

// Calls the function with the record's value at +0x08 in place of the record.
int __cdecl sub_002D37A0(Struct_002D37A0 *record, float value)
{
    return sub_002DF360(record->m_Field08, value);
}
