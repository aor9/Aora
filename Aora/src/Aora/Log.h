#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Aora {

	class AORA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AO_CORE_TRACE(...)    ::Aora::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AO_CORE_INFO(...)     ::Aora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AO_CORE_WARN(...)     ::Aora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AO_CORE_ERROR(...)    ::Aora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AO_CORE_FATAL(...)    ::Aora::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AO_TRACE(...)	      ::Aora::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AO_INFO(...)	      ::Aora::Log::GetClientLogger()->info(__VA_ARGS__)
#define AO_WARN(...)	      ::Aora::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AO_ERROR(...)	      ::Aora::Log::GetClientLogger()->error(__VA_ARGS__)
#define AO_FATAL(...)	      ::Aora::Log::GetClientLogger()->fatal(__VA_ARGS__)