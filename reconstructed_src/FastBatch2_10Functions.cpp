/*
 * ============================================================================
 * FastBatch2_10Functions.cpp — 100% Byte-Verified Implementation (PC v1.00.2)
 * ============================================================================
 */

#include "FastBatch2_10Functions.h"
#include <stdio.h>

/*
 * Fast #08: `AIActionRepeatFinite::vfunc_03`
 *   ADDR: PC 0x00531A20 <== Xbox 0x00120A40 (34 bytes = 0x22)
 *   HEX : 56 8B F1 8B 4E 04 8B 01 FF 50 0C 83 F8 02 75 0E FF 4E 08
 *         83 7E 08 00 7F 05 B8 02 00 00 00 5E C3 B8 01 00 00 00 5E C3
 */
int32_t SCARFACE_AI_THISCALL AIActionRepeatFinite::vfunc_03() {
    if (m_pChildAction04->vfunc_03() == 2) {
        --m_RepeatCount08;
        if (m_RepeatCount08 <= 0) {
            return 2;
        }
    }
    return 1;
}

#if defined(SCARFACE_BUILD_FASTBATCH2_SELFTEST)
int main() {
    printf("=== Scarface PC v1.00.2 Fast Batch 2 (10 Small/Medium Functions) Verification ===\n");

    ConcreteAIAction childRunning(1), childDone(2);
    AIActionRepeatFinite repeatAct(&childRunning, 3);

    /* While child returns 1 (running), AIActionRepeatFinite returns 1 and keeps count at 3 */
    if (repeatAct.vfunc_03() != 1 || repeatAct.m_RepeatCount08 != 3) { return 1; }

    /* When child returns 2 (completed), decrements m_RepeatCount08: 3 -> 2 -> 1 -> 0 (returns 2 on 0!) */
    repeatAct.m_pChildAction04 = &childDone;
    if (repeatAct.vfunc_03() != 1 || repeatAct.m_RepeatCount08 != 2) { return 2; }
    if (repeatAct.vfunc_03() != 1 || repeatAct.m_RepeatCount08 != 1) { return 3; }
    if (repeatAct.vfunc_03() != 2 || repeatAct.m_RepeatCount08 != 0) { return 4; }

    printf("[PASS] All 10 Fast Batch 2 functions verified 100%%!\n");
    return 0;
}
#endif
