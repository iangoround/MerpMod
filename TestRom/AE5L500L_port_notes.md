# AE5L500L MerpMod port — map file notes

## Files produced

| File | Purpose |
|------|---------|
| `MerpMod/Targets/AE5L500L.map` | IDA/HEW-style map: 537 addresses, 1636 symbol names. This is the port deliverable. |
| `MerpMod/Targets/AE5L500L.h` | Header with the same defines, generated with the `idatohew.xml` define/priority rules (useful for checking the import). |
| `MerpMod/Targets/AE5L500LConfig.h` | Target config (AUTO_TRANS=0, SD_DMAP=0, MT 2.0 L EJ255). |

The ROM file in `TestRom` is actually named `AE5L500L.bin` (1 MB, SH7058). CALID at `0x2004`
reads `AE5L500L`; ECUID bytes `8A 12 58 40 07` are at `0xD97EC`.

## How the addresses were obtained

No IDA database exists for this ROM, so the map was reconstructed from:

1. **ECUFlash definition** `TestRom/AE5L500L.xml` — all 345 table/axis addresses. Names are
   normalized exactly as SharpTune's XMLtoIDC does (remove punctuation, spaces -> `_`), e.g.
   `Max Wastegate Duty Limit Post-Compensation` -> `Max_Wastegate_Duty_Limit_PostCompensation`.
   Verified against `AZ1G500F.xml` / `AZ1G500F.map` (0 mismatches).
2. **Direct SH-4 disassembly** of `AE5L500L.bin` (capstone, big-endian SH4) plus a literal-pool
   cross-reference engine (`mov.l @(disp,PC),Rn` decoding). Hooks are the literal-pool slots
   themselves, because MerpMod patches the 4-byte pointer stored there (see `Metadata.c`).
3. **Existing target maps** (`AE5K700V.h`, `A8DH202X.h`, …) used as a structural cross-check —
   AE5K700V is a very close sibling (MAF routine and pull functions are the same code, shifted).
4. Ghidra helper scripts already present in `C:\Users\ianph\ghidra_scripts` (verified MAF RAM
   addresses and ROM hole).

## Key derived addresses (high confidence — verified in the ROM bytes)

| Symbol | Address | Evidence |
|--------|---------|----------|
| dCalId / ECU_CALIBRATION | `0x2004` | CALID string `AE5L500L` |
| dEcuId / ECU_ID | `0xD97EC` | bytes `8A 12 58 40 07` |
| dRomHoleStart | `0xDAE88` | start of longest 0xFF run (`0xDAE88..0xF8900`, size `0x1DA78`) |
| sPull2DFloat | `0xBE830` | pull routine; pointer at `0x4A88` |
| sPull3DFloat | `0xBE8E4` | pull routine; pointers at `0x13AF0`, `0x13FD4`, `0x40338` |
| sMafCalc | `0x4A2C` | routine containing the MAF scaling pull call |
| hMafCalc | `0x4A88` | pool holding `sPull2DFloat`, loaded at `0x4A38` in sMafCalc |
| pMafSensorVoltage | `0xFFFF4042` | loaded at `0x4A2E`/`0x4A4E`; Ghidra-verified |
| pMassAirFlow | `0xFFFF40B4` | loaded at `0x4A46`; Ghidra-verified |
| hTableTargetBoost | `0x13AEC` | pool holding the target-boost descriptor `0xAA9B0`, loaded at `0x13A1C` |
| hPullTargetBoost | `0x13AF0` | pool holding `sPull3DFloat`, loaded at `0x13A1E` |
| sWgdc | `0x13D58` | WGDC routine containing all table pulls |
| hTableWgdcInitial | `0x13FD0` | pool holding descriptor `0xAA994`, loaded at `0x13DF6` |
| hPullWgdc | `0x13FD4` | pool holding `sPull3DFloat`, loaded at `0x13DF8` |
| hTableWgdcMax | `0x13FF0` | pool holding descriptor `0xAA978`, loaded at `0x13E3C` |
| hInjectorScaling | `0x3038C` | pool holding `0xCBE08` ("Injector Flow Scaling"), loaded at `0x30360` |
| hRevLimDelete | `0x4ACB8` | pool holding `sRevLimStart`, loaded at `0x4AA7E` |
| sRevLimStart | `0x3B644` | routine referencing rev-limit table pool at `0x3B778` |
| sRevLimEnd | `0x3D2D8` | tail-call target loaded from pool `0x3B798` |
| pFlagsRevLim | `0xFFFF7CB4` | pool `0x3B788`, loaded in sRevLimStart |
| hMemoryReset | `0xFCE8` | pool holding `sMemoryReset`, loaded by reset handler at `0xFA84` |
| sMemoryReset | `0x10290` | routine using limits `0xFFFF4000` / `0xFFFFBF9F` |
| hMemoryResetLimit | `0x10370` | pool holding pointer to `0xFFFFBF9F`, loaded at `0x10294` |
| sCelTrigger | `0x7FD9A` | third `bsr` in the `sts.l pr; bsr;nop; bsr;nop; bsr;nop` CEL pattern at `0x7FD34` |
| hCelSignal | `0x7FF04` | pool holding `0xFFFFA384`, loaded at `0x7FE3E`+ |
| pCelSignalOem | `0xFFFFA384` | RAM address immediately after CEL port `0xFFFFA380` |
| hTableBaseTiming | `0x40334` | pool holding descriptor `0xAE2DC`, loaded at `0x4014A` |
| hPull3DTiming | `0x40338` | pool holding `sPull3DFloat`, loaded in the timing routine |

