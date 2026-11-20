// bin: xb
// va: 0x002D37B0
// what: Passes a value stored inside the given record, with two more arguments, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceDiff)
// sub_002D37B0 (0x002D37B0, 16 bytes)

struct Struct_002D37B0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" void __cdecl sub_002DF370(int handle, int, unsigned int);

// Calls the function with the record's value at +0x08 in place of the record.
void __cdecl sub_002D37B0(Struct_002D37B0 *record, int a2, unsigned int count)
{
    sub_002DF370(record->m_Field08, a2, count);
}
