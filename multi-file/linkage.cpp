
// accessible in any file (external linkage)
int g_myGlobal{ 100 };
// extern makes constants have external linkage
extern const int g_myGlobalConst{ 101 };
// Best Practice: if you make a global variable ALWAYS make it a constant


// internal linkage variables can have the same name in multiple files b/c the variable is only available to the file it exists in
// internal linkage b/c of the static keyword
static int g_onlyThisFileStatic{ 200 };

// constants have internal linkage
const int g_onlyThisFileConst{ 300 };
// constexpr int g_onlyThisFileConstExpr{ 500 };



