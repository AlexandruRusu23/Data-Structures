#ifndef DETECT_PLATFORM_H
#define DETECT_PLATFORM_H

#include <string>

#if defined(_WIN32)
static const std::string PLATFORM_NAME = "windows";
#elif defined(_WIN64)
static const std::string PLATFORM_NAME = "windows";
#elif defined(__linux__)
static const std::string PLATFORM_NAME = "linux"; // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and others
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#include <sys/param.h>
#if defined(BSD)
static const std::string PLATFORM_NAME = "bsd"; // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
#endif
#elif defined(__APPLE__) && defined(__MACH__) // Apple
#include <TargetConditionals.h>
#if TARGET_OS_MAC == 1
static const std::string PLATFORM_NAME = "apple"; // Apple OSX
#endif
#else
static const std::string PLATFORM_NAME = nullptr;
#endif

namespace Platform
{
	std::string GetPlatformName() {
		return (PLATFORM_NAME.empty()) ? "" : PLATFORM_NAME;
	}
}

#endif

