// bin: xb
// va: 0x002D37D0
// what: Passes a value stored inside the given record, with a number, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_002D37D0 (0x002D37D0, 16 bytes)

struct Struct_002D37D0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" void __cdecl sub_002DF450(int handle, float);

// Calls the function with the record's value at +0x08 in place of the record.
void __cdecl sub_002D37D0(Struct_002D37D0 *record, float value)
{
    sub_002DF450(record->m_Field08, value);
}
