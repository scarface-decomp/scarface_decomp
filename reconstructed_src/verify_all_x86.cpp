#define SCARFACE_FREESTANDING_X86_CHECK 1
#include "EmpireSubHUDs.h"
#include "CharacterObject.h"
#include "StarterBatch1_25Functions.h"
#include "AIAction.h"

int VerifyAllFivePacksX86() {
    if (sizeof(EmpireHUD)        != 0x080) return -1;
    if (sizeof(BusinessHUD)      != 0x084) return -2;
    if (sizeof(DrugWarsHUD)      != 0x0C0) return -3;
    if (sizeof(ExoticsHUD2)      != 0x0C4) return -4;
    if (sizeof(CharacterObject)  != 0x430) return -5;
    if (VerifyCharacterFieldOffsetsX86() != 0x430) return -6;
    if (VerifyBatch1FieldOffsetsX86()    != 25)    return -7;
    if (VerifyAIActionAndRTTIOffsetsX86()!= 0x677) return -8;
    return 0x1002;
}
