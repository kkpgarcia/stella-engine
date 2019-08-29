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

#define STELLA_CORE_TRACE(...) ::StellaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STELLA_CORE_ERROR(...) ::StellaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define STELLA_CORE_WARNING(...) ::StellaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STELLA_CORE_INFO(...) ::StellaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define STELLA_CORE_CRITICAL(...) ::StellaEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
		
#define STELLA_TRACE(...) ::StellaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STELLA_ERROR(...) ::StellaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define STELLA_WARNING(...) ::StellaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STELLA_INFO(...) ::StellaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define STELLA_CRITICAL(...) ::StellaEngine::Log::GetClientLogger()->critical(__VA_ARGS__)