// bin: xb
// va: 0x000A6D10
// tool: the portal's starter code (no AI)
// sub_000A6D10 (0x000A6D10, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039DD50;

class Class_000A6D10
{
public:
    float sub_000A6D10(int a1, int a2);
};

float Class_000A6D10::sub_000A6D10(int a1, int a2)
{
    unsigned char t1;

    t1 = *(unsigned char*)((a1 << 4) + a2 + a1 + (int)this + 360);
    a1 = *(unsigned char*)((a1 << 4) + a2 + a1 + (int)this + 360);
    return ((float)a1) * DAT_0039DD50;
}
