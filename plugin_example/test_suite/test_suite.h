#pragma once

#include "plugin_example\PluginLibrary.h"
#include "iostream"
#include "string"

typedef void(*TestCases)();

PluginFunctions pluginFunctions;

//Tests for currentDate(int)
void Test_currentDate_BetweenBeforeAndAfterAndLessThanOneMinuteApart();

//Tests for isOldSave(int)
void Test_isOldSave_ConfigIsInDefaultState_False();
void Test_isOldSave_ConfigIsCurrent_False();
void Test_isOldSave_LastConfigFailsToUpdate_False();
void Test_isOldSave_ConfigIsOldSave_True();
void Test_isOldSave_CheckIfIdempotentOnOldSave_UnchangedConfig();
void Test_isOldSave_CheckIfIdempotentOnCurrentSave_UnchangedConfig();
void Test_isOldSave_ConfigShouldNotUpdateOnOldSave_UnchangedConfig();
void Test_isOldSave_ConfigShouldNotUpdateOnCurrentSave_UnchangedConfig();
void Test_isOldSave_ConfigShouldUpdateIfOutOfDate_Unspecified();

//Tests for getWorkoutsFromBestWeek...

//Test for getLevelUpsAsString(string, string)
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForHealth_String();
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForStamina_String();
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForMagicka_String();
void Test_getLevelUpAsString_NoOutstandingExactlyTwoLevelForHealth_String();
void Test_getLevelUpAsString_NoOutstandingExactlyThreeLevelForStamina_String();
void Test_getLevelUpAsString_NoOutstandingExactlyFourLevelForMagicka_String();
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForHealthOverTwoWorkouts_String();
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForStaminaOverFourWorkouts_String();
void Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForMagickaOverFiveWorkouts_String();
void Test_getLevelUpAsString_NoOutstandingWithPartLevelForHealth_String();
void Test_getLevelUpAsString_NoOutstandingWithPartLevelForStamina_String();
void Test_getLevelUpAsString_NoOutstandingWithPartLevelForMagicka_String();
void Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForHealthOverTwoWorkouts_String();
void Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForStaminaOverTwoWorkouts_String();
void Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForMagickaOverTwoWorkouts_String();
void Test_getLevelUpAsString_OutstandingLevelsInAllAttributesOverTwoWorkouts_String();
void Test_getLevelUpAsString_AllAttributesTestRounding();

//Tests for isNthLevelUp(string, int)
void Test_isNthLevelUp_BlankString_False(); //undefined behaviour
void Test_isNthLevelUp_NoLevelsNEqualOne_False();
void Test_isNthLevelUp_OneLevelNEqualOne_True();
void Test_isNthLevelUp_OneLevelNEqualTwo_False();
void Test_isNthLevelUp_TwoLevelNEqualOne_True();
void Test_isNthLevelUp_TwoLevelNEqualTwo_True();
void Test_isNthLevelUp_TwoLevelNEqualThree_False();

//Tests for getLevelComponent
void Test_getLevelComponent_GetHealth1_10();
void Test_getLevelComponent_GetHealth2_5();
void Test_getLevelComponent_GetStamina1_0();
void Test_getLevelComponent_GetStamina2_2();
void Test_getLevelComponent_GetMagicka1_0();
void Test_getLevelComponent_GetMagicka2_3();

//Tests for getOutstandingLevel
void Test_getOutstandingLevel_noLevelUp_String();
void Test_getOutstandingLevel_oneLevelUp_String();
void Test_getOutstandingLevel_multipleLevelUps_String();

//Tests for normalFetch
void Test_startNormalFetch_ValidRawData();

//Tests for forceFetch
//doesn't work at the moment
void Test_startForceFetch_ValidRawData();

//Tests for getWorkoutsString
//void Test_getWorkoutsString_empty_emptyString();


//Tests for getRawDataWorkoutCount

//Tests for validUsername

//Tests for getShortenedUsername
void Test_getShortenedUsername_PaulRalph_unchanged();
void Test_getShortenedUsername_DrPaulRalph_unchanged();
void Test_getShortenedUsername_PaulRalph123_shortened();
void Test_getShortenedUsername_ReallyReallyLongString_shortened();
void Test_getShortenedUsername_PaulRalph0_unchanged(); //boundary case
void Test_getShortenedUsername_P_unchanged();

//Tests for getPointsToNextLevel
void Test_getPointsToNextLevel_EarlyInSecondWeek_3500();
void Test_getPointsToNextLevel_LateInSecondWeek_1712();
void Test_getPointsToNextLevel_Week5NoOutstandingLevel_5174();
void Test_getPointsToNextLevel_Week5AlmostLevel_1();

