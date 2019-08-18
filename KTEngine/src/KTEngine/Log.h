#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace KTEngine {
	class KT_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

#define KT_CORE_ERROR(...) ::KTEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KT_CORE_WARNING(...) ::KTEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KT_CORE_LOG(...) ::KTEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define KT_CORE_FATAL(...) ::KTEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define KT_CLIENT_ERROR(...) ::KTEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KT_CLIENT_WARNING(...) ::KTEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KT_CLIENT_LOG(...) ::KTEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define KT_CLIENT_FATAL(...) ::KTEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)