// bin: xb
// va: 0x000EF290
// tool: the portal's starter code (no AI)
// sub_000EF290 (0x000EF290, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000CA1C0();
};

class Class_000EF290
{
public:
    int sub_000EF290();
};

int Class_000EF290::sub_000EF290()
{
    return !((Object*)(int)this + 348)->sub_000CA1C0();
}
