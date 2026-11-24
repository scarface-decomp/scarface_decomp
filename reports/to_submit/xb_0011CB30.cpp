// bin: xb
// va: 0x0011CB30
// what: Calls sub_00113030 on the argument object and forwards its result to sub_0009A220.
// tool: Gemini 4 Neon

struct Object_0011CB30
{
    int sub_00113030();
};

extern "C" void __cdecl sub_0009A220(int);

void __cdecl sub_0011CB30(Object_0011CB30* obj)
{
    sub_0009A220(obj->sub_00113030());
}
