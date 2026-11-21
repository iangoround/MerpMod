#define MOD_ECUID 26614D3435
#define MOD_DATE 20.11.26.11.52
#include "Switch.h"
#define MOD_CONFIG Switch
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AE5L500L
#define ECU_IDENTIFIER 8A12584007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D97EC)
#define dRomHoleStart (0x000DAE88)
#define pRamHoleStart (0xFFFFB720)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000BE830)
#define sPull3DFloat (0x000BE8E4)

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0A)
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C0C)
#define sShortToFloat (0x000BEA6C)
#define hPull2DTipInEnrich (0x0003AA40)
#define tTipInEnrich (0x000CED4C)
#define tCrankingFuelA (0x000CD2E2)
#define tCrankingFuelB (0x000CD302)
#define tCrankingFuelC (0x000CD322)
#define tCrankingFuelD (0x000CD342)
#define tCrankingFuelE (0x000CD362)
#define tCrankingFuelF (0x000CD382)
#define tStartupEnrich2_1A (0x000CF958)
#define tStartupEnrich2_1B (0x000CF8B4)
#define tStartupEnrich2_2A (0x000CC91D)
#define tStartupEnrich2_2B (0x000CF958)
#define tStartupEnrich3_1A (0x000CF8B4)
#define tStartupEnrich3_1B (0x000CF958)
#define tStartupEnrich3_2A (0x000CC91D)
#define tStartupEnrich3_2B (0x000CF8B4)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0004ACB8)
#define sRevLimStart (0x0003B644)
#define sRevLimEnd (0x0003D2D8)
#define pFlagsRevLim ((unsigned char*)0xFFFF7CB4)
#define RevLimBitMask (0x00000001)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004A88)
#define sMafCalc (0x00004A2C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000CBE08)
#define hInjectorScaling (0x0003038C)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007FD9A)
#define hCelSignal (0x0007FF04)
#define pCelSignalOem ((unsigned char*)0xFFFFA384)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00013AF0)
#define hTableTargetBoost (0x00013AEC)
#define tTargetBoost (0x000AA9B0)
#define tTargetBoostKcaAlt (0x000CFEEC)
#define tTargetBoostKcaBLo (0x000D0240)
#define tTargetBoostKcaBHi (0x000D0400)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00013FD4)
#define hWgdc (0x0004A574)
#define sWgdc (0x0001383C)
#define hTableWgdcInitial (0x00013FD0)
#define tWgdcInitial (0x000AA994)
#define hTableWgdcMax (0x00013FF0)
#define tWgdcMax (0x000AA978)
#define tWgdcInitialKcaAlt (0x000CFEEC)
#define tWgdcMaxKcaAlt (0x000CFEEC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF79A0)
#define hPull3DPolf (0x0003629C)
#define tPolf (0x000D05C0)
#define hPolf (0x0004ACDC)
#define sPolf (0x00036048)
#define pPolfEnrich (0xFFFF79A0)
#define tPolfKcaAlt (0x000AD634)
#define hTablePolfKcaAlt (0x00036298)
#define tPolfKcaBLo (0x000AD688)
#define hTablePolfKcaBLo (0x000362B0)
#define tPolfKcaBHi (0x000AD6A4)
#define hTablePolfKcaBHi (0x000362B4)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x0004AD9C)
#define hTableBaseTiming (0x00040334)
#define tBaseTiming (0x000AE2DC)
#define pBaseTiming (0xFFFF7F20)
#define sBaseTiming (0x00040026)
#define hPull3DTiming (0x00040338)
#define tBaseTimingPCruise (0x000D4710)
#define tBaseTimingPNonCruise (0x000D48D0)
#define tBaseTimingRCruiseAvcs (0x000D4A90)
#define tBaseTimingRNonCruiseAvcs (0x000D4C50)
#define pKcaIam (0xFFFF8250)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF5FCB)
#define ResumeBitMask ((unsigned char)0x00000001)
#define pCoastFlags ((unsigned char*)0xFFFF5FCA)
#define CoastBitMask ((unsigned char)0x00000001)
#define pBrakeFlags ((unsigned char*)0xFFFF5FCC)
#define BrakeBitMask ((unsigned char)0x00000001)
#define pClutchFlags ((unsigned char*)0xFFFF65F4)
#define ClutchBitMask ((unsigned char)0x00000001)
#define pTestModeFlags ((unsigned char*)0xFFFF69EC)
#define TestModeBitMask ((unsigned char)0x00000020)
#define pDefogFlags ((unsigned char*)0xFFFF69EF)
#define DefogBitMask ((unsigned char)0x00000020)
#define pSSMResetByte ((unsigned char*)0xFFFF2D8E)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF689F)
#define pFbkc4 ((float*)0xFFFF77FC)
#define pIam1 ((unsigned char*)0xFFFF68A1)
#define pIam4 ((float*)0xFFFF2B3C)
#define pEngineSpeed ((float*)0xFFFF6648)
#define pVehicleSpeed ((float*)0xFFFF6624)
#define pCoolantTemp ((float*)0xFFFF4144)
#define pAtmoPress ((float*)0xFFFF68C4)
#define pManifoldAbsolutePressure ((float*)0xFFFF42FC)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF63FC)
#define pReqTorque ((float*)0xFFFF854C)
#define pThrottlePlate ((float*)0xFFFF62E4)
#define pWgdc4 ((float*)0xFFFF79C4)
#define pCurrentGear ((unsigned char*)0xFFFF6835)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2D40)
#define dLoadSmoothingB (0x000C2D3C)
#define dLoadSmoothingAlt (0x000C2D38)
#define dLoadSmoothingFinal (0x000C2D48)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x00010290)
#define hMemoryReset (0x0000FCE8)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011CE8)

