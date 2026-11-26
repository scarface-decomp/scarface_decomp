// bin: xb
// va: 0x00250E80
// what: Rounds a number up to a multiple of a step; a step of zero, or a number already on a multiple, leaves it as it is.
// tool: Claude (from the bytes)

unsigned int __cdecl sub_00250E80(unsigned int value, unsigned int step)
{
    if (step != 0)
    {
        unsigned int over = value % step;
        if (over != 0)
        {
            return value - over + step;
        }
    }
    return value;
}