TestCases tests[] = {
	//case 1
	Test_currentDate_BetweenBeforeAndAfterAndLessThanOneMinuteApart,

	//case n+1
	Test_isOldSave_ConfigIsInDefaultState_False,
	Test_isOldSave_ConfigIsCurrent_False,
	Test_isOldSave_LastConfigFailsToUpdate_False,
	Test_isOldSave_ConfigIsOldSave_True,
	Test_isOldSave_CheckIfIdempotentOnOldSave_UnchangedConfig,
	Test_isOldSave_CheckIfIdempotentOnCurrentSave_UnchangedConfig,
	Test_isOldSave_ConfigShouldNotUpdateOnOldSave_UnchangedConfig,
	Test_isOldSave_ConfigShouldNotUpdateOnCurrentSave_UnchangedConfig,
	Test_isOldSave_ConfigShouldUpdateIfOutOfDate_Unspecified,

	//case n+9
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForHealth_String,
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForStamina_String,
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForMagicka_String,
	Test_getLevelUpAsString_NoOutstandingExactlyTwoLevelForHealth_String,
	Test_getLevelUpAsString_NoOutstandingExactlyThreeLevelForStamina_String,
	Test_getLevelUpAsString_NoOutstandingExactlyFourLevelForMagicka_String,
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForHealthOverTwoWorkouts_String,
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForStaminaOverFourWorkouts_String,
	Test_getLevelUpAsString_NoOutstandingExactlyOneLevelForMagickaOverFiveWorkouts_String,
	Test_getLevelUpAsString_NoOutstandingWithPartLevelForHealth_String,
	Test_getLevelUpAsString_NoOutstandingWithPartLevelForStamina_String,
	Test_getLevelUpAsString_NoOutstandingWithPartLevelForMagicka_String,
	Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForHealthOverTwoWorkouts_String,
	Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForStaminaOverTwoWorkouts_String,
	Test_getLevelUpAsString_OutstandingLevelsExactlyOneLevelForMagickaOverTwoWorkouts_String,
	Test_getLevelUpAsString_OutstandingLevelsInAllAttributesOverTwoWorkouts_String,
	Test_getLevelUpAsString_AllAttributesTestRounding,

	//case n+17
	Test_isNthLevelUp_BlankString_False,
	Test_isNthLevelUp_NoLevelsNEqualOne_False,
	Test_isNthLevelUp_OneLevelNEqualOne_True,
	Test_isNthLevelUp_OneLevelNEqualTwo_False,
	Test_isNthLevelUp_TwoLevelNEqualOne_True,
	Test_isNthLevelUp_TwoLevelNEqualTwo_True,
	Test_isNthLevelUp_TwoLevelNEqualThree_False,

	//case n+7
	Test_getLevelComponent_GetHealth1_10,
	Test_getLevelComponent_GetHealth2_5,
	Test_getLevelComponent_GetStamina1_0,
	Test_getLevelComponent_GetStamina2_2,
	Test_getLevelComponent_GetMagicka1_0,
	Test_getLevelComponent_GetMagicka2_3,

	//case n+3
	Test_getOutstandingLevel_noLevelUp_String,
	Test_getOutstandingLevel_oneLevelUp_String,
	Test_getOutstandingLevel_multipleLevelUps_String,

	Test_startNormalFetch_ValidRawData,
	Test_startForceFetch_ValidRawData,

	Test_getShortenedUsername_PaulRalph_unchanged,
	Test_getShortenedUsername_DrPaulRalph_unchanged,
	Test_getShortenedUsername_PaulRalph123_shortened,
	Test_getShortenedUsername_ReallyReallyLongString_shortened,
	Test_getShortenedUsername_PaulRalph0_unchanged,
	Test_getShortenedUsername_P_unchanged,

	//case n+6
	Test_getPointsToNextLevel_EarlyInSecondWeek_3500,
	Test_getPointsToNextLevel_LateInSecondWeek_1712,
	Test_getPointsToNextLevel_Week5NoOutstandingLevel_5174,
	Test_getPointsToNextLevel_Week5AlmostLevel_1
};

//helpers
std::string configProperties[] = {
	"startDate",
	"lastWorkoutDate",
	"lastSyncDate",
	"firstWorkoutDate",
	"workoutCount",
	"weeksWorkedOut",
	"avgPointsPerWorkout",
	"totalPoints",
	"workoutsThisWeek"
};
//please move this to the ConfigHandler and expose methods to delete the Config file and corrupt the config file.
void initialiseConfig() {
	for (std::string s : configProperties) {
		pluginFunctions.config.setConfigProperty(s, 0);
	}
}
