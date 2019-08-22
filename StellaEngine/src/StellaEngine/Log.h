#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace StellaEngine {
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

#define KT_CORE_TRACE(...) ::StellaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KT_CORE_ERROR(...) ::StellaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KT_CORE_WARNING(...) ::StellaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KT_CORE_LOG(...) ::StellaEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define KT_CORE_FATAL(...) ::StellaEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define KT_CLIENT_TRACE(...) ::StellaEngine::Log::GetClientLogger()->trace(__VA_ARGS__
#define KT_CLIENT_ERROR(...) ::StellaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KT_CLIENT_WARNING(...) ::StellaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KT_CLIENT_LOG(...) ::StellaEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define KT_CLIENT_FATAL(...) ::StellaEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)