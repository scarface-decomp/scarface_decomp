// bin: xb
// va: 0x00250E60
// what: Rounds a number down to a multiple of a step; a step of zero leaves it as it is.
// tool: Claude (from the bytes)

unsigned int __cdecl sub_00250E60(unsigned int value, unsigned int step)
{
    if (step != 0)
    {
        value = value / step * step;
    }
    return value;
}
