// bin: xb
// va: 0x00283FE0
// what: Passes its four arguments, the last a 64-bit number, unchanged to another function.
// tool: Claude Opus 5.5 (symcov hint: File_ReadAsyncEx)
// sub_00283FE0 (0x00283FE0, 34 bytes)

extern "C" int __cdecl sub_00283F50(int a1, int a2, int a3, __int64 a4);

// Forwards all four arguments. MSVC 7.1 does not turn the call into a jump because of the 64-bit argument.
int __cdecl sub_00283FE0(int a1, int a2, int a3, __int64 a4)
{
    return sub_00283F50(a1, a2, a3, a4);
}
