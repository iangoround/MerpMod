/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#include "EcuHacks.h"

#define COMP80_DATA1 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA2 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA3 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA4 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA5 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA6 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA7 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA8 0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,0,	1008,	2016,	3025,	4033,	5041,	6049,	7058,	8066,	9074,	10082,	11091,	12099,	13107,	13107,	13107,
#define COMP80_DATA COMP80_DATA1 COMP80_DATA2 COMP80_DATA3 COMP80_DATA4 COMP80_DATA5 COMP80_DATA6 COMP80_DATA7 COMP80_DATA8

#define COMP100_DATA1 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA2 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA3 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA4 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA5 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA6 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA7 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA8 0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,0,	1260,	2521,	3781,	5041,	6302,	7562,	8822,	10082,	11343,	12603,	13863,	15124,	16384,	16384,	16400,
#define COMP100_DATA COMP100_DATA1 COMP100_DATA2 COMP100_DATA3 COMP100_DATA4 COMP100_DATA5 COMP100_DATA6 COMP100_DATA7 COMP100_DATA8

#define COMP_COLS 100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350
#define COMP_ROWS 2000,2600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200

/////////////////
//Constants
/////////////////
#if BOOST_HACKS

unsigned char DefaultBoostHackEnabled BOOSTDATA = HackDisabled;

float RPMLockWGDC BOOSTDATA = 3000.0f;
float ThrottleLockWGDC BOOSTDATA = 85.0f;

#if SWITCH_HACKS
TableGroup PGWGTableGroup BOOSTDATA = {
	{&PGWGTable1i,
	&PGWGTable1s,
	&PGWGTable1ss},
	{&PGWGTable2i,
	&PGWGTable2s,
	&PGWGTable2ss}
};

TableGroup PGTBTableGroup BOOSTDATA = {
	{&PGTBTable1i,
	&PGTBTable1s,
	&PGTBTable1ss},
	{&PGTBTable2i,
	&PGTBTable2s,
	&PGTBTable2ss}
};

TableGroup WGDCInitialTableGroup BOOSTDATA = {
	{&WGDCInitialTable1i,
	&WGDCInitialTable1s,
	&WGDCInitialTable1ss},
	{&WGDCInitialTable2i,
	&WGDCInitialTable2s,
	&WGDCInitialTable2ss}
};

TableGroup WGDCMaxTableGroup BOOSTDATA = {
	{&WGDCMaxTable1i,
	&WGDCMaxTable1s,
	&WGDCMaxTable1ss},
	{&WGDCMaxTable2i,
	&WGDCMaxTable2s,
	&WGDCMaxTable2ss}
};

TableGroup TargetBoostTableGroup BOOSTDATA = {
	{&TargetBoostTable1i,
	&TargetBoostTable1s,
	&TargetBoostTable1ss},
	{&TargetBoostTable2i,
	&TargetBoostTable2s,
	&TargetBoostTable2ss}
};
#endif 

///////////////
//PGWG TABLE 1 i
///////////////
ThreeDTable PGWGTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData1i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1i,
	.rowHeaderArray = PGWGRows1i,
	.tableCells = PGWGData1i,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 i
///////////////
ThreeDTable PGWGTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData2i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2i,
	.rowHeaderArray = PGWGRows2i,
	.tableCells = PGWGData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };
	
#if SWITCH_HACKS
///////////////
//PGWG TABLE 1 s
///////////////
ThreeDTable PGWGTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData1s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1s,
	.rowHeaderArray = PGWGRows1s,
	.tableCells = PGWGData1s,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 s
///////////////
ThreeDTable PGWGTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData2s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2s,
	.rowHeaderArray = PGWGRows2s,
	.tableCells = PGWGData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };	
	
///////////////
//PGWG TABLE 1 ss
///////////////
ThreeDTable PGWGTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData1ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1ss,
	.rowHeaderArray = PGWGRows1ss,
	.tableCells = PGWGData1ss,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 ss
