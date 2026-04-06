#pragma once

#include <memory>

#ifdef C_DEBUG
#   define C_PROFILE
#   include <signal.h>
#   define C_API_ASSERT(x, ...) if (!(x)) { Cat::Log::GetAPILogger()->critical(__VA_ARGS__); raise(SIGTRAP); }
#   define C_ASSERT(x) if(!(x)) raise(SIGTRAP);
#else
#   define C_API_ASSERT(x, ...)
#   define C_ASSERT(x)
#endif

#define BIT(x) 1 << x

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Cat
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
