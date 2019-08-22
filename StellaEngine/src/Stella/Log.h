#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Stella {
	class STELLA_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

#define STELLA_CORE_TRACE(...) ::Stella::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STELLA_CORE_ERROR(...) ::Stella::Log::GetCoreLogger()->error(__VA_ARGS__)
#define STELLA_CORE_WARNING(...) ::Stella::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STELLA_CORE_LOG(...) ::Stella::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define STELLA_CORE_FATAL(...) ::Stella::Log::GetCoreLogger()->fatal(__VA_ARGS__)
		
#define STELLA_CLIENT_TRACE(...) ::Stella::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STELLA_CLIENT_ERROR(...) ::Stella::Log::GetClientLogger()->error(__VA_ARGS__)
#define STELLA_CLIENT_WARNING(...) ::Stella::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STELLA_CLIENT_LOG(...) ::Stella::Log::GetClientLogger()->debug(__VA_ARGS__)
#define STELLA_CLIENT_FATAL(...) ::Stella::Log::GetClientLogger()->fatal(__VA_ARGS__)