// src/josim_shared.cpp

#include <msclr/marshal_cppstd.h>
#include "JOSIM/Wrapper.hpp"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace JoSIM {

public ref class JoSIMWrapper {
public:
    static int RunSimulation(array<String^>^ args) {
        int argc = args->Length;
        const char** argv = new const char*[argc];
        for (int i = 0; i < argc; ++i) {
            argv[i] = (const char*)(Marshal::StringToHGlobalAnsi(args[i])).ToPointer();
        }

        int result = JoSIM::RunSimulation(argc, argv);

        for (int i = 0; i < argc; ++i) {
            Marshal::FreeHGlobal(IntPtr((void*)argv[i]));
        }
        delete[] argv;

        return result;
    }
};

}
