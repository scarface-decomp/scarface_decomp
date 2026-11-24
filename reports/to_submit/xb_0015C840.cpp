// bin: xb
// va: 0x0015C840
// what: Script command GenericCharacterCamera::ReleaseTarget; calls sub_002A9290 if the camera pointer is non-null.
// tool: Gemini 4 Neon

struct GenericCharacterCamera
{
    void sub_002A9290();
};

void __cdecl sub_0015C840(GenericCharacterCamera* camera)
{
    if (camera) {
        camera->sub_002A9290();
    }
}