## Ghidra verification (2026-11-19)

`C:\Users\ianph\ghidra_scripts\AE5L500L_verify.py` was run headless with Ghidra 12.2
(`SuperH4:BE:32:default`, RAM block `0xFFFF0000-0xFFFFFFFF`, auto-analysis enabled).
Full output: `TestRom/AE5L500L_ghidra_verify_report.txt` (280 KB).

**Confirmed by Ghidra:**

* **All 13 hook slots** still contain their expected old pointer — 0 mismatches.
* **CALID** `AE5L500L`, **ECUID** `8A12584007`, **ROM hole** all-`0xFF` at `0xDAE88`.
* **RAM hole**: largest unreferenced gap `0xFFFFB719..0xFFFFBF90` (0x877 bytes).
  The map's `0xFFFFB720..0xFFFFBF70` sits inside it and is 4-byte aligned — no change needed.
* **Flag/switch addresses** (xref counts from the report): resume `0xFFFF5FCB` (21),
  coast `0xFFFF5FCA` (17), brake `0xFFFF5FCC` (16), clutch `0xFFFF65F4` (5),
  test mode `0xFFFF69EC` (68), rev-limit flags `0xFFFF7CB4` (11),
  CEL signal `0xFFFFA384` (5).
* **Engine parameters**: Ghidra found direct xrefs for `pEngineSpeed` (3), `pVehicleSpeed` (6),
  `pCoolantTemp` (33), `pAtmoPress` (3), `pEngineLoad` (8), `pIntakeAirTemp` (14),
  `pThrottlePlate` (7), `pReqTorque` (12), `pFbkc4` (9), `pAf1Res` (37), `pKcaIam` (3),
  `pWgdc4` (10), `pMassAirFlow` (3), `pMafSensorVoltage` (7),
  `pManifoldAbsolutePressure` (24), plus literal pools for most of them.

## Follow-up: additional items found (GBR + descriptor tracing)

* **Switch flags are individual 0/1 bytes, not bitfields.** GBR decoding found
  `pCoastFlags` at GBR `0xFFFF5FC7`+3, `pResumeFlags`/`pBrakeFlags` at GBR `0xFFFF5FC2`+9/+10;
  the OEM code writes literal 0 or 1 to them (`cmp/eq #1, r0`). Consequently
  **all switch bitmasks are now `0x01`** — `BrakeBitMask` was corrected from the sibling value
  `0x80`. Clutch (`0xFFFF65F4`) is likewise compared to 1.
* **Tip-in enrichment**: `tTipInEnrich = 0xCED4C`, `hPull2DTipInEnrich = 0x3AA40` (pull2D pool),
  table hook at `0x3AA58` (descriptor `0xAD328`).
* **POLF KCA hooks**: `hTablePolfKcaAlt = 0x36298`, `hTablePolfKcaBLo = 0x362B0`,
  `hTablePolfKcaBHi = 0x362B4`; `sPolf = 0x3604C`. `hPull3DPolf = 0x3629C`.
  No literal pool holds `sPolf`, so `hPolf` cannot be defined (POLF_HACKS is 0 in Flash.h).
* **Engine load smoothing factors** added at `0xC2D40` (A = 0.7), `0xC2D3C` (B = 0.4),
  `0xC2D38` (Alt = -1.0) and `0xC2D48` (Final = 0.9) — the first three match AE5K700V exactly.

## Items still needing manual confirmation before flashing

