// bin: xb
// va: 0x002D37C0
// what: Passes a value stored inside the given record, with two more arguments, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceDiff)
// sub_002D37C0 (0x002D37C0, 16 bytes)

struct Struct_002D37C0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" void __cdecl sub_002DF3C0(int handle, int, int);

// Calls the function with the record's value at +0x08 in place of the record.
void __cdecl sub_002D37C0(Struct_002D37C0 *record, int a2, int a3)
{
    sub_002DF3C0(record->m_Field08, a2, a3);
}
