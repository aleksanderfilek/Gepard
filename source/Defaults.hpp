#pragma once

#ifdef DEBUG
    #define PATH(Path) "bin/"#Path
#endif

#ifndef DEBUG
    #define PATH(Path) #Path
#endif