* `pDefogFlags` (`0xFFFF69EF`) and `pSSMResetByte` (`0xFFFF2D8E`) returned **0 direct xrefs**
  in Ghidra (nearby GBR accesses: `0xFFFF2D90`/`0xFFFF2DA0`). Confirm in `SsmGet_Switches_63...`.
* `pFbkc1` (`0xFFFF689F`), `pIam1` (`0xFFFF68A1`), `pIam4` (`0xFFFF2B3C`) and
  `pCurrentGear` (`0xFFFF6835`) still have 0 direct/GBR xrefs. Nearby referenced bytes are
  `0xFFFF6894`/`0xFFFF6898` and `0xFFFF6830-0xFFFF6842`; the sibling addresses may be wrong.
  These are only used for logging/definitions, not for any patch hook.
* Still undefined (feature disabled or needs manual RE): CEL flash tables, `sShortToFloat`,
  spark-cut points, `tPolf` (main) and `hPolf`. `Flash.h` disables BOOST/TIMING/POLF/SPARK,
  so these do not block a Flash build. **CEL_HACKS is enabled and its three defines are present.**

## Build verification (2026-11-19)

`Flash_Testing` build completed with **0 errors, 3 warnings**. All patch baselines matched the
real ROM bytes, and SharpTune validated apply **and** remove:

| Hook | OEM value | Patched value |
|------|-----------|---------------|
| hMafCalc `0x4A88` | `0x000BE830` | `0x000DBA78` |
| hRevLimDelete `0x4ACB8` | `0x0003B644` | `0x000DC6D4` |
| hMemoryReset `0xFCE8` | `0x00010290` | `0x000DC26C` |
| hCelSignal `0x7FF04` | `0xFFFFA384` | `0xFFFFB788` |

`patched.bin` differs from OEM in 7,183 bytes; `reverted.bin` is byte-identical to OEM.
Generated outputs:

* `TestRom\AE5L500L.MeRpMoD.Flash.Testing.*.patch` (76,704 B)
* `SubaruDefs\RomRaider\logger\MerpMod\Testing\AE5L500L.MeRpMoD.Flash.Testing.*.xml` (1.6 MB)
* `SubaruDefs\ECUFlash\subaru standard\MerpMod\Testing\AE5L500L.MeRpMoD.Flash.Testing.*.xml`

Supporting files added to SubaruDefs so definition generation works:
`ECUFlash\subaru standard\Impreza WRX\AE5L500L.xml`, `RomRaider\ecu\standard\RR_AE5L500L.xml`,
and `RomRaider\logger\logger.xml` (copy of `standard\logger.xml`).

## ECUFlash definition fix (fields not editable)

The first generated mod definition was only 833 B (romid + include, **no tables**) because SharpTune
could not find the MerpMod base tables. Root cause: `SubaruDefs\ECUFlash\subaru standard\Bases\32BITBASE.xml`
(502 KB) lacked the MerpMod table definitions, while SharpTune's embedded copy
(`C:\Users\ianph\.SharpTune\EmbeddedDefs\SharpTune.Resources.Defs.Bases.32BITBASE.xml`, 696 KB) has them.
Installed the embedded copy over the repo base (backup kept as `32BITBASE.xml.bak`) and re-ran the
Update phase. The regenerated definition now contains 39 MerpMod tables (3,482 B) and was copied to:

`C:\Users\ianph\OneDrive\Documents\Automobile\Subaru\EcuFlash\rommetadata\subaru\MerpMod\Testing\AE5L500L.MeRpMoD.Flash.Testing..19.11.26.16.22.xml`

Verified: internalidaddress `DAE88` matches the mod CALID string in `patched.bin`, ECUID
`A540E1E0C1` matches, `<include>AE5L500L</include>` resolves, and every table name has a scaling
in ECUFlash's `rommetadata\subaru\Bases\32BITBASE.xml`. **Restart ECUFlash** so it reloads metadata,
then open `TestRom\patched.bin`.

## Sibling-ROM comparison (AE5IB00V.hex / AE5K700V.hex, 2026-11-19)

