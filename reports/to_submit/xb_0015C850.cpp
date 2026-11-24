// bin: xb
// va: 0x0015C850
// what: Script command GenericCharacterCamera::RecenterCamera; calls sub_001546E0 if the camera pointer is non-null.
// tool: Gemini 4 Neon

struct GenericCharacterCamera
{
    void sub_001546E0();
};

void __cdecl sub_0015C850(GenericCharacterCamera* camera)
{
    if (camera) {
        camera->sub_001546E0();
    }
}
