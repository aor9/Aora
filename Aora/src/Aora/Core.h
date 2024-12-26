#pragma once

#ifdef AO_PLATFORM_WINDOWS
	#ifdef AO_BUILD_DLL
		#define AORA_API __declspec(dllexport)
	#else
		#define AORA_API __declspec(dllimport)
	#endif
#else
	#error Aora only supports Windows!
#endif

#ifdef AO_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define AO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { AO##type##ERROR(msg, __VA_ARGS__); AO_DEBUGBREAK(); } }
#define AO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) AO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define AO_INTERNAL_ASSERT_NO_MSG(type, check) AO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", AO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define AO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define AO_INTERNAL_ASSERT_GET_MACRO(...) AO_EXPAND_MACRO( AO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, AO_INTERNAL_ASSERT_WITH_MSG, AO_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define AO_ASSERT(...) AO_EXPAND_MACRO( AO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define AO_CORE_ASSERT(...) AO_EXPAND_MACRO( AO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define AO_ASSERT(...)
#define AO_CORE_ASSERT(...)
#endif

#define BIT(x) (1 << x)