`C:\dev\AE5IB00V.hex` and `C:\Dev\AE5K700V.hex` are raw 1 MB SH7058 binaries with companion
`.map/.h/.txt` files in `Targets\`. Normalized code-signature matching (masking PC-relative
displacements and bsr targets) against these confirmed and corrected several addresses:

| Symbol | Reference | AE5L500L | Evidence |
|--------|-----------|----------|----------|
| sPull2DFloat / sPull3DFloat | IB00V `0xBE7F4`/`0xBE8A8`, K700V same | `0xBE830`/`0xBE8E4` | +0x3C in both |
| sMafCalc | IB00V/K700V `0x498C` | `0x4A2C` | +0xA0 |
| sMemoryReset | IB00V `0xFFE4`, K700V `0x101C8` | `0x10290` | +0x2AC / +0xC8 |
| **sWgdc** | IB00V `0x134CC` | **`0x1383C`** | +0x370 (our earlier `0x13D58` is actually **sWgdc0**, IB00V `0x139E8`) |
| **hWgdc** | IB00V `0x48AB0` (slot holds sWgdc) | **`0x4A574`** | slot at `0x4A574` contains `0x1383C` |
| **sBaseTiming** | K700V `0x4069C` | **`0x40026`** | confirmed by descriptor 0xAE2DC → pool 0x40334 |
| **hBaseTiming** | slot holds sBaseTiming | **`0x4AD9C`** | slot contains `0x40026` |
| **sPolf** | K700V `0x364E4` | **`0x36048`** | slot 0x4ACDC holds it |
| **hPolf** | slot holds sPolf | **`0x4ACDC`** | — |

`hWgdc`, `hBaseTiming`, `hPolf` all sit in the same master function-pointer vector table
(`0x4AC90..0x4ADC0`), matching the README_PORTING description of the "large subroutine vector
jump table". The STI (K700V) has extra exhaust-AVCS code, which shifts the timing-region
addresses relative to the WRX; IB00V (no exhaust AVCS) was the better anchor there.

Still unresolved for a full Switch build: `sShortToFloat`, startup-enrich hooks/tables,
boost-alt/KCA hooks, and a few optional defines. These are under `#if defined(...)` guards,
so the build degrades gracefully, but `sShortToFloat` is unconditional under `SWITCH_HACKS`.

## Switch_Testing build — patch validation fixes (2026-11-19)

The Switch build compiled with 0 errors. SharpTune's baseline validation exposed six wrong
`t*` defines: these must be the **descriptor addresses** the OEM code loads (not the raw table
addresses from the XML). Corrections, each taken from the actual 4 bytes at the hook slot:

| Patch | Slot / define | Correct value |
|-------|---------------|---------------|
| Memory Reset Limit | `hMemoryResetLimit` → `0x11CE8` | `0xFFFFBF9F` |
| WGDC Initial Table | `tWgdcInitial` | `0xAA994` |
| WGDC Max Table | `tWgdcMax` | `0xAA978` |
| Target Boost Table | `tTargetBoost` | `0xAA9B0` |
| Timing Table | `tBaseTiming` | `0xAE2DC` |
| POLF KCA Table | `tPolfKcaAlt/Lo/Hi` | `0xAD634` / `0xAD688` / `0xAD6A4` |

All other patches (CALID, ECUID, rev limit, memory reset, MAF, CEL, WGDC/POLF/timing main hooks,
pull hooks, and the 0xAB71-byte ROM-hole code patch) validated against the real ROM bytes.
Still undefined (optional features, patches silently skipped): boost-alt/KCA, WGDC-alt, spark
cut, `pSiDrive`, `pDeltaMap`. `sShortToFloat` was mapped to `0xBEA6C` (best candidate found via
Ghidra) — verify TGV input scaling at runtime.

## Switch_Testing build SUCCESS (2026-11-19)

Final build: **0 errors**, all patches validated, patch applied and removed cleanly.
`patched.bin` differs from OEM in 43,813 bytes; `reverted.bin` is byte-identical to OEM.
MOD CALID at `0xDAE88` = `AE5L500L.MeRpMoD.Switch.Testing..19.11.26.20.05`.

