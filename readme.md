# Console Helper
### Usage
To use the library, make a global instance of `Console::ConsoleController`. This object will handle everything related with the console. It is possible to use multiple objects for this, since the class itself holds no data, but it is not recommended, as this will change in the future.

The library supports both the standard 16-DOS colours which you may be used to if you have used the C# console colours, and it also supports full 24-bit RGB. Two colour objects exist. One is `Console::Color` which is a simple enum, and the other is the `RGBColor` struct which has three bytes for each colour channel.

There are 3 different ways to set the console colour. The first and easiest way will only apply to the foreground colour.
Simply use the `<<` operator on your console instance and pass in either of the colour objects.
```cpp
using namespace Console;
ConsoleController console;
console << Color::RED << "This text is in red\n";
console << RGBColor(0, 0, 255) << "This text is in blue";
```

The next way is to use the `Console::CInfo` struct. This struct takes either of the colours, and a boolean stating whether to apply the colour to the foreground or background. Like the last method, use the `<<` operator.
```cpp
using namespace Console;
ConsoleController console;
console << CInfo(Color::RED) << "This text is in red\n";
console << CInfo(RGBColor(0, 0, 255), true) << "Now the background is blue";
```

Finally, you can use the `SetForeColor` and `SetBackColor` methods in the `Console::ConsoleController` class.
```cpp
ConsoleController console;
console.SetForeColor(Color::RED);
console << "This text is in red\n";
console.SetForeColor(Color::BLUE);
console << "This text is in blue";
```

#### Final Notes
First of all, it is not essential to use the `<<` operator to print text. Internally, that operator reroutes the text to `std::cout`. You can mix `std::cout`, `printf` and `ConsoleController::<<` if you'd like.
I haven't tested it, but since the `ConsoleController::<<` operator uses `std::cout <<`, custom `<<` overloads should work with the console class.

Since this library uses ANSI codes, it will break and print some garbage if you try to print any colour codes into a file. So don't do that.

Finally, both British and American spellings of `colour` is supported. The main objects and functions themselves use the American spelling but aliases exist to allow the British spelling.

## Building
This library uses CMake it is simple enough to build and link. Most IDE's will support it nativly, so just open it and build.
If you are using Visual Studio on Windows, you have two options. You can open it as a folder and build through the CMake project, or you can open the developer console and enter `cmake <PATH-TO-SRC>`. This will generate a `.sln` you can use.
Additionally, if you are on Windows, you can download the pre-built binaries.

To link with CMake, make sure you use `add_subdirectory` to build the project. Make sure that you set up the include folder, and then use `target_link_libraries(<YOUR-PROJ> ConsoleHelper)`
