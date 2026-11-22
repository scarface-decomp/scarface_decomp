// bin: xb
// va: 0x0020F5B0
// what: Looks up an object by name, keeps it in the holder and hands back a pointer into it; says whether it was found.
// tool: Claude Opus 5.5 (transplanted from xb:0x00200EA0, nearest by portal/tools/similar.py)
struct Holder
{
    void* object;
    void sub_00098B90(void* object);
};

extern "C" char DAT_004195CC[];
extern "C" char DAT_00441624[];
extern "C" void* __cdecl sub_0002AC90(void* object);
extern "C" void* __cdecl sub_0002B770(const char* name, int flags);
extern "C" void* __cdecl sub_002FC034(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x24 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_0020F5B0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_0002B770(name, 0);
        holder->sub_00098B90(sub_002FC034(object, 0, DAT_004195CC, DAT_00441624, 0));
        sub_0002AC90(holder->object);
        if (sub_0002AC90(holder->object)) {
            *out = (char*)sub_0002AC90(holder->object) + 0x24;
            found = true;
        }
    }
    return found;
}