///////////////
ThreeDTable PGWGTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGData2ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2ss,
	.rowHeaderArray = PGWGRows2ss,
	.tableCells = PGWGData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };	
#endif

///////////////
//PGWG TABLE VALET MODE
///////////////
ThreeDTable PGWGTableValetMode __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGColsVM[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRowsVM[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGWGDataVM[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	23040,	21247,	21247,	21247,	21247,
	21247,	21247,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17664,	17408,	17408,
	17408,	17408,	17408,	17408,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,	16896,
	15018,	15018,	15018,	15018,	15018,	15018,	11264,	11264,	11264,	11264,	11264,	11264,	12799,	12799,	12799,	12799,
	12799,	12799,	12629,	12629,	12629,	12629,	12629,	12629,	10752,	10752,	10752,	10752,	10752,	10752,	12117,	12117,
	12117,	12117,	12117,	12117,	10922,	10922,	10922,	10922,	10922,	10922,	7168,	7168,	7168,	7168,	7168,	7168,
};

ThreeDTable PGWGTableValetMode __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGColsVM,
	.rowHeaderArray = PGWGRowsVM,
	.tableCells = PGWGDataVM,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };
	
///////////////
//PGWG RAM LUT
///////////////
#if PGWG_RAMTUNING
ThreeDTable PGWGRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->PGWGRamCols),
	.rowHeaderArray = &(pRamVariables->PGWGRamRows),
	.tableCells = &(pRamVariables->PGWGRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };
#endif

///////////////
//PGTB TABLE 1i
///////////////
ThreeDTable PGTBTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData1i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1i,
	.rowHeaderArray = PGTBRows1i,
	.tableCells = PGTBData1i,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000 .01933677	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2i
///////////////
ThreeDTable PGTBTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData2i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2i,
	.rowHeaderArray = PGTBRows2i,
	.tableCells = PGTBData2i,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };

#if SWITCH_HACKS
///////////////
//PGTB TABLE 1s
///////////////
ThreeDTable PGTBTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData1s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1s,
	.rowHeaderArray = PGTBRows1s,
	.tableCells = PGTBData1s,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2s
///////////////
ThreeDTable PGTBTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData2s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2s,
	.rowHeaderArray = PGTBRows2s,
	.tableCells = PGTBData2s,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };


///////////////
//PGTB TABLE 1ss
///////////////
ThreeDTable PGTBTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData1ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1ss,
	.rowHeaderArray = PGTBRows1ss,
	.tableCells = PGTBData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2ss
///////////////
ThreeDTable PGTBTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBData2ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2ss,
	.rowHeaderArray = PGTBRows2ss,
	.tableCells = PGTBData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };
#endif

///////////////
//PGTB TABLE VALET MODE
///////////////
ThreeDTable PGTBTableValetMode __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBColsVM[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRowsVM[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short PGTBDataVM[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	1140,	1140,	1140,	1140,	1140,	1140,	1346,	1346,	1346,	1346,	1346,	1346,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,
	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1450,	1443,	1443,	1443,	1443,
	1443,	1443,	1436,	1436,	1436,	1436,	1436,	1436,	1430,	1430,	1430,	1430,	1430,	1430,	1423,	1423,
	1423,	1423,	1423,	1423,	1413,	1413,	1413,	1413,	1413,	1413,	1400,	1400,	1400,	1400,	1400,	1400,
};

ThreeDTable PGTBTableValetMode __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBColsVM,
	.rowHeaderArray = PGTBRowsVM,
	.tableCells = PGTBDataVM,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };
	
///////////////
//PGTB RAM LUT
///////////////
#if PGWG_RAMTUNING
ThreeDTable PGTBRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->PGTBRamCols),
	.rowHeaderArray = &(pRamVariables->PGTBRamRows),
	.tableCells = &(pRamVariables->PGTBRamData),
	.tableType = UInt16Table3D,
	.multiplier = 1.0,//0x3B800000
	.offset = 0 };	
