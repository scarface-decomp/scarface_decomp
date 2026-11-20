// bin: xb
// va: 0x0002EAA0
// what: Says whether either of two global on/off flags is set.
// tool: Claude Opus 5.5 (symcov hint: GUI_ScoreCardUp)
// sub_0002EAA0 (0x0002EAA0, 27 bytes)

extern "C" bool DAT_0041C040;
extern "C" bool DAT_00474517;

// True when either flag is set.
bool __cdecl sub_0002EAA0()
{
    return DAT_00474517 || DAT_0041C040;
}
