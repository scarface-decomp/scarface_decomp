// parked: 25/25 bytes only as a dummy-parameter __fastcall (R17, MATCH-PENDING); the honest static C body compiled with cl /GL and linked with link /LTCG gives 25/25 bytes with the value in edx (experiment 2026-11-19, work/ltcg/), so the wall is the per-file verifier's lack of an LTCG mode, not the source.
// bin: xb
// va: 0x00299510
// what: Counts how many of the 32 bits of a value are set.
// tool: Claude Opus 5.5

// The value arrives in edx and nothing is passed on the stack: a whole-program-optimised (/GL)
// static function. __fastcall with an unused first parameter reproduces that register.
int __fastcall count_bits_32(int unused, unsigned int value)
{
    int count = 0;
    int bit;

    for (bit = 0; bit < 32; bit++)
    {
        if (value & (1 << bit))
            count++;
    }
    return count;
}
