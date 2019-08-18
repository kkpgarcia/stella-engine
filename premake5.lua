workspace "KTEngine"
    architecture "x64"

    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KTEngine"
    location "KTEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KT_PLATFORM_WINDOWS",
            "KT_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines "KT_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "KT_RELEASE"
            optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"  
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "KTEngine/vendor/spdlog/include",
        "KTEngine/src"
    }

    links {
        "KTEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KT_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "KT_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "KT_RELEASE"
            optimize "On"