// bin: xb
// va: 0x00063160
// what: Calls sub_00061810(a1) if the argument is non-null, otherwise returns -1.
// tool: Gemini 4 Neon

extern "C" int __cdecl sub_00061810(void* arg);

int __cdecl sub_00063160(void* arg)
{
    int result = -1;
    if (arg) {
        result = sub_00061810(arg);
    }
    return result;
}
