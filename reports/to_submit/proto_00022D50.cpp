// bin: proto
// va: 0x00022D50
// what: 
// tool: the portal's starter code (no AI)

// sub_00022D50 (Proto 0x00022D50, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00429334;
extern "C" bool DAT_0043D700;
extern "C" bool DAT_0043D701;

void* __cdecl sub_00022D50(void)
{
    DAT_0043D700 = DAT_00429334;
    DAT_0043D701 = false;
    return &DAT_0043D700;
}
