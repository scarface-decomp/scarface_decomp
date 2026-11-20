// bin: xb
// va: 0x000643F0
// what: Passes the same value to two other functions, one after the other.
// tool: Claude Opus 5.5 (symcov hint: DF_vDrawLayers, link-order)
// sub_000643F0 (0x000643F0, 22 bytes)

extern "C" void __cdecl sub_00064240(int);
extern "C" void __cdecl sub_00061760(int);

// Calls the two functions with the same argument.
void __cdecl sub_000643F0(int a1)
{
    sub_00064240(a1);
    sub_00061760(a1);
}
