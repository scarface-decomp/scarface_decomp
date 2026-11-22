// bin: proto
// va: 0x001D4B20
// what: Looks up an object by name, keeps it in the holder and hands back a pointer into it; says whether it was found.
// tool: Claude Opus 5.5 (transplanted from xb:0x00200EA0, nearest by portal/tools/similar.py)
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_004251D4[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x24 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4B20(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_004251D4, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x24;
            found = true;
        }
    }
    return found;
}