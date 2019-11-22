#include "Plugin.h"
#include "PluginLibrary.h"

namespace plugin
{
	PluginFunctions pluginFunctions;

	/**********************************************************************************************************
	*	Functions
	*/

	//Returns the current date to the calling papyrus script
	UInt32 currentDate(StaticFunctionTag* base)
	{
		return pluginFunctions.currentDate();
	}

	//Checks if the current save is old
	bool isOldSave(StaticFunctionTag* base, UInt32 creationDate)
	{
		return pluginFunctions.isOldSave(creationDate);
	}

	//Returns the workouts from the day of the week of the creation date to the end of the best week between the creation date of the calling save and now as a string (format is "W,H,S,M;W,H,S,M...")
	BSFixedString getWorkoutsFromBestWeek(StaticFunctionTag* base, UInt32 creationDate)
	{
		return pluginFunctions.getWorkoutsFromBestWeek(creationDate).c_str();
	}

	//Returns a string representation of the levels gained in the given week (format is "H,S,M;H,S,M...")
	BSFixedString getLevelUpsAsString(StaticFunctionTag* base, BSFixedString outstandingLevel, BSFixedString workoutsString)
	{
		return pluginFunctions.getLevelUpsAsString(outstandingLevel.content, workoutsString.content).c_str();
	}

	//Returns true if there is another level up and sets the health,stamina and magicka values
	bool isNthLevelUp(StaticFunctionTag* base, BSFixedString levelUpsString, UInt32 n)
	{
		return pluginFunctions.isNthLevelUp(levelUpsString.content,n);
	}

	//Returns the health, stamina or magicka component of the given level up
	UInt32 getLevelComponent(StaticFunctionTag* base, BSFixedString levelUpsString, UInt32 n, BSFixedString type)
	{
		return pluginFunctions.getLevelComponent(levelUpsString.content,n,type.content);
	}

	//Returns the outstanding level as a string
	BSFixedString getOutstandingLevel(StaticFunctionTag* base, BSFixedString levelUpsString)
	{
		return pluginFunctions.getOutstandingLevel(levelUpsString.content).c_str();
	}

	//Makes a service call to fetch workouts
	UInt32 startNormalFetch(StaticFunctionTag* base, BSFixedString gameID, BSFixedString username)
	{
		return pluginFunctions.startNormalFetch(gameID.content,username.content);
	}

	//Starts the poll for new workouts when the user requests a check
	UInt32 startForceFetch(StaticFunctionTag* base, BSFixedString gameID, BSFixedString username)
	{
		return pluginFunctions.startForceFetch(gameID.content,username.content);
	}

	//Returns workouts from Raw_Data.xml as a string (format is "W,H,S,M;W,H,S,M...")
	BSFixedString getWorkoutsString(StaticFunctionTag* base, UInt32 level)
	{
		return pluginFunctions.getWorkoutsString(level).c_str();
	}

	//Returns the number of workouts in the raw data file
	UInt32 getRawDataWorkoutCount(StaticFunctionTag* base)
	{
		return pluginFunctions.getRawDataWorkoutCount();
	}

	//Allows papyrus to clear the debug
	void clearDebug(StaticFunctionTag* base)
	{
		pluginFunctions.clearDebug();
	}

	//Checks if the given username is valid
	bool validUsername(StaticFunctionTag* base, BSFixedString gameID, BSFixedString username)
	{
		return pluginFunctions.validUsername(gameID.content,username.content);
	}

	//Returns a shortened username to fit in the menu screen
	BSFixedString getShortenedUsername(StaticFunctionTag* base, BSFixedString username)
	{
		return pluginFunctions.getShortenedUsername(username.content).c_str();
	}

	//Virtually presses the given key
	void pressKey(StaticFunctionTag* base, BSFixedString key)
	{

	}

	//Gets the number of exercise.com points needed to level up
	UInt32 getPointsToNextLevel(StaticFunctionTag* base, float outstandingWeight)
	{
		return pluginFunctions.getPointsToNextLevel(outstandingWeight);
	}

	//Updates the config file to match the config object
	void updateConfig(StaticFunctionTag* base)
	{
		pluginFunctions.updateConfig();
	}

	//Returns a%b
	UInt32 mod(StaticFunctionTag* base, UInt32 a, UInt32 b)
	{
		return pluginFunctions.mod(a, b);
	}

	//Returns a/b
	UInt32 division(StaticFunctionTag* base, UInt32 c, UInt32 d)
	{
		return pluginFunctions.division(c, d);
	}

	/**********************************************************************************************************
	*	Register
	*/

	//Registers functions for use in a papyrus script
	bool RegisterFuncs(VMClassRegistry* registry) {

		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, UInt32>("currentDate", "PluginScript", plugin::currentDate, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, bool, UInt32>("isOldSave", "PluginScript", plugin::isOldSave, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, BSFixedString, UInt32>("getWorkoutsFromBestWeek", "PluginScript", plugin::getWorkoutsFromBestWeek, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, BSFixedString, BSFixedString, BSFixedString>("getLevelUpsAsString", "PluginScript", plugin::getLevelUpsAsString, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, bool, BSFixedString, UInt32>("isNthLevelUp", "PluginScript", plugin::isNthLevelUp, registry));

		registry->RegisterFunction(
			new NativeFunction3 <StaticFunctionTag, UInt32, BSFixedString, UInt32, BSFixedString>("getLevelComponent", "PluginScript", plugin::getLevelComponent, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, BSFixedString, BSFixedString>("getOutstandingLevel", "PluginScript", plugin::getOutstandingLevel, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, BSFixedString, BSFixedString>("startNormalFetch", "PluginScript", plugin::startNormalFetch, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, BSFixedString, BSFixedString>("startForceFetch", "PluginScript", plugin::startForceFetch, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, BSFixedString, UInt32>("getWorkoutsString", "PluginScript", plugin::getWorkoutsString, registry));

		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, UInt32>("getRawDataWorkoutCount", "PluginScript", plugin::getRawDataWorkoutCount, registry));

		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, void>("clearDebug", "PluginScript", plugin::clearDebug, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, bool, BSFixedString, BSFixedString>("validUsername", "PluginScript", plugin::validUsername, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, BSFixedString, BSFixedString>("getShortenedUsername", "PluginScript", plugin::getShortenedUsername, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, void, BSFixedString>("pressKey", "PluginScript", plugin::pressKey, registry));

		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, UInt32, float>("getPointsToNextLevel", "PluginScript", plugin::getPointsToNextLevel, registry));

		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, void>("updateConfig", "PluginScript", plugin::updateConfig, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, UInt32, UInt32>("mod", "PluginScript", plugin::mod, registry));

		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, UInt32, UInt32>("division", "PluginScript", plugin::division, registry));

		return true;
	}
}