#endif

///////////////////
//WGDC Initial Table 1i LUT
///////////////////
ThreeDTable WGDCInitialTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData1i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols1i,
	.rowHeaderArray = WGDCInitialRows1i,
	.tableCells = WGDCInitialData1i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

///////////////////
//WGDC Initial Table 2 LUT
///////////////////
ThreeDTable WGDCInitialTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData2i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols2i,
	.rowHeaderArray = WGDCInitialRows2i,
	.tableCells = WGDCInitialData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

#if SWITCH_HACKS
///////////////////
//WGDC Initial Table 1s LUT
///////////////////
ThreeDTable WGDCInitialTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData1s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols1s,
	.rowHeaderArray = WGDCInitialRows1s,
	.tableCells = WGDCInitialData1s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

///////////////////
//WGDC Initial Table 2s LUT
///////////////////
ThreeDTable WGDCInitialTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData2s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols2s,
	.rowHeaderArray = WGDCInitialRows2s,
	.tableCells = WGDCInitialData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

///////////////////
//WGDC Initial Table 1ss LUT
///////////////////
ThreeDTable WGDCInitialTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData1ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols1ss,
	.rowHeaderArray = WGDCInitialRows1ss,
	.tableCells = WGDCInitialData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

///////////////////
//WGDC Initial Table 2ss LUT
///////////////////
ThreeDTable WGDCInitialTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCInitialRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCInitialData2ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCInitialTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols2ss,
	.rowHeaderArray = WGDCInitialRows2ss,
	.tableCells = WGDCInitialData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
#endif
	
///////////////
//WGDC Initial RAM LUT
///////////////
#if WGDC_RAMTUNING
ThreeDTable WGDCInitialRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->WGDCInitialRamCols),
	.rowHeaderArray = &(pRamVariables->WGDCInitialRamRows),
	.tableCells = &(pRamVariables->WGDCInitialRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0- range, 16bit precision)
#endif

///////////////////
//WGDC Max Table 1i LUT
///////////////////
ThreeDTable WGDCMaxTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData1i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols1i,
	.rowHeaderArray = WGDCMaxRows1i,
	.tableCells = WGDCMaxData1i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Max Table 2i LUT
///////////////////
ThreeDTable WGDCMaxTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData2i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols2i,
	.rowHeaderArray = WGDCMaxRows2i,
	.tableCells = WGDCMaxData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

#if SWITCH_HACKS
///////////////////
//WGDC Max Table 1s LUT
///////////////////
ThreeDTable WGDCMaxTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData1s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols1s,
	.rowHeaderArray = WGDCMaxRows1s,
	.tableCells = WGDCMaxData1s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Max Table 2s LUT
///////////////////
ThreeDTable WGDCMaxTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData2s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols2s,
	.rowHeaderArray = WGDCMaxRows2s,
	.tableCells = WGDCMaxData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Max Table 1ss LUT
///////////////////
ThreeDTable WGDCMaxTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData1ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols1ss,
	.rowHeaderArray = WGDCMaxRows1ss,
	.tableCells = WGDCMaxData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Max Table 2ss LUT
///////////////////
ThreeDTable WGDCMaxTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float WGDCMaxRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short WGDCMaxData2ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16311,	15729,	15729,	15947,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15609,	15609,	16273,	15886,	15498,	15720,	15720,	15941,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	15807,	15807,	16384,	16384,	16153,	16153,	16153,	16230,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	15616,	16128,	16128,	16128,	16213,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,	16384,
};

ThreeDTable WGDCMaxTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols2ss,
	.rowHeaderArray = WGDCMaxRows2ss,
	.tableCells = WGDCMaxData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
#endif

///////////////
//WGDC Max RAM LUT
///////////////
#if WGDC_RAMTUNING
ThreeDTable WGDCMaxRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->WGDCMaxRamCols),
	.rowHeaderArray = &(pRamVariables->WGDCMaxRamRows),
	.tableCells = &(pRamVariables->WGDCMaxRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0- range, 16bit precision)
