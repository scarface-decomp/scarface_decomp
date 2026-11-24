// bin: xb
// va: 0x00178690
// what: Script command CharacterObject::GetCharacterTemplateName; returns the template name via sub_000CE360, or null.
// tool: Gemini 4 Neon

struct CharacterTemplate_00178690
{
    const char* sub_000CE360();
};

struct CharacterObject_00178690
{
    char m_pad00[0xB4];
    CharacterTemplate_00178690* m_Template; // +0xB4
};

const char* __cdecl sub_00178690(CharacterObject_00178690* character)
{
    if (character->m_Template) {
        return character->m_Template->sub_000CE360();
    }
    return 0;
}