Generated definition: `SubaruDefs\ECUFlash\subaru standard\MerpMod\Testing\AE5L500L.MeRpMoD.Switch.Testing..19.11.26.20.05.xml` (14,553 B, **120 tables**) — copied into ECUFlash's
`rommetadata\subaru\MerpMod\Testing\`. It contains all the previously-missing field groups:
boost/WGDC/target boost (per-gear, 3 maps), POLF (6 maps), base timing (6 maps), knock retard
(6 maps), map switching/blending, input config (TGV scaling), tip-in/cranking/startup blending
multipliers, LC/FFS, rev limit, CEL flash, and SD tables. RomRaider logger/ECU definitions were
also generated under `SubaruDefs\RomRaider\`.

To use: restart ECUFlash (to reload metadata), open `TestRom\patched.bin`, accept the checksum
correction. Flash to a bench/test ECU first — `sShortToFloat` is still a best-candidate value.

## Safety review of patched.bin (Switch build, 20:11)

- File is exactly 1,048,576 bytes; reset vector at `0xFFFFF0` is byte-identical to OEM.
- 43,820 bytes changed. Every change is in a known hook slot, CALID/ECUID, the checksum word at
  `0xFFB88`, or the ROM hole `0xDAE88..0xE59F8`. The entire ROM hole was `0xFF` in OEM (0 non-FF
  bytes), so no OEM code/data was overwritten. Code ends at `0xE59F8`, well before the hole's end
  `0xF8900`.
- RAM hole `0xFFFFB720` sits inside the largest unreferenced RAM gap found by Ghidra
  (`0xFFFFB719..0xFFFFBF90`); the memory-reset limit was lowered to `0xFFFFB71F` to preserve
  variables (RAM_PERSIST). No overlap with OEM-referenced RAM.
- All 3D axes are monotonic; dimensions read from the C source match the definitions. Default
  values are sane for a stock-like baseline: VE 27–67%, atmo comp 1.0, SD blend 0–1, redline
  7,200 rpm, LC cut 4,000 rpm, displacement 2.46 L, SD constant 0.00387.
- **All hacks are off by default:** Boost Hack Enable=0, Timing Hack Enable=0, POLF Hack Enable=0,
  Speed Density Mode=0 (`MafModeUndefined`, which falls through to MAF-sensor output), FFS/LC
  modes=0/undefined. So the car should run on OEM MAF logic.
- **WARNING:** the mod tables are generic placeholders, NOT a base map (as README.md states):
  all seven Per Gear Wastegate tables are entirely ZERO, Per Gear Target Boost tables are flat,
  and fueling/timing/KCA tables are flat template values. Enabling any hack without first filling
  these in will cause poor or dangerous behavior (e.g. 0% WGDC = no boost). Bench/test ECU only.
- ECUFlash/RomRaider checksum correction should still be accepted on first open (checksum word at
  `0xFFB88` was updated by SharpTune but the module may not match its expected value).

## OEM WGDC / Target Boost values populated (2026-11-20)

All 32 boost/WGDC tables in the Switch build were populated from this ROM's OEM tables
(`Initial Wastegate Duty @ C1150`, `Max Wastegate Duty @ C0F58`, `Target Boost @ C1340`):

- **Per Gear Wastegate / Target Boost (14 tables, 6×16):** OEM values at the highest-torque
  column, interpolated onto the mod's 2000–8200 rpm axis. WGDC runs 90% → 28%; target boost
  runs ~7.3 → 13.3 psi.
- **WGDC / Target Boost Compensation (18 tables, 16×16):** per-torque ratio of OEM value to the
  high-torque reference, so `(base-760)*comp+760` reproduces the OEM torque dependence exactly
  (e.g. at mid torque the boost comp is 0.24 → 3.2 psi, matching OEM).
- Updated `BoostHackTables.c` arrays and the compiled `Switch_Testing\MerpMod.mot` S-records so a
  rebuild reproduces the values. Rebuilt patch validated: **all patches valid, HEW BUILD SUCCESS**.
- Restored missing `SubaruDefs\ECUFlash\subaru standard\Bases\32BITBASE.xml` (this had stopped
  definition generation with "key not present in dictionary").

## Switch CALID aligned to OEM (2026-11-20)

Set `MOD_CALIBRATION_ID = AE5L500L` in `Targets\AE5L500LConfig.h` and updated the `newcalid`
field in the `.mot` metadata at `0x80001024` (the auto-generated `AE5L5MML` came from the
`FFFFFFFF` placeholder). After rebuilding the patch, the Switch ROM's CALID at `0x2004` is now
`AE5L500L`, matching the OEM ROM; the Calibration ID Patch is a no-op (baseline == payload).
Both ECUFlash definitions continue to identify via the long MOD CALID at `0xDAE88`, and the
RomRaider ECU definition keys off that same address, so there is no collision with the stock
`AE5L500L` definition. Bundle rebuilt at `C:\Dev\patched\AE5L500L_MerpMod_Bundle.zip`.

## Using the map

`SharpTune.exe` imports the map from `/SubaruDisassembly/Maps` (per README.md) and generates
`Targets/AE5L500L.h`. The `.h` in this folder is the expected output for cross-checking.
Set `TARGETROM=AE5L500L` in HEW, select the Flash configuration, and run the Target Selection
and Update build phases. Always accept the ECUFlash checksum correction after patching.