#endif

///////////////////
//Target Boost Table 1i
///////////////////
ThreeDTable TargetBoostTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData1i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols1i,
	.rowHeaderArray = TBRows1i,
	.tableCells = TBData1i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//Target Boost Table 2i
///////////////////
ThreeDTable TargetBoostTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData2i[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols2i,
	.rowHeaderArray = TBRows2i,
	.tableCells = TBData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

#if SWITCH_HACKS
///////////////////
//Target Boost Table 1s
///////////////////
ThreeDTable TargetBoostTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData1s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols1s,
	.rowHeaderArray = TBRows1s,
	.tableCells = TBData1s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//Target Boost Table 2s
///////////////////
ThreeDTable TargetBoostTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData2s[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols2s,
	.rowHeaderArray = TBRows2s,
	.tableCells = TBData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)

///////////////////
//Target Boost Table 1ss
///////////////////
ThreeDTable TargetBoostTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData1ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols1ss,
	.rowHeaderArray = TBRows1ss,
	.tableCells = TBData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//Target Boost Table 2ss
///////////////////
ThreeDTable TargetBoostTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_COLS};
float TBRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{COMP_ROWS};
short TBData2ss[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{
	0,	0,	0,	0,	0,	814,	3449,	5964,	8479,	11210,	14084,	16384,	16384,	16384,	16384,	16384,
	0,	0,	0,	0,	0,	341,	2048,	3638,	5229,	7168,	9340,	11429,	13188,	14926,	16384,	16384,
	0,	0,	0,	0,	0,	101,	1464,	2800,	4136,	5798,	7678,	9612,	11767,	13957,	15962,	16384,
	0,	0,	0,	0,	0,	0,	1069,	2404,	3740,	5283,	6965,	8706,	10685,	12822,	15118,	16384,
	0,	0,	0,	0,	0,	189,	1464,	2833,	4202,	5738,	7387,	9111,	11134,	13192,	15329,	16384,
	0,	0,	0,	0,	0,	290,	1543,	2978,	4413,	5946,	7546,	9234,	11279,	13403,	15487,	16384,
	0,	0,	0,	0,	0,	185,	1306,	2839,	4373,	5907,	7440,	9076,	11121,	13455,	15593,	16384,
	0,	0,	0,	0,	0,	0,	1227,	2694,	4162,	5630,	7097,	8654,	10566,	12664,	14959,	16384,
	0,	0,	0,	0,	0,	0,	1029,	2480,	3931,	5382,	6833,	8372,	10263,	12295,	14775,	16384,
	0,	0,	0,	0,	0,	0,	712,	2196,	3680,	5165,	6649,	8232,	10210,	12347,	15038,	16384,
	0,	0,	0,	0,	0,	0,	1279,	2677,	4076,	5495,	6927,	8454,	10363,	12361,	14865,	16384,
	0,	0,	0,	0,	0,	421,	1856,	3235,	4614,	6033,	7479,	8995,	10788,	12698,	15308,	16384,
	0,	0,	0,	0,	0,	951,	2445,	3872,	5298,	6786,	8314,	9863,	11493,	13368,	16384,	16384,
	0,	0,	0,	0,	0,	1409,	2964,	4473,	5983,	7554,	9166,	10859,	12871,	15039,	16384,	16384,
	0,	0,	0,	0,	414,	1955,	3511,	5113,	6715,	8401,	10142,	11963,	14099,	16050,	16384,	16384,
	0,	0,	0,	0,	1097,	2603,	4096,	5803,	7509,	9344,	11264,	13198,	15189,	16384,	16384,	16384,
};

ThreeDTable TargetBoostTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols2ss,
	.rowHeaderArray = TBRows2ss,
	.tableCells = TBData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
#endif
	
#endif