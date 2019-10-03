workspace "Brainfuck-Interpreter"
  architecture "x64"

  configurations {
    "Debug",
    "Release"
  }

  project "BGi"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("bin-int/%{cfg.buildcfg}")

    files {
      "src/**.h",
      "src/**.hpp",
      "src/**.cpp",
      "src/**.c"
    }

    includedirs {
        "src"
    }

    filter "configurations:Debug"
      defines "HZ_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "HZ_RELEASE"
      optimize "On"
