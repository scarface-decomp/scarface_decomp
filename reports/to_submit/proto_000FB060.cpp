// bin: proto
// va: 0x000FB060
// what: 
// tool: the portal's starter code (no AI)

// sub_000FB060 (Proto 0x000FB060, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F9C10(int, float);
};

extern "C" int DAT_0045BC80;

class Class_000FB060
{
public:
    void sub_000FB060(float a1);
};

void Class_000FB060::sub_000FB060(float a1)
{
    ((Object*)DAT_0045BC80)->sub_000F9C10((int)this, a1 * a1);
}
