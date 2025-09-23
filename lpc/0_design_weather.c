

// rooms with weather-flag can access the system
// 

// user attempt to affect weather parameter|s with magnitude and range.


object weather_manager (global, internal logs, limits_resources(time&space) )
* global_weather_system
* set of weather_systems
* a safe default system fallback

data global_weather_system

data weather_system
* ruleset : definitions, limits, coefficients
* state : previous, current, next
* members : "position within system"
